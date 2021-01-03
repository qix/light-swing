#include <math.h>
#include "rgb.h"

uint8_t *ledBuffer;
int r_mult = 255;
int g_mult = 255;
int b_mult = 255;

uint8_t blend(float amount, int a, int b)
{
    float af = a / 255.0;
    float bf = b / 255.0;
    return (uint8_t)(255 * sqrt((1 - amount) * af * af + amount * bf * bf));
}

void rgb(int pixel, uint8_t r, uint8_t g, uint8_t b, int mode)
{
    int position = (ROPE_OFFSET + pixel) * 3;
    if (mode == COLOR_SET)
    {
        ledBuffer[position + 1] = r;
        ledBuffer[position + 0] = g;
        ledBuffer[position + 2] = b;
        return;
    }

    uint8_t oR = ledBuffer[position + 1];
    uint8_t oG = ledBuffer[position + 0];
    uint8_t oB = ledBuffer[position + 2];

    if (mode == COLOR_ADD)
    {
        int maxPrev = max(oR, max(oG, oB));
        uint8_t maxNow = max(r, max(g, b));

        if (maxNow + maxPrev > 255)
        {
            float scale = ((255.0 - maxNow) / 255);
            oR = (uint8_t)(oR * scale);
            oG = (uint8_t)(oG * scale);
            oB = (uint8_t)(oB * scale);
        }
        r = (uint8_t)(r + oR);
        g = (uint8_t)(g + oG);
        b = (uint8_t)(b + oB);
    }
    else if (mode == COLOR_BLEND)
    {
        r = blend(0.5, oR, r);
        g = blend(0.5, oG, g);
        b = blend(0.5, oB, b);
    }

    ledBuffer[position + 1] = r;
    ledBuffer[position + 0] = g;
    ledBuffer[position + 2] = b;
}

bool isRGB(int pixel, uint8_t r, uint8_t g, uint8_t b)
{
    int position = (ROPE_OFFSET + pixel) * 3;
    return (
        ledBuffer[position + 1] == r &&
        ledBuffer[position + 0] == g &&
        ledBuffer[position + 2] == b);
}

void hsv(int pixel, int hue, uint8_t sat, uint8_t val, int mode)
{
    val = gamma8[(uint8_t)val];
    sat = 255 - gamma8[255 - (uint8_t)sat];

    int base;

    if (sat == 0)
    {
        rgb(pixel, val, val, val, mode);
    }
    else
    {
        base = (int)(((255 - sat) * val) >> 8);

        switch ((int)(hue / 60))
        {
        case 0:
            return rgb(pixel, val, (((val - base) * hue) / 60) + base, base, mode);
        case 1:
            return rgb(pixel, (((val - base) * (60 - (hue % 60))) / 60) + base, val, base, mode);
        case 2:
            return rgb(pixel, base, val, (((val - base) * (hue % 60)) / 60) + base, mode);
        case 3:
            return rgb(pixel, base, (((val - base) * (60 - (hue % 60))) / 60) + base, val, mode);
        case 4:
            return rgb(pixel, (((val - base) * (hue % 60)) / 60) + base, base, val, mode);
        case 5:
            return rgb(pixel, val, base, (((val - base) * (60 - (hue % 60))) / 60) + base, mode);
        }
    }
}

void rope_fade(int amount)
{
    for (int k = 0; k < ROPE_LEDS * 3; k++)
    {
        ledBuffer[k] = ledBuffer[k] > amount ? ledBuffer[k] - amount : 0;
    }
}

void rope_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    for (int k = 0; k < ROPE_LEDS; k++)
    {
        rgb(k, r, g, b);
    }
}

void rope_hsv(int hue, uint8_t sat, uint8_t val)
{
    for (int k = 0; k < ROPE_LEDS; k++)
    {
        hsv(k, hue, sat, val);
    }
}

void mult_rgb(int r, int g, int b)
{
    r_mult = r;
    g_mult = g;
    b_mult = b;
}

void colorSetRGB(Color *color, uint8_t r, uint8_t g, uint8_t b, int mode)
{
    color->r = r;
    color->g = g;
    color->b = b;
}
void colorSetHSV(Color *color, int hue, uint8_t sat, uint8_t val, int mode)
{
    val = gamma8[(uint8_t)val];
    sat = 255 - gamma8[255 - (uint8_t)sat];

    int base;

    if (sat == 0)
    {
        colorSetRGB(color, val, val, val, mode);
    }
    else
    {
        base = (int)(((255 - sat) * val) >> 8);

        switch ((int)(hue / 60))
        {
        case 0:
            return colorSetRGB(color, val, (((val - base) * hue) / 60) + base, base, mode);
        case 1:
            return colorSetRGB(color, (((val - base) * (60 - (hue % 60))) / 60) + base, val, base, mode);
        case 2:
            return colorSetRGB(color, base, val, (((val - base) * (hue % 60)) / 60) + base, mode);
        case 3:
            return colorSetRGB(color, base, (((val - base) * (60 - (hue % 60))) / 60) + base, val, mode);
        case 4:
            return colorSetRGB(color, (((val - base) * (hue % 60)) / 60) + base, base, val, mode);
        case 5:
            return colorSetRGB(color, val, base, (((val - base) * (60 - (hue % 60))) / 60) + base, mode);
        }
    }
}

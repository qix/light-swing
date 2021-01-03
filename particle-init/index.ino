









































































































































































































































































































































































































































#include "main.h"

unsigned long lastTime = 0;
int prevState = 0;
int state = 0;
int frameMs = 0;
int fadeSpeed = 10;

enum ANIMATION
{
    OFF = 0,
    FADE = 1,
    SCHEDULED = 2,
    BLOCK = 3,
    BLOCK_RAINBOW = 4,
    TWENTYTWENTY = 5,
    FIREWORKS = 6
};

ANIMATION animation = OFF;
ANIMATION nextAnimation = OFF;

void showRing(int ring)
{
    for (int k = ringStart[ring]; k < ringStart[ring] + ringSize[ring]; k++)
    {
        int index = ringIndexOffset + ringIndex[k];
        int colorIndex = ring + index + ((int)(state / 150));
        int color = 16 * (colorIndex % 16);
        rgb(
            index,
            ring % 2 == 0 ? color : 0,
            ring % 2 == 1 ? color : 0,
            ring % 3 == 0 ? color : 0);
    }
}
int ringX(int index)
{
    return (int)(ringIndex[index] / 16);
}
int ringY(int index)
{
    int rI = ringIndex[index];
    if (ringX(index) % 2 == 0)
    {
        return rI % 16;
    }
    else
    {
        return 15 - rI % 16;
    }
}
void ringHSV(int ring, int h, int s, int v)
{
    for (int k = ringStart[ring]; k < ringStart[ring] + ringSize[ring]; k++)
    {
        int index = ringIndexOffset + ringIndex[k];
        hsv(index, (h + k) % 360, s, v);
    }
}

void squareRGB(int x, int y, int r, int g, int b)
{
    if (x < 0 || x > 15 || y < 0 || y > 15)
    {
        return;
    }
    else if (x % 2 == 0)
    {
        rgb(ringIndexOffset + x * 16 + y, r, g, b);
    }
    else
    {
        rgb(ringIndexOffset + x * 16 + 15 - y, r, g, b);
    }
}

bool squareIsRGB(int x, int y, int r, int g, int b)
{
    if (x < 0 || x > 15 || y < 0 || y > 15)
    {
        return false;
    }
    else if (x % 2 == 0)
    {
        return isRGB(ringIndexOffset + x * 16 + y, r, g, b);
    }
    else
    {
        return isRGB(ringIndexOffset + x * 16 + 15 - y, r, g, b);
    }
}

uint8_t colorMap[768];
int skipColor = ' ' * 3;
void squareImage(const Image *img, int offsetX, int offsetY)
{
    for (int c = 0; c < img->num_colors * 4; c++)
    {
        int offset = img->color[c] * 3;
        colorMap[offset + 0] = img->color[c + 1];
        colorMap[offset + 1] = img->color[c + 2];
        colorMap[offset + 2] = img->color[c + 3];
    }
    int pixel = 0;
    for (int y = 0; y < img->h; y++)
    {
        int rY = y + offsetY;
        for (int x = 0; x < img->w; x++)
        {
            int rX = x + offsetX;
            int color = (uint8_t)(img->pixels[pixel++]) * 3;
            if (color != skipColor)
            {
                squareRGB(rX, rY, colorMap[color], colorMap[color + 1], colorMap[color + 2]);
            }
        }
    }
}
void clearImage(const Image *img, int offsetX, int offsetY)
{
    int pixel = 0;
    for (int y = 0; y < img->h; y++)
    {
        int rY = y + offsetY;
        for (int x = 0; x < img->w; x++)
        {
            int rX = x + offsetX;
            int color = (uint8_t)(img->pixels[pixel++]) * 3;
            if (color != skipColor)
            {
                squareRGB(rX, rY, 0, 0, 0);
            }
        }
    }
}

enum ParticleState
{
    DEAD = 0,
    ALIVE = 1,
};
struct Particle_
{
    float x;
    float y;
    float vx;
    float vy;
    float r;
    float g;
    float b;
    int state = DEAD;
    int step;
    int next;
};

const int maxParticles = 256;
Particle_ particles[maxParticles];
Particle_ unboundParticle;
int particleCount = 0;

Particle_ *nextParticle()
{
    if (particleCount == maxParticles)
    {
        for (int k = 0; k < particleCount; k++)
        {
            if (particles[k].state == DEAD)
            {
                return &particles[k];
            }
        }
        return &unboundParticle;
    }
    else
    {
        return &particles[particleCount++];
    }
}
void charParticles(char c, int oX, int oY)
{
    GFXglyph *glyph = &font.glyph[c - ' '];

    int offset = glyph->bitmapOffset;
    int bit = 0;
    int bits;
    for (int cY = 0; cY < glyph->height; cY++)
    {
        for (int cX = 0; cX < glyph->width; cX++)
        {
            if (((bit++) & 7) == 0)
            {
                bits = font.bitmap[offset++];
            }
            if (bits & 0x80)
            {
                Particle_ *p = nextParticle();
                p->x = oX + cX;
                p->y = oY + cY;
                p->step = random(10);
                p->state = ALIVE;
                p->r = 255;
                p->g = 0;
                p->b = 0;
                p->next = state + 2500 + 250 * random(50);
            }
            bits = (bits << 1) & 0xFF;
        }
    }
}

void charRGB(char c, int oX, int oY, int r, int g, int b)
{
    GFXglyph *glyph = &font.glyph[c - ' '];

    int offset = glyph->bitmapOffset;
    int bit = 0;
    int bits;
    for (int cY = 0; cY < glyph->height; cY++)
    {
        for (int cX = 0; cX < glyph->width; cX++)
        {
            if (((bit++) & 7) == 0)
            {
                bits = font.bitmap[offset++];
            }
            if (bits & 0x80)
            {
                squareRGB(oX + cX, oY + cY, r, g, b);
            }
            bits = (bits << 1) & 0xFF;
        }
    }
}

void renderParticles()
{
    for (int k = 0; k < particleCount; k++)
    {
        Particle_ *p = &particles[k];
        if (p->state == DEAD)
        {
            continue;
        }
        if (p->y < 16)
        {
            squareRGB((int)p->x, (int)p->y, (int)p->r, (int)p->g, (int)p->b);
        }
        else
        {
            int offset = ringIndexOffset - ((int)p->y - 15);
            if (offset >= 0)
            {
                rgb(offset, (int)p->r, (int)p->g, (int)p->b);
            }
        }
    }
}

/** Removes any particles that are not their expected color */
void killOverwrittenParticles()
{
    for (int k = 0; k < particleCount; k++)
    {
        Particle_ *p = &particles[k];
        if (p->state == DEAD)
        {
            continue;
        }
        if (p->y < 16)
        {
            if (!squareIsRGB((int)p->x, (int)p->y, 255, 0, 0))
            {
                p->state = DEAD;
            }
        }
        else
        {
            int offset = ringIndexOffset - ((int)p->y - 15);
            if (offset >= 0)
            {
                if (!isRGB(offset, 255, 0, 0))
                {
                    p->state = DEAD;
                }
            }
        }
    }
}

void animate2020()
{
    if (prevState == 0)
    {
        particleCount = 0;
        charParticles('2', 0, 0);
        charParticles('0', 6, 0);
        charParticles('2', 3, 7);
        charParticles('0', 9, 7);
    }
    for (int k = 0; k < particleCount; k++)
    {
        Particle_ *p = &particles[k];
        if (state > p->next)
        {
            if (p->y == 15)
            {
                if (p->x < 7)
                {
                    p->x++;
                }
                else if (p->x > 8)
                {
                    p->x--;
                }
                else
                {
                    p->y++;
                }
            }
            else
            {
                p->y += 1;
            }
            p->step += 1;
            p->next = state + random(max(20, 200 - p->step * 5));

            for (int j = 0; j < particleCount; j++)
            {
                if (j != k && particles[j].x == p->x && particles[j].y == p->y)
                {
                    particles[j].state = DEAD;
                }
            }
        }
    }

    rope_fade(5);
    renderParticles();

    const Image *images[] = {&pac_a, &pac_b, &pac_c};

    int pacX = (int)(-90 + state / 100);

    if (pacX > 2)
    {
        uint8_t bright = random(64, 256);
        charRGB('+', 5, 6, bright, bright, bright);
        if (pacX > 4)
        {
            charRGB('1', 9, 5, bright, bright, bright);
        }

        if (pacX > 20)
        {
            particleCount = 0;
            charParticles('+', 5, 6);
            charParticles('1', 9, 5);

            while (particleCount < 100)
            {
                Particle_ *p = nextParticle();
                p->x = 7;
                p->y = 7;
                p->state = ALIVE;
            }
            for (int k = 0; k < particleCount; k++)
            {
                particles[k].r = 255;
                particles[k].g = 255;
                particles[k].b = 255;
                particles[k].vx = -10 + random(2000) / 100.0;
                particles[k].vy = -15 + random(2000) / 100.0;
            }
            animation = FIREWORKS;
            state = 1;
            return;
        }
    }
    clearImage(images[(int)(prevState / 250) % 3], (int)(-90 + prevState / 100), 0);
    squareImage(images[(int)(state / 250) % 3], pacX, 0);

    killOverwrittenParticles();
}
void showNextAnimation()
{
    animation = nextAnimation;
    nextAnimation = FADE;
    state = -1;
}

void animateFireworkFade()
{
    int newWorks = 30 * ((int)(state / 1500) - (int)(prevState / 1500));
    if (state == 0)
    {
        newWorks = 20;
    }
    if (state < 4000)
    {
        Color c;
        for (int k = 0; k < newWorks; k++)
        {
            colorSetHSV(&c, random(360), 255, 255);
            Particle_ *p = nextParticle();
            p->x = 7;
            p->y = 7;
            p->state = ALIVE;
            p->r = c.r;
            p->g = c.g;
            p->b = c.b;
            p->vx = -20 + random(4000) / 100.0;
            p->vy = -25 + random(3000) / 100.0;
        }
    }
    renderParticles();
    rope_fade(10);
    int seen = 0;
    for (int k = 0; k < particleCount; k++)
    {
        Particle_ *p = &particles[k];
        if (frameMs > random(1000))
        {
            p->state = DEAD;
        }
        if (p->state == DEAD)
        {
            continue;
        }
        seen++;
        p->x += p->vx * 0.001 * frameMs;
        p->y += p->vy * 0.001 * frameMs;
        p->vy += 0.001 * frameMs;
        if (p->x > 15.99)
        {
            p->x = 15.99;
            p->vx = -fabs(p->vx);
        }
        else if (p->x < 0)
        {
            p->x = 0;
            p->vx = fabs(p->vx);
        }
        if (p->y > 15.99)
        {
            p->y = 15.99;
            p->vy = -fabs(p->vy) * 0.6;
            p->vx *= 0.6;
        }
        else if (p->y < 0)
        {
            p->y = 0;
            p->vy = fabs(p->vy);
        }
    }
    if (seen == 0)
    {
        showNextAnimation();
    }
}

void animateBlock()
{
    rope_fade(fadeSpeed);
    mult_rgb(96, 96, 96);
    int ring = (int)(state / 1000);
    if (ring >= ringCount)
    {
        animation = BLOCK_RAINBOW;
        state = 0;
    }
    else
    {
        showRing(ringCount - ring - 1);
    }
}

void animateBlockRainbow()
{
    rope_fade(1);
    mult_rgb(96, 96, 96);
    int step = ((int)(state / 50));
    // ~160 steps of animation
    if (step < ringIndexOffset)
    {
        hsv(step, (step * 15) % 360, 255, 96);
    }
    else
    {
        step -= ringIndexOffset;
        for (int k = 0; k < ringCount; k++)
        {
            int v = -20 * (ringCount - k - 1) + 5 * step;
            if (v > 0)
            {
                ringHSV(k, (k * 30 + ((int)(state / 10))) % 360, 255, min(v, 96));
            }
        }
    }
    if (step > 160)
    {
        animation = FADE;
    }
}

void animateScheduled()
{
    rope_fade(fadeSpeed);
    mult_rgb(96, 96, 96);
    showRing(ringCount - 1);
    if (nextAnimation == BLOCK)
    {
        showNextAnimation();
    }
    else if (nextAnimation != FADE)
    {
        showNextAnimation();
        nextAnimation = SCHEDULED;
    }
}

void animateFade()
{
    if (state == 0)
    {
        fadeSpeed = 1;
    }
    if (nextAnimation != FADE)
    {
        showNextAnimation();
        return;
    }
    rope_fade(fadeSpeed);
}

void loop()
{
    // Safe with rollover
    prevState = state;
    unsigned long now = millis();
    frameMs = (now - lastTime);
    state += frameMs;
    lastTime = now;

    if (prevState < 0)
    {
        prevState = 0;
        state = 0;
    }

    if (animation == OFF)
    {
        strip.clear();
        strip.show();
        particleCount = 0;
        return;
    }

    if (animation == TWENTYTWENTY)
    {
        animate2020();
    }
    else if (animation == FIREWORKS)
    {
        animateFireworkFade();
    }
    else if (animation == BLOCK)
    {
        animateBlock();
    }
    else if (animation == BLOCK_RAINBOW)
    {
        animateBlockRainbow();
    }
    else if (animation == SCHEDULED)
    {
        animateScheduled();
    }
    else if (animation == FADE)
    {
        animateFade();
    }
    strip.show();
}

void queueAnimation(ANIMATION next)
{
    if (animation == OFF)
    {
        animation = next;
        state = -1;
    }
    else
    {
        nextAnimation = next;
    }
}
void eth2Event(const char *event, const char *data)
{
    if (strcmp(event, "eth2/attest") == 0)
    {
        if (animation == FADE)
        {
            hsv(random(ROPE_LEDS), random(360), 255, 128);
        }
    }
    else if (strcmp(event, "eth2/block") == 0)
    {
        queueAnimation(BLOCK);
    }
    else if (strcmp(event, "eth2/scheduled") == 0)
    {

        queueAnimation(SCHEDULED);
    }
}
void show(const char *event, const char *data)
{
    if (strcmp(event, "show/2020") == 0)
    {
        queueAnimation(TWENTYTWENTY);
    }
    else if (strcmp(event, "show/off") == 0)
    {
        animation = OFF;
        nextAnimation = OFF;
    }
    else if (strcmp(event, "show/fireworks") == 0)
    {
        queueAnimation(FIREWORKS);
    }
}

void setup()
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    ledBuffer = strip.getPixels();
    Particle.subscribe("eth2/", eth2Event);
    Particle.subscribe("show/", show);
    animation = FADE;
    nextAnimation = FADE;
    lastTime = millis();
    state = -1;
}
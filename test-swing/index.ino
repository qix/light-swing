#define ROPE_OFFSET 0

struct GFXglyph
{
    uint16_t bitmapOffset; ///< Pointer into GFXfont->bitmap
    uint8_t width;         ///< Bitmap dimensions in pixels
    uint8_t height;        ///< Bitmap dimensions in pixels
    uint8_t xAdvance;      ///< Distance to advance cursor (x axis)
    int8_t xOffset;        ///< X dist from cursor pos to UL corner
    int8_t yOffset;        ///< Y dist from cursor pos to UL corner
};

/// Data stored for FONT AS A WHOLE
struct GFXfont
{
    uint8_t *bitmap;  ///< Glyph bitmaps, concatenated
    GFXglyph *glyph;  ///< Glyph array
    uint16_t first;   ///< ASCII extents (first char)
    uint16_t last;    ///< ASCII extents (last char)
    uint8_t yAdvance; ///< Newline distance (y axis)
};

const uint8_t Org_01Bitmaps[] PROGMEM = {
    0xE8, 0xA0, 0x57, 0xD5, 0xF5, 0x00, 0xFD, 0x3E, 0x5F, 0x80, 0x88, 0x88,
    0x88, 0x80, 0xF4, 0xBF, 0x2E, 0x80, 0x80, 0x6A, 0x40, 0x95, 0x80, 0xAA,
    0x80, 0x5D, 0x00, 0xC0, 0xF0, 0x80, 0x08, 0x88, 0x88, 0x00, 0xFC, 0x63,
    0x1F, 0x80, 0xF8, 0xF8, 0x7F, 0x0F, 0x80, 0xF8, 0x7E, 0x1F, 0x80, 0x8C,
    0x7E, 0x10, 0x80, 0xFC, 0x3E, 0x1F, 0x80, 0xFC, 0x3F, 0x1F, 0x80, 0xF8,
    0x42, 0x10, 0x80, 0xFC, 0x7F, 0x1F, 0x80, 0xFC, 0x7E, 0x1F, 0x80, 0x90,
    0xB0, 0x2A, 0x22, 0xF0, 0xF0, 0x88, 0xA8, 0xF8, 0x4E, 0x02, 0x00, 0xFD,
    0x6F, 0x0F, 0x80, 0xFC, 0x7F, 0x18, 0x80, 0xF4, 0x7D, 0x1F, 0x00, 0xFC,
    0x21, 0x0F, 0x80, 0xF4, 0x63, 0x1F, 0x00, 0xFC, 0x3F, 0x0F, 0x80, 0xFC,
    0x3F, 0x08, 0x00, 0xFC, 0x2F, 0x1F, 0x80, 0x8C, 0x7F, 0x18, 0x80, 0xF9,
    0x08, 0x4F, 0x80, 0x78, 0x85, 0x2F, 0x80, 0x8D, 0xB1, 0x68, 0x80, 0x84,
    0x21, 0x0F, 0x80, 0xFD, 0x6B, 0x5A, 0x80, 0xFC, 0x63, 0x18, 0x80, 0xFC,
    0x63, 0x1F, 0x80, 0xFC, 0x7F, 0x08, 0x00, 0xFC, 0x63, 0x3F, 0x80, 0xFC,
    0x7F, 0x29, 0x00, 0xFC, 0x3E, 0x1F, 0x80, 0xF9, 0x08, 0x42, 0x00, 0x8C,
    0x63, 0x1F, 0x80, 0x8C, 0x62, 0xA2, 0x00, 0xAD, 0x6B, 0x5F, 0x80, 0x8A,
    0x88, 0xA8, 0x80, 0x8C, 0x54, 0x42, 0x00, 0xF8, 0x7F, 0x0F, 0x80, 0xEA,
    0xC0, 0x82, 0x08, 0x20, 0x80, 0xD5, 0xC0, 0x54, 0xF8, 0x80, 0xF1, 0xFF,
    0x8F, 0x99, 0xF0, 0xF8, 0x8F, 0x1F, 0x99, 0xF0, 0xFF, 0x8F, 0x6B, 0xA4,
    0xF9, 0x9F, 0x10, 0x8F, 0x99, 0x90, 0xF0, 0x55, 0xC0, 0x8A, 0xF9, 0x90,
    0xF8, 0xFD, 0x63, 0x10, 0xF9, 0x99, 0xF9, 0x9F, 0xF9, 0x9F, 0x80, 0xF9,
    0x9F, 0x20, 0xF8, 0x88, 0x47, 0x1F, 0x27, 0xC8, 0x42, 0x00, 0x99, 0x9F,
    0x99, 0x97, 0x8C, 0x6B, 0xF0, 0x96, 0x69, 0x99, 0x9F, 0x10, 0x2E, 0x8F,
    0x2B, 0x22, 0xF8, 0x89, 0xA8, 0x0F, 0xE0};

const GFXglyph Org_01Glyphs[] PROGMEM = {{0, 0, 0, 6, 0, 1},     // 0x20 ' '
                                         {0, 1, 5, 2, 0, -4},    // 0x21 '!'
                                         {1, 3, 1, 4, 0, -4},    // 0x22 '"'
                                         {2, 5, 5, 6, 0, -4},    // 0x23 '#'
                                         {6, 5, 5, 6, 0, -4},    // 0x24 '$'
                                         {10, 5, 5, 6, 0, -4},   // 0x25 '%'
                                         {14, 5, 5, 6, 0, -4},   // 0x26 '&'
                                         {18, 1, 1, 2, 0, -4},   // 0x27 '''
                                         {19, 2, 5, 3, 0, -4},   // 0x28 '('
                                         {21, 2, 5, 3, 0, -4},   // 0x29 ')'
                                         {23, 3, 3, 4, 0, -3},   // 0x2A '*'
                                         {25, 3, 3, 4, 0, -3},   // 0x2B '+'
                                         {27, 1, 2, 2, 0, 0},    // 0x2C ','
                                         {28, 4, 1, 5, 0, -2},   // 0x2D '-'
                                         {29, 1, 1, 2, 0, 0},    // 0x2E '.'
                                         {30, 5, 5, 6, 0, -4},   // 0x2F '/'
                                         {34, 5, 5, 6, 0, -4},   // 0x30 '0'
                                         {38, 1, 5, 2, 0, -4},   // 0x31 '1'
                                         {39, 5, 5, 6, 0, -4},   // 0x32 '2'
                                         {43, 5, 5, 6, 0, -4},   // 0x33 '3'
                                         {47, 5, 5, 6, 0, -4},   // 0x34 '4'
                                         {51, 5, 5, 6, 0, -4},   // 0x35 '5'
                                         {55, 5, 5, 6, 0, -4},   // 0x36 '6'
                                         {59, 5, 5, 6, 0, -4},   // 0x37 '7'
                                         {63, 5, 5, 6, 0, -4},   // 0x38 '8'
                                         {67, 5, 5, 6, 0, -4},   // 0x39 '9'
                                         {71, 1, 4, 2, 0, -3},   // 0x3A ':'
                                         {72, 1, 4, 2, 0, -3},   // 0x3B ';'
                                         {73, 3, 5, 4, 0, -4},   // 0x3C '<'
                                         {75, 4, 3, 5, 0, -3},   // 0x3D '='
                                         {77, 3, 5, 4, 0, -4},   // 0x3E '>'
                                         {79, 5, 5, 6, 0, -4},   // 0x3F '?'
                                         {83, 5, 5, 6, 0, -4},   // 0x40 '@'
                                         {87, 5, 5, 6, 0, -4},   // 0x41 'A'
                                         {91, 5, 5, 6, 0, -4},   // 0x42 'B'
                                         {95, 5, 5, 6, 0, -4},   // 0x43 'C'
                                         {99, 5, 5, 6, 0, -4},   // 0x44 'D'
                                         {103, 5, 5, 6, 0, -4},  // 0x45 'E'
                                         {107, 5, 5, 6, 0, -4},  // 0x46 'F'
                                         {111, 5, 5, 6, 0, -4},  // 0x47 'G'
                                         {115, 5, 5, 6, 0, -4},  // 0x48 'H'
                                         {119, 5, 5, 6, 0, -4},  // 0x49 'I'
                                         {123, 5, 5, 6, 0, -4},  // 0x4A 'J'
                                         {127, 5, 5, 6, 0, -4},  // 0x4B 'K'
                                         {131, 5, 5, 6, 0, -4},  // 0x4C 'L'
                                         {135, 5, 5, 6, 0, -4},  // 0x4D 'M'
                                         {139, 5, 5, 6, 0, -4},  // 0x4E 'N'
                                         {143, 5, 5, 6, 0, -4},  // 0x4F 'O'
                                         {147, 5, 5, 6, 0, -4},  // 0x50 'P'
                                         {151, 5, 5, 6, 0, -4},  // 0x51 'Q'
                                         {155, 5, 5, 6, 0, -4},  // 0x52 'R'
                                         {159, 5, 5, 6, 0, -4},  // 0x53 'S'
                                         {163, 5, 5, 6, 0, -4},  // 0x54 'T'
                                         {167, 5, 5, 6, 0, -4},  // 0x55 'U'
                                         {171, 5, 5, 6, 0, -4},  // 0x56 'V'
                                         {175, 5, 5, 6, 0, -4},  // 0x57 'W'
                                         {179, 5, 5, 6, 0, -4},  // 0x58 'X'
                                         {183, 5, 5, 6, 0, -4},  // 0x59 'Y'
                                         {187, 5, 5, 6, 0, -4},  // 0x5A 'Z'
                                         {191, 2, 5, 3, 0, -4},  // 0x5B '['
                                         {193, 5, 5, 6, 0, -4},  // 0x5C '\'
                                         {197, 2, 5, 3, 0, -4},  // 0x5D ']'
                                         {199, 3, 2, 4, 0, -4},  // 0x5E '^'
                                         {200, 5, 1, 6, 0, 1},   // 0x5F '_'
                                         {201, 1, 1, 2, 0, -4},  // 0x60 '`'
                                         {202, 4, 4, 5, 0, -3},  // 0x61 'a'
                                         {204, 4, 5, 5, 0, -4},  // 0x62 'b'
                                         {207, 4, 4, 5, 0, -3},  // 0x63 'c'
                                         {209, 4, 5, 5, 0, -4},  // 0x64 'd'
                                         {212, 4, 4, 5, 0, -3},  // 0x65 'e'
                                         {214, 3, 5, 4, 0, -4},  // 0x66 'f'
                                         {216, 4, 5, 5, 0, -3},  // 0x67 'g'
                                         {219, 4, 5, 5, 0, -4},  // 0x68 'h'
                                         {222, 1, 4, 2, 0, -3},  // 0x69 'i'
                                         {223, 2, 5, 3, 0, -3},  // 0x6A 'j'
                                         {225, 4, 5, 5, 0, -4},  // 0x6B 'k'
                                         {228, 1, 5, 2, 0, -4},  // 0x6C 'l'
                                         {229, 5, 4, 6, 0, -3},  // 0x6D 'm'
                                         {232, 4, 4, 5, 0, -3},  // 0x6E 'n'
                                         {234, 4, 4, 5, 0, -3},  // 0x6F 'o'
                                         {236, 4, 5, 5, 0, -3},  // 0x70 'p'
                                         {239, 4, 5, 5, 0, -3},  // 0x71 'q'
                                         {242, 4, 4, 5, 0, -3},  // 0x72 'r'
                                         {244, 4, 4, 5, 0, -3},  // 0x73 's'
                                         {246, 5, 5, 6, 0, -4},  // 0x74 't'
                                         {250, 4, 4, 5, 0, -3},  // 0x75 'u'
                                         {252, 4, 4, 5, 0, -3},  // 0x76 'v'
                                         {254, 5, 4, 6, 0, -3},  // 0x77 'w'
                                         {257, 4, 4, 5, 0, -3},  // 0x78 'x'
                                         {259, 4, 5, 5, 0, -3},  // 0x79 'y'
                                         {262, 4, 4, 5, 0, -3},  // 0x7A 'z'
                                         {264, 3, 5, 4, 0, -4},  // 0x7B '{'
                                         {266, 1, 5, 2, 0, -4},  // 0x7C '|'
                                         {267, 3, 5, 4, 0, -4},  // 0x7D '}'
                                         {269, 5, 3, 6, 0, -3}}; // 0x7E '~'

typedef struct
{
    int w;
    int h;
    const uint8_t *color;
    uint8_t num_colors;
    const char *pixels;
} Image;

const uint8_t pac_color[] = {
    '+', 0xFF, 0, 0,
    '@', 0xFF, 0xFF, 0,
    '#', 0x21, 0x21, 0xFF};

const Image pac_a = {
    11, 14, pac_color, 4 /*sizeof(pac_color) / 4*/,
    "   ++      "
    "   +++@@@@@"
    "  +#++@@@@ "
    "++#+@@ @@  "
    "+++@@  @   "
    " ++@ #@    "
    " @@@@@     "
    " @@@@      "
    " @@@@@     "
    " @@@ @@    "
    "  @@@@@@   "
    "  @@@@@@@  "
    "   @@@@@@@ "
    "     @@@@@@"};

const Image pac_b = {
    13, 14, pac_color, 4 /*sizeof(pac_color) / 4*/,
    "   ++        "
    "   +++@@@@   "
    "  +#++@@@@@@ "
    "++#+@@@@@@@@@"
    "+++@@@  @@@@@"
    " ++@@ #@@    "
    " @@@@@@      "
    " @@@@        "
    " @@@@@@      "
    " @@@ @@@@    "
    "  @@@@@@@@@@@"
    "  @@@@@@@@@@@"
    "   @@@@@@@@@ "
    "     @@@@@   "};

const Image pac_c = {
    14, 14, pac_color, 4 /*sizeof(pac_color) / 4*/,
    "   ++         "
    "   +++@@@@    "
    "  +#++@@@@@@  "
    "++#+@@@@@@@@@ "
    "+++@@@@@@@@@@ "
    " ++@    @@@@@@"
    " @@@@@@@@@@@@@"
    " @@@@@@@@@@@@@"
    " @@@@@@@@@@@@@"
    " @@@ @@@@@@@@@"
    "  @@@@@@@@@@@ "
    "  @@@@@@@@@@@ "
    "   @@@@@@@@@  "
    "     @@@@@    "};

const GFXfont Org_01 PROGMEM = {(uint8_t *)Org_01Bitmaps,
                                (GFXglyph *)Org_01Glyphs, 0x20, 0x7E, 7};

const GFXfont font = Org_01;

enum BlendMode
{
    COLOR_SET = 0,
    COLOR_ADD = 1,
    COLOR_BLEND = 2,
};

enum ColorMode
{
    MODE_HSV = 1,
    MODE_RGB = 2,
};

int r_mult = 255;
int g_mult = 255;
int b_mult = 255;

uint8_t blend(float amount, int a, int b)
{
    float af = a / 255.0;
    float bf = b / 255.0;
    return (uint8_t)(255 * sqrt((1 - amount) * af * af + amount * bf * bf));
}

bool isRGB(int pixel, uint8_t r, uint8_t g, uint8_t b)
{
    int position = (ROPE_OFFSET + pixel) * 3;
    return (
        ledBuffer[position + 1] == r &&
        ledBuffer[position + 0] == g &&
        ledBuffer[position + 2] == b);
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
typedef struct
{
    float r;
    float g;
    float b;
} Color;
void colorSetRGB(Color *color, uint8_t r, uint8_t g, uint8_t b, int mode = COLOR_SET)
{
    color->r = r;
    color->g = g;
    color->b = b;
}
void colorSetHSV(Color *color, int hue, uint8_t sat, uint8_t val, int mode = COLOR_SET)
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

const uint8_t ringCount = 8;
const uint8_t ringSize[] = {60, 52, 44, 36, 28, 20, 12, 4};
const uint8_t ringStart[] = {0, 60, 112, 156, 192, 220, 240, 252};
const uint8_t ringIndexOffset = 115;
const uint8_t ringIndex[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 47, 48, 79, 80, 111, 112, 143, 144, 175, 176, 207, 208, 239, 240, 241,
    242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 224, 223,
    192, 191, 160, 159, 128, 127, 96, 95, 64, 63, 32, 31, 30, 29, 28, 27,
    26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 46, 49, 78, 81, 110, 113,
    142, 145, 174, 177, 206, 209, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229,
    228, 227, 226, 225, 222, 193, 190, 161, 158, 129, 126, 97, 94, 65, 62, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 50, 77, 82, 109,
    114, 141, 146, 173, 178, 205, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
    220, 221, 194, 189, 162, 157, 130, 125, 98, 93, 66, 61, 60, 59, 58, 57,
    56, 55, 54, 53, 52, 51, 76, 83, 108, 115, 140, 147, 172, 179, 204, 203,
    202, 201, 200, 199, 198, 197, 196, 195, 188, 163, 156, 131, 124, 99, 92, 67,
    68, 69, 70, 71, 72, 73, 74, 75, 84, 107, 116, 139, 148, 171, 180, 181,
    182, 183, 184, 185, 186, 187, 164, 155, 132, 123, 100, 91, 90, 89, 88, 87,
    86, 85, 106, 117, 138, 149, 170, 169, 168, 167, 166, 165, 154, 133, 122, 101,
    102, 103, 104, 105, 118, 137, 150, 151, 152, 153, 134, 121, 120, 119, 136, 135};

/********************************************************************************************************
 ********************************************************************************************************
 ******************************************              ************************************************
 ****************************************** === main === ************************************************
 ******************************************              ************************************************
 ********************************************************************************************************
 ********************************************************************************************************/
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

    int animationStep = (int)(state / 250);
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
    else if (animation == BLOCK_RAINBOW)
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
    else if (animation == SCHEDULED)
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
    else if (animation == FADE)
    {
        if (nextAnimation != FADE)
        {
            showNextAnimation();
            return;
        }
        rope_fade(fadeSpeed);
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
    animation = TWENTYTWENTY;
    nextAnimation = FADE;
    lastTime = millis();
    state = -1;
}
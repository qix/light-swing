
typedef struct
{
    int w;
    int h;
    const uint8_t *color;
    uint8_t num_colors;
    const char *pixels;
} Image;

const uint8_t pac_color[] = {
    '+', 96, 0, 0,
    '@', 96, 96, 0,
    '#', 13, 13, 96};

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
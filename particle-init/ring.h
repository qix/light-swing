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

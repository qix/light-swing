function range(v) {
  return Array.from(Array(v).keys());
}

const FLOWER_SVG = [
  ...range(115).map((i) => {
    return { x: 7, y: 115 + 15 - i };
  }),
];

range(16).forEach((x) => {
  range(16).forEach((y) => {
    if (x % 2 == 1) {
      y = 15 - y;
    }
    FLOWER_SVG.push({
      x,
      y,
    });
  });
});

const FUNKY_SVG = [
  { x: 130.299, y: 255.666 },
  { x: 129.048, y: 252.932 },
  { x: 127.607, y: 250.288 },
  { x: 126.124, y: 247.667 },
  { x: 124.739, y: 244.995 },
  { x: 123.61, y: 242.214 },
  { x: 122.921, y: 239.305 },
  { x: 122.835, y: 236.324 },
  { x: 123.399, y: 233.39 },
  { x: 124.521, y: 230.607 },
  { x: 126.052, y: 228.017 },
  { x: 127.865, y: 225.612 },
  { x: 129.873, y: 223.368 },
  { x: 132.131, y: 221.241 },
  { x: 134.867, y: 220.022 },
  { x: 137.847, y: 219.426 },
  { x: 140.877, y: 219.061 },
  { x: 143.87, y: 218.537 },
  { x: 146.666, y: 217.457 },
  { x: 148.957, y: 215.556 },
  { x: 150.541, y: 212.984 },
  { x: 151.511, y: 210.098 },
  { x: 152.06, y: 207.098 },
  { x: 152.328, y: 204.063 },
  { x: 152.321, y: 200.953 },
  { x: 152.054, y: 197.903 },
  { x: 151.728, y: 194.859 },
  { x: 151.368, y: 191.817 },
  { x: 151.003, y: 188.776 },
  { x: 150.657, y: 185.733 },
  { x: 150.36, y: 182.685 },
  { x: 150.136, y: 179.631 },
  { x: 150.01, y: 176.572 },
  { x: 150.006, y: 173.51 },
  { x: 150.143, y: 170.452 },
  { x: 150.438, y: 167.404 },
  { x: 150.901, y: 164.379 },
  { x: 151.539, y: 161.383 },
  { x: 152.35, y: 158.431 },
  { x: 153.484, y: 155.588 },
  { x: 155.129, y: 153.073 },
  { x: 156.969, y: 150.694 },
  { x: 158.947, y: 148.425 },
  { x: 161.006, y: 146.23 },
  { x: 163.098, y: 144.065 },
  { x: 165.176, y: 141.887 },
  { x: 167.193, y: 139.653 },
  { x: 169.094, y: 137.322 },
  { x: 170.825, y: 134.863 },
  { x: 172.324, y: 132.259 },
  { x: 173.537, y: 129.513 },
  { x: 174.429, y: 126.645 },
  { x: 174.988, y: 123.692 },
  { x: 175.226, y: 120.694 },
  { x: 175.176, y: 117.686 },
  { x: 174.731, y: 114.572 },
  { x: 173.788, y: 111.625 },
  { x: 172.44, y: 108.831 },
  { x: 170.47, y: 106.467 },
  { x: 167.774, y: 105.26 },
  { x: 164.81, y: 105.751 },
  { x: 162.206, y: 107.412 },
  { x: 160.06, y: 109.64 },
  { x: 158.3, y: 112.178 },
  { x: 156.883, y: 114.919 },
  { x: 155.805, y: 117.807 },
  { x: 155.312, y: 119.791 },
  { x: 155, y: 123.747 },
  { x: 154.752, y: 126.887 },
  { x: 154.507, y: 129.991 },
  { x: 154.262, y: 133.094 },
  { x: 154.015, y: 136.227 },
  { x: 153.716, y: 140.011 },
  { x: 152.781, y: 141.366 },
  { x: 150.211, y: 142.497 },
  { x: 147.661, y: 143.672 },
  { x: 145.038, y: 144.083 },
  { x: 142.83, y: 142.713 },
  { x: 141.469, y: 140.277 },
  { x: 140.853, y: 138.413 },
  { x: 140.87, y: 134.565 },
  { x: 140.883, y: 131.5 },
  { x: 140.896, y: 128.475 },
  { x: 140.909, y: 125.462 },
  { x: 140.923, y: 122.455 },
  { x: 140.936, y: 119.45 },
  { x: 140.949, y: 116.445 },
  { x: 140.962, y: 113.441 },
  { x: 140.975, y: 110.435 },
  { x: 140.988, y: 107.423 },
  { x: 141.001, y: 104.4 },
  { x: 141.014, y: 101.341 },
  { x: 141.03, y: 97.603 },
  { x: 141.136, y: 95.4373 },
  { x: 141.357, y: 92.3595 },
  { x: 141.478, y: 89.2764 },
  { x: 141.488, y: 86.1906 },
  { x: 141.376, y: 83.1057 },
  { x: 141.125, y: 80.029 },
  { x: 140.718, y: 76.9693 },
  { x: 140.132, y: 73.9386 },
  { x: 139.338, y: 70.9545 },
  { x: 138.302, y: 68.0451 },
  { x: 136.982, y: 65.2539 },
  { x: 135.332, y: 62.6466 },
  { x: 133.307, y: 60.3244 },
  { x: 130.886, y: 58.4313 },
  { x: 128.108, y: 57.1348 },
  { x: 125.099, y: 56.5632 },
  { x: 122.033, y: 56.7349 },
  { x: 119.067, y: 57.5575 },
  { x: 116.287, y: 58.8925 },
  { x: 113.725, y: 60.6129 },
  { x: 111.282, y: 61.3769 },
  { x: 108.809, y: 59.6174 },
  { x: 106.347, y: 57.841 },
  { x: 103.892, y: 56.0571 },
  { x: 101.435, y: 54.2755 },
  { x: 98.968, y: 52.5069 },
  { x: 96.4819, y: 50.7656 },
  { x: 93.9658, y: 49.0686 },
  { x: 91.4068, y: 47.437 },
  { x: 88.7907, y: 45.898 },
  { x: 86.1038, y: 44.4876 },
  { x: 83.3338, y: 43.2522 },
  { x: 80.4737, y: 42.25 },
  { x: 77.5276, y: 41.5492 },
  { x: 74.5213, y: 41.2187 },
  { x: 71.5009, y: 41.3087 },
  { x: 68.5232, y: 41.8317 },
  { x: 65.6405, y: 42.7577 },
  { x: 62.7127, y: 44.0219 },
  { x: 59.8251, y: 45.2911 },
  { x: 56.977, y: 46.7945 },
  { x: 54.3396, y: 48.9109 },
  { x: 54.8764, y: 51.2156 },
  { x: 57.8182, y: 52.7123 },
  { x: 60.8438, y: 53.6701 },
  { x: 63.8857, y: 54.4524 },
  { x: 66.9336, y: 55.1619 },
  { x: 69.9808, y: 55.8463 },
  { x: 73.0246, y: 56.5366 },
  { x: 76.0601, y: 57.2565 },
  { x: 79.0819, y: 58.0285 },
  { x: 82.0834, y: 58.8774 },
  { x: 85.0536, y: 59.8333 },
  { x: 87.9743, y: 60.9366 },
  { x: 90.8116, y: 62.2456 },
  { x: 93.4948, y: 63.8465 },
  { x: 95.8676, y: 65.8626 },
  { x: 97.486, y: 68.475 },
  { x: 98.51, y: 71.3375 },
  { x: 99.2075, y: 74.2927 },
  { x: 99.4833, y: 77.3097 },
  { x: 99.2469, y: 80.3236 },
  { x: 98.4552, y: 83.2384 },
  { x: 97.1469, y: 85.9653 },
  { x: 95.426, y: 88.4611 },
  { x: 93.4121, y: 90.7342 },
  { x: 91.205, y: 92.8246 },
  { x: 88.8782, y: 94.7829 },
  { x: 86.4847, y: 96.6607 },
  { x: 84.0674, y: 98.5072 },
  { x: 81.6648, y: 100.371 },
  { x: 79.318, y: 102.305 },
  { x: 77.0808, y: 104.364 },
  { x: 75.0301, y: 106.604 },
  { x: 73.277, y: 109.075 },
  { x: 71.9617, y: 111.794 },
  { x: 71.3576, y: 114.864 },
  { x: 71.3203, y: 118.055 },
  { x: 71.4978, y: 121.241 },
  { x: 71.9457, y: 124.399 },
  { x: 72.733, y: 127.486 },
  { x: 73.9353, y: 130.429 },
  { x: 75.6095, y: 133.123 },
  { x: 77.7556, y: 135.452 },
  { x: 80.2974, y: 137.347 },
  { x: 83.1163, y: 138.817 },
  { x: 86.1014, y: 139.929 },
  { x: 89.1762, y: 140.774 },
  { x: 92.2972, y: 141.438 },
  { x: 95.4382, y: 141.999 },
  { x: 98.5849, y: 142.526 },
  { x: 101.726, y: 143.086 },
  { x: 104.847, y: 143.747 },
  { x: 108.015, y: 144.446 },
  { x: 111.11, y: 144.154 },
  { x: 113.911, y: 142.847 },
  { x: 116.177, y: 140.695 },
  { x: 117.904, y: 138.06 },
  { x: 119.224, y: 135.192 },
  { x: 120.261, y: 132.211 },
  { x: 121.103, y: 129.169 },
  { x: 121.809, y: 126.094 },
  { x: 122.42, y: 123 },
  { x: 122.969, y: 119.895 },
  { x: 123.482, y: 116.784 },
  { x: 123.979, y: 113.67 },
  { x: 124.483, y: 110.558 },
  { x: 125.015, y: 107.451 },
  { x: 125.599, y: 104.351 },
  { x: 126.264, y: 101.267 },
  { x: 127.046, y: 98.2099 },
  { x: 127.998, y: 95.1997 },
  { x: 129.573, y: 92.2065 },
  { x: 131.94, y: 91.5064 },
  { x: 133.978, y: 93.7102 },
  { x: 135.223, y: 96.454 },
  { x: 136.124, y: 99.2888 },
  { x: 136.828, y: 102.164 },
  { x: 137.395, y: 105.064 },
  { x: 137.851, y: 107.983 },
  { x: 138.208, y: 110.915 },
  { x: 138.382, y: 112.85 },
  { x: 138.341, y: 116.849 },
  { x: 138.308, y: 120.03 },
  { x: 138.276, y: 123.169 },
  { x: 138.244, y: 126.298 },
  { x: 138.212, y: 129.426 },
  { x: 138.18, y: 132.564 },
  { x: 138.147, y: 135.736 },
  { x: 138.108, y: 139.588 },
  { x: 138.637, y: 141.706 },
  { x: 140.283, y: 144.153 },
  { x: 142.211, y: 146.41 },
  { x: 144.585, y: 148.146 },
  { x: 147.314, y: 148.477 },
  { x: 149.937, y: 147.24 },
  { x: 152.335, y: 145.476 },
  { x: 154.856, y: 144.007 },
  { x: 156.771, y: 143.794 },
  { x: 157.141, y: 140.125 },
  { x: 157.434, y: 137.21 },
  { x: 157.724, y: 134.33 },
  { x: 158.013, y: 131.458 },
  { x: 158.303, y: 128.581 },
  { x: 158.595, y: 125.673 },
  { x: 158.95, y: 122.15 },
  { x: 159.336, y: 120.176 },
  { x: 160.212, y: 117.628 },
  { x: 161.276, y: 115.145 },
  { x: 162.738, y: 112.886 },
  { x: 164.849, y: 111.448 },
  { x: 167.437, y: 111.552 },
  { x: 169.885, y: 113.179 },
  { x: 171.408, y: 115.795 },
  { x: 172.216, y: 118.705 },
  { x: 172.277, y: 121.737 },
  { x: 171.717, y: 124.731 },
  { x: 170.709, y: 127.614 },
  { x: 169.395, y: 130.374 },
  { x: 167.871, y: 133.024 },
  { x: 166.201, y: 135.584 },
  { x: 164.43, y: 138.076 },
  { x: 162.589, y: 140.515 },
  { x: 160.702, y: 142.92 },
  { x: 158.792, y: 145.308 },
  { x: 156.879, y: 147.694 },
  { x: 154.987, y: 150.097 },
  { x: 153.143, y: 152.541 },
  { x: 151.391, y: 155.056 },
  { x: 149.933, y: 157.708 },
  { x: 148.873, y: 160.579 },
  { x: 148.029, y: 163.521 },
  { x: 147.408, y: 166.517 },
  { x: 147.009, y: 169.551 },
  { x: 146.821, y: 172.605 },
  { x: 146.821, y: 175.666 },
  { x: 146.981, y: 178.723 },
  { x: 147.267, y: 181.773 },
  { x: 147.642, y: 184.813 },
  { x: 148.069, y: 187.847 },
  { x: 148.508, y: 190.879 },
  { x: 148.922, y: 193.914 },
  { x: 149.272, y: 196.958 },
  { x: 149.521, y: 200.009 },
  { x: 149.731, y: 203.186 },
  { x: 149.696, y: 206.327 },
  { x: 149.007, y: 209.368 },
  { x: 147.469, y: 212.039 },
  { x: 145.146, y: 214.085 },
  { x: 142.363, y: 215.518 },
  { x: 139.389, y: 216.552 },
  { x: 136.358, y: 217.423 },
  { x: 133.345, y: 218.365 },
  { x: 130.494, y: 219.675 },
  { x: 128.197, y: 221.746 },
  { x: 126.179, y: 223.995 },
  { x: 124.3, y: 226.364 },
  { x: 122.618, y: 228.876 },
  { x: 121.221, y: 231.554 },
  { x: 120.241, y: 234.402 },
  { x: 119.843, y: 237.372 },
  { x: 120.13, y: 240.346 },
  { x: 121.037, y: 243.205 },
  { x: 122.363, y: 245.911 },
  { x: 123.882, y: 248.523 },
  { x: 125.387, y: 251.142 },
  { x: 126.658, y: 253.871 },
];

const POINTS_SVG = FLOWER_SVG;
const MIN_X = Math.min(...POINTS_SVG.map((p) => p.x));
const MAX_X = Math.max(...POINTS_SVG.map((p) => p.x));
const MIN_Y = Math.min(...POINTS_SVG.map((p) => p.y));
const MAX_Y = Math.max(...POINTS_SVG.map((p) => p.y));

export function getCoordCount() {
  return POINTS_SVG.length;
}
export function generateCoords(width: number, height: number) {
  const padding = Math.min(50, width * 0.05, height * 0.05);
  const scale = Math.min(
    (width - 2 * padding) / (MAX_X - MIN_X),
    (height - 2 * padding) / (MAX_Y - MIN_Y)
  );
  const xPad = (width - scale * (MAX_X - MIN_X)) / 2;
  const yPad = (height - scale * (MAX_Y - MIN_Y)) / 2;
  return {
    xCoord: POINTS_SVG.map((pnt) => {
      return Math.floor(xPad + (pnt.x - MIN_X) * scale);
    }),
    yCoord: POINTS_SVG.map((pnt) => {
      return Math.floor(yPad + (pnt.y - MIN_Y) * scale);
    }),
  };
}

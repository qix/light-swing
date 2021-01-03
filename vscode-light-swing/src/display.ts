const canvas: HTMLCanvasElement = document.getElementById("canvas") as any;

let offscreen: OffscreenCanvas | null = null;

function renderLights(buffer: Uint8Array, xCoord: number[], yCoord: number[]) {
  const width = window.innerWidth;
  const height = window.innerHeight;

  if (!width || !height) {
    console.log("Zero size canvas");
    return;
  }
  canvas.width = width;
  canvas.height = height;
  if (!offscreen || offscreen.width !== width || offscreen.height !== height) {
    offscreen = new OffscreenCanvas(width, height);
  }

  const ctx = offscreen.getContext("2d");
  ctx.fillStyle = "black";
  ctx.fillRect(0, 0, width, height);

  const pixelCount = buffer.length / 3;
  for (let pixel = 0; pixel < pixelCount; pixel++) {
    const color =
      "rgb(" +
      [buffer[pixel * 3 + 1], buffer[pixel * 3 + 0], buffer[pixel * 3 + 2]]
        .map((v) => {
          return 32 + (255 - 32) * (v / 255);
        })
        .join(",") +
      ")";
    ctx.fillStyle = color;
    ctx.fillRect(xCoord[pixel] - 2, yCoord[pixel] - 2, 4, 4);
  }

  const bitmap = offscreen.transferToImageBitmap();
  const renderer = canvas.getContext("bitmaprenderer");
  renderer.transferFromImageBitmap(bitmap);
}

renderLights(new Uint8Array([]), [], []);

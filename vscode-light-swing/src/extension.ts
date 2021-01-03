"use strict";

import * as vscode from "vscode";
import { fstat, readFileSync, writeFileSync } from "fs";
import { compile } from "./parse";
import { join } from "path";

function readScript(name: string) {
  return readFileSync(join(__dirname, name), {
    encoding: "utf-8",
  });
}

function codeSwingCompile(extension: string, code: string) {
  let compiled: string;
  let error: string | null = null;
  try {
    compiled = compile(code);
  } catch (err) {
    error = err.stack;
  }

  if (error) {
    return `
      <html>
        <body style="background-color: #000; color: #eee;">
          <pre>${error}</pre>
        </body>
      </html>`;
  }
  const html = `
  <html>
    <head>
    <style type="text/css">
      body, html { 
        margin: 0;
        padding: 0;
        overflow: none;
        background-color: #000;
      }
      canvas {
        width: 100%;
        height: 100%;
      }
    </style>
    </head>
    <body>
      <canvas id="canvas"></canvas>
      <script type="text/javascript">
        let exports = {};
        ${readScript("stdlib.js")}
        ${readScript("display.js")}

        ${readScript("points.js")}

        initDisplay(getCoordCount());
        strip.show = () => {
          const {xCoord, yCoord} = generateCoords(canvas.width, canvas.height);
          renderLights(ROPE_BUFFER, xCoord, yCoord);
        };
        const {setup, loop} = ${compiled};
        setup();
        setInterval(loop, 50);
      </script>
    </body>
  </html>
  `;
  writeFileSync("/tmp/codeswing.htm", html);
  return html;
}
export async function activate(context: vscode.ExtensionContext) {
  return { codeSwingCompile };
}

export function deactivate() {}

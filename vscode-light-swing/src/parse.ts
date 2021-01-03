import { Location, Block } from "./ast";
import { parse as pegParse, SyntaxError } from "./lang";
import prettier from "prettier/standalone";
import prettierBabel from "prettier/parser-babel";
import { Context } from "./context";

export function sourceArrow(source: string, location: Location): string {
  const { start, end } = location;
  const sourceLines = source.split("\n");

  let output = "";
  for (let line = start.line; line <= end.line; line++) {
    const source = sourceLines[line - 1];
    const left = line > start.line ? 0 : start.column - 1;
    const right = line < end.line ? source.length : end.column - 1;
    output += source + "\n";
    output += " ".repeat(left) + "^".repeat(right - left) + "\n";
  }

  return output;
}

function parse(source: string) {
  try {
    return pegParse(source);
  } catch (err) {
    if (err.location) {
      // Could improve error reporting here
      // console.log(sourceArrow(source, err.location));
    }
    throw err;
  }
}

export class Controller {
  constructor(
    readonly source: string,
    readonly size: number,
    readonly ledBuffer: Uint8Array,
    readonly setup: () => void,
    readonly loop: () => void,
    readonly message: (input: string) => void
  ) {}
}

export function compile(source: string) {
  const ctx = new Context();
  let ast: Block;
  try {
    ast = parse(source);
  } catch (err) {
    console.log(err.location);
    throw err;
  }
  let transpiled = ast.statements.map((s) => s.transpile(ctx)).join("\n");

  // Genate source code for each message
  let blockSource: { [name: string]: string } = {};
  Object.entries(ctx.messages).forEach(([name, block]) => {
    blockSource[name] = block.transpile(ctx);
  });
  Object.keys(ctx.modes).forEach((name) => {
    if (!blockSource.hasOwnProperty(name)) {
      blockSource[name] = `{ set_mode(${name}); }`;
    }
  });

  blockSource["*"] = blockSource["*"] || "{}";

  transpiled =
    [...Object.keys(ctx.modes).sort(), "NUM_DISPLAY_MODES"]
      .map((mode, idx) => {
        return `const ${mode} = ${idx};`;
      })
      .join("\n") + transpiled;

  transpiled +=
    "function message(msg) {\n" +
    [
      ...Object.entries(blockSource)
        .filter(([name, source]) => name !== "*")
        .map(([name, source]) => {
          return `if (msg === ${JSON.stringify(name)}) ${source}`;
        }),
      blockSource["*"],
    ].join(" else ") +
    "}\n";

  transpiled +=
    "function render_mode() {\n" +
    Object.entries(ctx.modes)
      .map(([name, block]) => {
        return `if (current_mode === ${name}) ${block.transpile(ctx)}`;
      })
      .join(" else ") +
    "}\n";

  const header = "(function() {\n";
  const footer = "return { setup, loop, message };\n" + "})()";

  return prettier.format(header + transpiled + footer, {
    parser: "babel",
    plugins: [prettierBabel],
  });
}

/*
export function createController(
  source: string,
  options: {
    ledCount: number;
    log: (format: string, ...args: any) => void;
    render: () => void;
  }
) {

  const ROPE_LEDS = options.ledCount;
  const ledBuffer = new Uint8Array(ROPE_LEDS * 3);

  const build = eval(code);
  const { setup, loop, message } = build(
    ...Object.keys(inputs)
      .sort()
      .map((k) => inputs[k])
  );

  return new Controller(
    source,
    ROPE_LEDS,
    ledBuffer,
    setup,
    loop,
    (msg: string) => {
      for (const word of msg.split(" ")) {
        message(word.toUpperCase());
      }
    }
  );
}
*/

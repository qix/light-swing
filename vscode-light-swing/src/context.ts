import { invariant } from "./invariant";
import { Struct, Block } from "./ast";

export class Context {
  structures: { [name: string]: Struct } = {};
  messages: { [name: string]: Block } = {};
  modes: { [name: string]: Block } = {};
}

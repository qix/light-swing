export function invariant(test: any, message: string): asserts test is true {
  if (!test) {
    throw new Error(message);
  }
}

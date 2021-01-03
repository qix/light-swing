const UINT_MAX = 65535;
let ROPE_LEDS = 10;
let ROPE_BUFFER = new Uint8Array(ROPE_LEDS * 3);
export { UINT_MAX, ROPE_LEDS, ROPE_BUFFER };

export function initDisplay(ledCount: number) {
  ROPE_LEDS = ledCount;
  ROPE_BUFFER = new Uint8Array(ledCount * 3);
}
// These values are used to produce better colors in lights, since the birghtness is not
// uniform across the range. On a computer screen though treat it as uniform.
const gamma8 = Array.from(Array(256)).map((v, idx) => idx);
const gamma8_floor = Array.from(Array(256)).map((v, idx) => idx);
const gamma8_partial = Array.from(Array(256)).fill(0);
export { gamma8, gamma8_floor, gamma8_partial };

const _subscriptions: Array<{
  eventPrefix: string;
  callback: (event: string, data: string) => void;
}> = [];

const Particle = {
  subscribe(eventPrefix, callback) {
    console.log(`${eventPrefix} subscription created`);
    _subscriptions.push({ eventPrefix, callback });
  },
};
const Log = {
  info(...args) {
    console.log(args);
  },
};
const strip = {
  getPixels() {
    return ROPE_BUFFER;
  },
  begin() {},
  clear() {
    ROPE_BUFFER.fill(0);
  },
  show() {
    throw new Error("Not implemented error");
  },
};
export { Particle, Log, strip };

export function strcmp(left: string, right: string) {
  return left.localeCompare(right);
}
export function random(min: number, max: number | null = null) {
  if (max === null) {
    max = min;
    min = 0;
  }
  return min + Math.floor(Math.random() * (max - min));
}
export function min(a: number, b: number) {
  return Math.min(a, b);
}
export function max(a: number, b: number) {
  return Math.max(a, b);
}
export function uint8(value: number | string) {
  if (typeof value === "string") {
    return value.charCodeAt(0);
  } else {
    return value & 255;
  }
}
export function uint16(value: number) {
  return value & 65535;
}
export function abs(value: number) {
  return Math.abs(value);
}
export function fabs(value: number) {
  return Math.abs(value);
}
export function delay(ms: number) {}
export function millis() {
  return Date.now();
}
export function digitalWrite() {}
export function switch_light() {}
export function strlen(str: string) {
  return str.length;
}
export function hex2int(char: string) {
  return parseInt(char, 16);
}

/* Called by code-swing when the input changes */
export function checkInput(event: string) {
  _subscriptions.forEach((subscription) => {
    if (event.startsWith(subscription.eventPrefix)) {
      subscription.callback(event, "");
    }
  });
}

import { encode, decode } from "@msgpack/msgpack";

/**
 * @type {import("@nil-/xit").CoDec<any>}
 */
export const msgpack_codec = {
    encode: o => encode(o),
    decode: o => decode(o)
};

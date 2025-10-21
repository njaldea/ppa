<script>
    import { xit } from "@nil-/xit";

    import { msgpack_codec } from "./codec.js";

    const { values } = xit();

    /** @typedef {{ position: [number, number]; radius: number; }} Circle */
    const value_x = values.json("value-x", /** @type Circle */ ({ position: [0, 0], radius: 1.0 }), msgpack_codec);
    const value_y = values.json("value-y", /** @type Circle */ ({ position: [0, 0], radius: 1.0 }), msgpack_codec);
</script>

<div style:width=100% style:height=100%>
    <svg viewBox="-2 -2 4 4" xmlns="http://www.w3.org/2000/svg">
        {#each [
            {...$value_x, color: "blue"},
            {...$value_y, color: "red"}
        ] as { position: [cx, cy], radius: r, color: stroke }}
            <circle {cx} {cy} {r} {stroke} fill="none" stroke-width=0.1 />
        {/each}
    </svg>
</div>
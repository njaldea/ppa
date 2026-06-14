<script>
    import { xit } from "@nil-/xit";
    import Plotly from "@nil-/xit/3pt/Plotly.svelte"

    import { msgpack_codec } from "./codec.js";

    const { values } = xit();

    const value_x = values("value-x", /** @type null | string[] */ (null), msgpack_codec);
    const value_y = values("value-y", /** @type null | string[] */ (null), msgpack_codec);
</script>

{#if $value_x != null && $value_y != null}
    <Plotly data={[{ x: $value_x, y:$value_y, type: "bar"}]}></Plotly>
{/if}
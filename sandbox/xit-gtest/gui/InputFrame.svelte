<script>
    import { xit } from "@nil-/xit";
    import JSONEditor from "@nil-/xit/3pt/JSONEditor.svelte";
    import Save from "@nil-/xit/test/Save.svelte";

    import { msgpack_codec } from "./codec.js";

    const { values } = xit();
    const buf_value = values('value', /** @type any */ ({}), msgpack_codec);
</script>

<Save></Save>
<JSONEditor bind:data={$buf_value}></JSONEditor>
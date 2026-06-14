<script lang="ts">
    import { type Writable } from "svelte/store";
    import { xit, codec_bool } from "@nil-/xit";
    const { tag, signals, load_frame_data } = xit();
    const finalize = signals("finalize");

    let result = $state(null) as Writable<boolean> | null;
    load_frame_data("tag_info", tag)
        .then(f => (result = f.values("value", false, codec_bool)));
</script>


{#if result != null}
    {`Result ${$result}`}
    <button onclick={() => finalize()}>Click to update</button>
{/if}
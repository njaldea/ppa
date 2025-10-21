<script lang="ts">
    import { onDestroy } from "svelte";
    import { xit } from "@nil-/xit";
    const { tag, signals, load_frame_data } = xit();
    const finalize = signals.none("finalize");

    let result = $state(false);
    let unsubs = [];
    load_frame_data("tag_info", tag)
        .then(f => {
            unsubs.push(f.unsub);
            unsubs.push(f.values.boolean("value", result)
                .subscribe(v => {
                    console.log("updated", v);
                    result = v;
            }));
        });

    onDestroy(() => unsubs.forEach(v => v()));
</script>


{`Result ${result}`}

<button onclick={finalize}>Click to update</button>
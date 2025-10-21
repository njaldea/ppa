<script lang="ts">
    import ReactiveValueLoader from "@nil-/xit/components/loaders/ReadOnly.svelte";
    // import ReactiveValueLoader from "./loaders/ReadOnly.svelte";
    import { msgpack_codec } from "./codec.js";
    let { tag } = $props();
</script>

<ReactiveValueLoader frames={[
    { id: "json_input_frame", tag, items: [ { codec: msgpack_codec, key: "value", type: "json", default: {} } ] }
]}>
    {#snippet loaded_data([ json_input_frame ])}
        {JSON.stringify(json_input_frame)}
    {/snippet}
</ReactiveValueLoader>
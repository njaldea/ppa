<script>
    import { createJSONEditor } from 'vanilla-jsoneditor/standalone.js'
    import { xit } from "@nil-/xit";

    import { msgpack_codec } from "./codec.js";

    const { values, signals } = xit();

    const buf_value = values.json('value', /** @type any */ ({}), msgpack_codec);
    const finalize = signals.none("finalize");

    /** @type (target: HTMLDivElement) => { destroy: () => void }*/
    const json_editor = (target) => {
        let is_notified = true;
        const editor = createJSONEditor({
            target,
            props: {
                content: { json: null },
                onChange: (updatedContent, previousContent, { contentErrors, patchResult }) => {
                    if (is_notified) {
                        return;
                    }
                    if ("json" in updatedContent)
                    {
                        $buf_value = updatedContent.json;
                    }
                    else if ("text" in updatedContent)
                    {
                        try
                        {
                            $buf_value = JSON.parse(updatedContent.text)
                        }
                        catch (e)
                        {
                            console.log(e);
                        }
                    }
                }
            }
        });
        const unsub = buf_value.subscribe((v) => {
            is_notified = true;
            editor.set({ json: v });
            is_notified = false;
        });
        return {
            destroy: () => {
                unsub();
                editor.destroy();
            }
        };
    };
</script>

<svelte:window onkeydowncapture={e => {
    if ((e.ctrlKey || e.metaKey) && e.key == "s") {
        finalize();
        alert("saving");
    }
}}></svelte:window>
<div style:display="contents" use:json_editor></div>
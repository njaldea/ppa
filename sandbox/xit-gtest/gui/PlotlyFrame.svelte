<script>
    import "https://cdn.plot.ly/plotly-2.35.2.min.js";

    import { xit } from "@nil-/xit";

    import { msgpack_codec } from "./codec.js";

    const { values } = xit();

    const value_x = values.json("value-x", /** @type null | string[] */ (null), msgpack_codec);
    const value_y = values.json("value-y", /** @type null | string[] */ (null), msgpack_codec);

    /** @type import("svelte/action").Action<HTMLDivElement, any[]> */
    const plot_it = (target, props) => {
        window.Plotly.newPlot(target, props);
        const observer = new ResizeObserver(() => window.Plotly.Plots.resize(target));
        observer.observe(target);
        return {
            update: (new_props) => window.Plotly.react(target, new_props),
            destroy: () => {
                observer.unobserve(target);
                window.Plotly.purge(target);
            }
        };
    };
</script>

{#if $value_x != null && $value_y != null}
    <div use:plot_it={[{ x: $value_x, y:$value_y, type: "bar"}]}></div>
{/if}
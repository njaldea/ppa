#include "userland_utils.hpp"

#include "frame_setup.hpp"

#include <nil/xit/gtest.hpp>

struct Expected
{
    XIT_INPUTS("slider_frame");
    XIT_OUTPUTS();
    XIT_EXPECTS("flag");
};

XIT_TEST_F(Expected, _, "$test/expected")
{
    auto& [e] = xit_expects;
    EXPECT_TRUE(e);
    e = !e;
}

struct Plotly
{
    using input_frames = nil::xit::gtest::Inputs<"slider_frame", "json_input_frame">;
    using output_frames = nil::xit::gtest::Outputs<"plotly_frame">;
};

XIT_TEST_F(Plotly, demo, "$test/plotly/*")
{
    const auto& [ranges, input_data] = xit_inputs;
    //           ┃           ┃         ┗━━━ from Input<"slider_frame",
    //           "input_frame"> ┃           ┗━━━ type == nlohmann::json ┗━━━ type
    //           == Ranges

    auto& [view] = xit_outputs;
    //     ┃       ┗━━━ from Output<"plotly_frame">
    //     ┗━━━ type == nlohmann::json

    std::cout << "Running: " << input_data["x"][2] << std::endl;

    view = input_data;
    view["y"][0] = std::int64_t(input_data["y"][0]) * ranges.v1;
    view["y"][1] = std::int64_t(input_data["y"][1]) * ranges.v2;
    view["y"][2] = std::int64_t(input_data["y"][2]) * ranges.v3;
}

struct DrawWithInput
{
    using input_frames = nil::xit::gtest::Inputs<"circles_input_frame">;
    using output_frames = nil::xit::gtest::Outputs<"draw_frame">;
};

XIT_TEST_F(DrawWithInput, demo, "$test/draw")
{
    const auto& [input_data] = xit_inputs;
    //           ┃             ┗━━━ from Input<"input_frame">
    //           ┗━━━ type == Circles

    // do your test here...

    auto& [draw] = xit_outputs;
    //     ┃       ┗━━━ from Output<"draw_frame">
    //     ┗━━━ type == Circles

    // Assign data to output.
    // This example is overly simplified where the input and output are of the
    // same type and just copies them to the output directly.
    draw = input_data;
}

struct Draw
{
    using output_frames = nil::xit::gtest::Outputs<"draw_frame">;
};

XIT_TEST_F(Draw, sample, "$test/.")
{
    const Circles circles;

    // Execute test here

    auto& [draw] = xit_outputs;
    //     ┃       ┗━━━ from Output<"draw_frame">
    //     ┗━━━ type == Circles
    draw = circles;
}

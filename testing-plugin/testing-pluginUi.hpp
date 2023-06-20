#pragma once
#include <testing-plugin/testing-pluginModel.hpp>
#include <halp/layout.hpp>

namespace Example
{
    struct testing_plugin::ui
    {
        using enum halp::colors;
        using enum halp::layouts;

            halp_meta(name, "Main")
            halp_meta(layout, vbox)
            halp_meta(background, dark)

            halp::label title{"My First Processor"};
    };
}

#pragma once

#include <halp/audio.hpp>
#include <halp/controls.hpp>
#include <halp/meta.hpp>
#include <string> 
#include <ATen/core/ivalue.h>
#include <torch/script.h>
#include <iostream>

namespace Example
{

    class testing_plugin
    {
    public:
        // static constexpr auto name() { return "Testing Plugin" ; }
        halp_meta(name, "Testing Plugin")
        halp_meta(category, "Audio")
        halp_meta(c_name, "testing_plugin")
        halp_meta(uuid, "62004a80-ed0d-473a-84b5-b8d191a0a8b0")

        // Inner model
        torch::jit::script::Module  model;
        bool                        module_loaded;

        // Define inputs and outputs ports.
        struct
        {
            struct {
                static consteval auto name() { return "in"; }
                float value;
            } in;
        } inputs;

        struct
        {
            struct {
                static consteval auto name() { return "out"; }
                float value;
            } out;
        } outputs;



        using setup = halp::setup;

        bool load_model(std::string filename)
        {
            try
            {
                // Deserialize the Scriptmodel from a file using torch::jit::load().
                model = torch::jit::load(filename);
            }
            catch (const c10::Error &e)
            {
                std::cerr << "error loading the model : " << filename << "\n";
                return false;
            }

            std::cout << "Module : " << filename << "loaded\n";

            return true;
        }

        void prepare(halp::setup info)
        {
            // Initialization, this method will be called with buffer size, etc.
            // Load the model here
            module_loaded = false;
            module_loaded = load_model("models/traced-lin-pred.pt");
        }

        // Do our processing for N samples
        using tick = halp::tick;

        // Defined in the .cpp
        void operator()(halp::tick t);

        // UI is defined in another file to keep things clear.
        struct ui;
    };

}

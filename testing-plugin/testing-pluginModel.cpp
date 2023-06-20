#include "testing-plugin.hpp"
// #include <torch/script.h>

namespace Example
{
    void testing_plugin::operator()(halp::tick t)
    {
        // in and out modifiers
        auto * in = &inputs.in;
        auto * out = &outputs.out;

        if(module_loaded)
        {
            // inputs for the model
            std::vector<torch::jit::IValue> torch_inputs;
            
            // transforming score input flow into recognizable torch input
            float input_val_arr [] = { in->value };
            long inputSize = sizeof(input_val_arr)/sizeof(float);

            torch::Tensor torch_in = torch::from_blob(input_val_arr, {1, inputSize}).reshape({-1,1}).clone();

            torch_inputs.push_back(torch_in);

            at::Tensor torch_output = model.forward(torch_inputs).toTensor();

            out->value = torch_output[0].item().toFloat();
        }
    }

    
}

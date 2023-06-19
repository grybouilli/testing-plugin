#include "testing-plugin.hpp"

namespace Example
{
    void testing_plugin::operator()(halp::tick t)
    {
        // in and out modifiers
        auto * in = &inputs.input;
        auto * out = &outputs.output;

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

    bool testing_plugin::load_model(std::string filename)
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
}

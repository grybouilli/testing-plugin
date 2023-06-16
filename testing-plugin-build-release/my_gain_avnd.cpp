// clang-format off
#include <ossia/detail/config.hpp>

#include "testing-plugin/testing-plugin.hpp"

/* #undef AVND_REFLECTION_HELPERS */
#if defined(AVND_REFLECTION_HELPERS)
#include <avnd/common/aggregates.hpp>
#include <avnd/concepts/port.hpp>
#include <avnd/concepts/message.hpp>
#include <avnd/common/index.hpp>

#include ""

#include <avnd/concepts/generic.hpp>
#include <avnd/introspection/input.hpp>
#include <avnd/introspection/output.hpp>
#include <avnd/introspection/messages.hpp>

#include ""
#endif

#include <Avnd/Factories.hpp>

namespace oscr
{
template <>
void custom_factories<Example::testing_plugin>(
    std::vector<std::unique_ptr<score::InterfaceBase>>& fx,
    const score::ApplicationContext& ctx, const score::InterfaceKey& key)
{
  using namespace oscr;
  oscr::instantiate_fx<Example::testing_plugin>(fx, ctx, key);
}
}

// clang-format on

// clang-format off
#include "score_addon_testing-plugin.hpp"

#include <score/application/ApplicationContext.hpp>
#include <score/plugins/Interface.hpp>
#include <score/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <score/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>

#include <score_plugin_engine.hpp>
#include <score/plugins/FactorySetup.hpp>

#include <Avnd/Factories.hpp>

namespace Example { struct testing_plugin; } 



score_addon_testing_plugin::score_addon_testing_plugin() = default;
score_addon_testing_plugin::~score_addon_testing_plugin() = default;

std::vector<std::unique_ptr<score::InterfaceBase>> score_addon_testing_plugin::factories(
        const score::ApplicationContext& ctx,
        const score::InterfaceKey& key) const
{
  std::vector<std::unique_ptr<score::InterfaceBase>> fx;

  
::oscr::custom_factories<Example::testing_plugin>(fx, ctx, key); 



  return fx;
}

std::vector<score::PluginKey> score_addon_testing_plugin::required() const
{
  return {score_plugin_engine::static_key()};
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_addon_testing_plugin)

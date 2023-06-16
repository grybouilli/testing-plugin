// clang-format off
#include <score/application/ApplicationContext.hpp>
#include <score/plugins/Interface.hpp>
#include <score/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <score/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>

class score_addon_testing_plugin final
  : public score::FactoryInterface_QtInterface
  , public score::Plugin_QtInterface
{
  SCORE_PLUGIN_METADATA(1, "0775ecc8-4cc0-4917-83c5-0b9f4544e2b5")
public:
  score_addon_testing_plugin();
  ~score_addon_testing_plugin() override;
private:
  std::vector<std::unique_ptr<score::InterfaceBase>> factories(
          const score::ApplicationContext& ctx,
          const score::InterfaceKey& key) const override;
  std::vector<score::PluginKey> required() const override;
};

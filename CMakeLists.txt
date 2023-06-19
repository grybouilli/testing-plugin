cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(NOT TARGET score_lib_base)
  include(ScoreExternalAddon)
endif()

include(ScoreAvndHelper)

project(score_addon_testing-plugin LANGUAGES CXX)

configure_file("models/traced-lin-pred.pt" "build/models" COPYONLY)

#find_package(Torch REQUIRED)

#target_link_libraries(my_gain "${TORCH_LIBRARIES}")

avnd_score_plugin_init(
  BASE_TARGET score_addon_testing-plugin
)

avnd_score_plugin_add(
  BASE_TARGET score_addon_testing-plugin
  SOURCES
    testing-plugin/testing-plugin.hpp
    testing-plugin/testing-pluginModel.hpp
    testing-plugin/testing-pluginModel.cpp
    testing-plugin/testing-pluginUi.hpp
  TARGET my_gain
  MAIN_CLASS testing-plugin
  NAMESPACE Example
)

avnd_score_plugin_finalize(
  BASE_TARGET score_addon_testing-plugin
  PLUGIN_VERSION 1
  PLUGIN_UUID "0775ecc8-4cc0-4917-83c5-0b9f4544e2b5"
)

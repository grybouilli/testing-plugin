cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

if(NOT TARGET score_lib_base)
  include(ScoreExternalAddon)
endif()

include(ScoreAvndHelper)

project(score_addon_testing_plugin LANGUAGES CXX)

# configure_file("models/traced-lin-pred.pt" "${CMAKE_INSTALL_PREFIX}/models/traced-lin-pred.pt" COPYONLY)
# configure_file("models/traced-lin-pred.pt" "/tmp/models/traced-lin-pred.pt" COPYONLY)

#find_package(Torch REQUIRED)

#target_link_libraries(my_gain "${TORCH_LIBRARIES}")

avnd_score_plugin_init(
  BASE_TARGET score_addon_testing_plugin
)


avnd_score_plugin_add(
  BASE_TARGET score_addon_testing_plugin
  SOURCES
    testing-plugin/testing-plugin.hpp
    testing-plugin/testing-pluginModel.hpp
    testing-plugin/testing-pluginModel.cpp
    testing-plugin/testing-pluginUi.hpp
  TARGET testing_plugin
  MAIN_CLASS testing_plugin
  NAMESPACE Example
)

set(CMAKE_INSTALL_RPATH "/usr/lib/libtorch-cpu/lib")
set(CMAKE_BUILD_RPATH "/usr/lib/libtorch-cpu/lib")
find_package(Torch REQUIRED)
target_link_libraries(score_addon_testing_plugin PRIVATE "${TORCH_LIBRARIES}")

avnd_score_plugin_finalize(
  BASE_TARGET score_addon_testing_plugin
  PLUGIN_VERSION 1
  PLUGIN_UUID "0775ecc8-4cc0-4917-83c5-0b9f4544e2b5"
)


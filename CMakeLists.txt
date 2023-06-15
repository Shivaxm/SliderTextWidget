cmake_minimum_required(VERSION 3.3)
project(QtDesignerPlugin VERSION 1.0.0 LANGUAGES CXX)
include_directories(${CMAKE_BINARY_DIR})
include(GenerateExportHeader)

set(CMAKE_PREFIX_PATH "/home/Qt/5.15.2/gcc_64/lib/cmake/Qt5Designer" ${CMAKE_PREFIX_PATH})
find_package(Qt5 COMPONENTS Widgets Designer REQUIRED)

include_directories(${Qt5Designer_INCLUDE_DIRS})



set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)
set(CMAKE_SHARED_MODULE_PREFIX "")


find_package(Qt5 COMPONENTS Widgets Gui Designer REQUIRED)


add_library(SliderTextBoxLib SHARED
        SliderTextBox.cpp
        ImageViewer.cpp
        ImageViewer.ui

)
qt5_wrap_ui(UI_HEADERS ImageViewer.ui)

generate_export_header(SliderTextBoxLib)
target_link_libraries(SliderTextBoxLib PUBLIC Qt5::Widgets)

# Add the following line to define the executable target
add_executable(QtDesignerPlugin main.cpp)

# Link the required libraries to the executable
target_link_libraries(QtDesignerPlugin PRIVATE Qt5::Widgets SliderTextBoxLib)

### PLUGIN SPECIFIC STUFF
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})
include(${CMAKE_CURRENT_SOURCE_DIR}/QtInstallPaths.cmake)

find_package(Qt5UiPlugin CONFIG REQUIRED)

option(SLIDERTEXTBOX_BUILD_PLUGINS "Build and Install SliderTextBox Plugins for Qt Designer" ON)
set(SLIDERTEXTBOX_DIR_FOR_DESIGNER_PLUGIN "/home/vboxuser/Qt/5.15.2/gcc_64/plugins/designer")


set(QTC_DESIGNER_DEFAULT "${QT_INSTALL_PLUGINS}/../../../Tools/QtCreator/lib/Qt/plugins/designer/")

set(SLIDERTEXTBOX_DIR_FOR_CREATOR_DESIGNER_PLUGIN "/home/vboxuser/Qt/Tools/QtCreator/lib/Qt/plugins/designer")


if (SLIDERTEXTBOX_BUILD_PLUGINS)
        add_library(SliderTextBoxPlugins MODULE SliderTextWidgetPlugin.cpp)
        target_link_libraries(SliderTextBoxPlugins Qt5::Widgets Qt5::UiPlugin)

        target_link_libraries(SliderTextBoxPlugins SliderTextBoxLib)

        if (SLIDERTEXTBOX_DIR_FOR_DESIGNER_PLUGIN)
        add_custom_target(CopySliderTextBoxPluginsToDesigner ALL DEPENDS SliderTextBoxLib)
        add_custom_command(TARGET CopySliderTextBoxPluginsToDesigner POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SliderTextBoxPlugins> ${SLIDERTEXTBOX_DIR_FOR_DESIGNER_PLUGIN}
                COMMENT "Copying SliderTextBox plugin to designer: ${SLIDERTEXTBOX_DIR_FOR_DESIGNER_PLUGIN}"
        )
        endif()

        if (SLIDERTEXTBOX_DIR_FOR_CREATOR_DESIGNER_PLUGIN)
        add_custom_target(CopySliderTextBoxPluginsToQtCreator ALL DEPENDS SliderTextBoxLib)
        add_custom_command(TARGET CopySliderTextBoxPluginsToQtCreator POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SliderTextBoxPlugins> ${SLIDERTEXTBOX_DIR_FOR_CREATOR_DESIGNER_PLUGIN}
                COMMENT "Copying SliderTextBox plugin to Qt Creator's designer: ${SLIDERTEXTBOX_DIR_FOR_CREATOR_DESIGNER_PLUGIN}"
        )
        endif()
endif()

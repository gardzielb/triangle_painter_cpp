cmake_minimum_required(VERSION 3.17)
project(triangle_painter)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core)

set(CMAKE_CXX_STANDARD 14)
#set(GXX_COVERAGE_COMPILE_FLAGS "-std=c++1z")
#set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} ${GXX_COVERAGE_COMPILE_FLAGS}")

add_executable(triangle_painter src/main.cpp src/TriangleSurface.h src/ParametersPanel.h src/PainterWindow.h src/PixelPainter.h src/AdvancedPixelPainter.h src/gbGeo.h src/Polygon.h src/painting.h src/PainterSettings.h src/gbGeo.cpp src/ColorButtonWrapper.h src/PaintCommand.h src/BarycentricPixelPainter.h src/SurfacePainter.h src/FillTriangleStrategy.h src/SurfacePainterFactory.h src/LightAnimation.h)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )
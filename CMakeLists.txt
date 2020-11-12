cmake_minimum_required(VERSION 3.17)
project(triangle_painter)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core)

set(CMAKE_CXX_STANDARD 14)
#set(GXX_COVERAGE_COMPILE_FLAGS "-std=c++1z")
#set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} ${GXX_COVERAGE_COMPILE_FLAGS}")

add_executable(triangle_painter main.cpp TriangleSurface.h ParametersPanel.h PainterWindow.h PixelPainter.h AdvancedPixelPainter.h gbGeo.h Polygon.h painting.h PainterSettings.h gbGeo.cpp ColorButtonWrapper.h PaintCommand.h BarycentricPixelPainter.h SurfacePainter.h FillTriangleStrategy.h SurfacePainterFactory.h LightAnimation.h)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )
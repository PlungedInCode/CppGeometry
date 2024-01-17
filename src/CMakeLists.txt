# lib/Geometry/CMakeLists.txt
add_library(Geometry SHARED
    Circle.cpp
    Ellipse.cpp
    Line.cpp
    Point.cpp
    Polygon.cpp
    Rectangle.cpp
    Square.cpp
    Triangle.cpp
    Vector.cpp
)

# Include the "include" directory for header files
target_include_directories(Geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
# Link the library with cxx_setup
target_link_libraries(Geometry PUBLIC cxx_setup)
# add_subdirectory(tests)
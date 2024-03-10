cmake_minimum_required(VERSION 3.27)

project(ethereum-client-simplified)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")


# Find Boost components
find_package(Boost REQUIRED)
find_package(fmt REQUIRED)


# Include Boost directories
include_directories(${Boost_INCLUDE_DIRS})

# Add all C++ source files from the src directory
file(GLOB SOURCES "src/*.cpp" "src/*.h")

# Add main.cpp as the starting point
list(APPEND SOURCES "src/main.cpp")

# Create an executable from the sources
add_executable(ethereum-client-simplified ${SOURCES} )

# Include Boost directories
target_include_directories(ethereum-client-simplified PRIVATE ${Boost_INCLUDE_DIRS})

# Link Boost libraries to your executable
target_link_libraries(ethereum-client-simplified PRIVATE ${Boost_LIBRARIES} fmt::fmt "-fsanitize=address")


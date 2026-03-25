cmake_minimum_required(VERSION 3.25)

project(fluid-sim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/build/${CMAKE_BUILD_TYPE}/generators")

include(FetchContent)

FetchContent_Declare(
	gl-renderer
	GIT_REPOSITORY https://github.com/anazli/gl-renderer.git
	GIT_TAG        main
)
FetchContent_MakeAvailable(gl-renderer)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/fluid_simulation.h
	src/fluid_simulation.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    gl-renderer
)


# Find Boost
find_package(Boost REQUIRED COMPONENTS filesystem system thread)

# Find SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/deps/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
if(WIN32)
	find_package(SFML 2 REQUIRED COMPONENTS audio graphics network system window main)
else()
	find_package(SFML 2 REQUIRED COMPONENTS audio graphics network system window)
endif()

# Building with Clang on OSX requires -stdlib=libc++ flag
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	if(APPLE)
		set(CMAKE_CXX_FLAGS "-stdlib=libc++ ${CMAKE_CXX_FLAGS}")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
	endif()
endif()

# Options
include(CMakeDependentOption)

# Divvy out work to subdirectories
add_subdirectory("client/")
add_subdirectory("common/")
add_subdirectory("server/")

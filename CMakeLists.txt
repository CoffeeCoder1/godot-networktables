cmake_minimum_required(VERSION 3.10)
project(godot-networktables)

###############################################################################
# options
###############################################################################

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# build universal binaries on macos
if(APPLE)
  set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "" FORCE)
endif()

###############################################################################
# libs
###############################################################################

# ntcore

set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "Don't build WPILib shared libraries" FORCE)
set(WITH_CSCORE OFF CACHE INTERNAL "Disable WPILib cscore functionality" FORCE)
set(WITH_GUI OFF CACHE INTERNAL "Disable WPILib GUI functionality" FORCE)
set(WITH_SIMULATION_MODULES OFF CACHE INTERNAL "Disable WPILib simulation functionality" FORCE)
set(WITH_TESTS OFF CACHE INTERNAL "Disable WPILib unit test functionality" FORCE)
set(WITH_WPILIB OFF CACHE INTERNAL "Disable WPILib HAL and wpilibc/j functionality" FORCE)
set(WITH_WPIMATH OFF CACHE INTERNAL "Disable WPILib math functionality" FORCE)
set(WITH_PROTOBUF OFF CACHE INTERNAL "Disable WPILib protobuf functionality" FORCE)

add_subdirectory(lib/allwpilib)

# godot-cpp

set(GODOTCPP_DISABLE_EXCEPTIONS OFF CACHE INTERNAL "Enable Godot CPP exceptions" FORCE)

add_subdirectory(lib/godot-cpp)

###############################################################################

# install build into example project by default
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(
		CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/project/addons/networktables/bin"
		CACHE PATH "..."
	FORCE)
endif()

# let's us link depended dlls relative to process on linux
set(CMAKE_INSTALL_RPATH "$ORIGIN")

add_library(
	godot-nt4
	SHARED
		src/register_types.cpp
		src/networktableinstance.cpp
		src/topic/networktabletopic.cpp
		src/topic/networktablesubscriber.cpp
		src/topic/networktablepublisher.cpp
		src/topic/networktablegenericsubscriber.cpp
		src/topic/networktablegenericpublisher.cpp
)

target_link_libraries(
	godot-nt4
	PRIVATE
		godot-cpp
		wpiutil
		ntcore
)


set_target_properties(
	godot-nt4
	PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON
)

install(TARGETS godot-nt4 DESTINATION .)

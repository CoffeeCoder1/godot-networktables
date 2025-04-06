cmake_minimum_required(VERSION 3.10)
project(godot-networktables)

set(WITH_CSCORE OFF CACHE INTERNAL "Disable WPILib cscore functionality" FORCE)
set(WITH_GUI OFF CACHE INTERNAL "Disable WPILib GUI functionality" FORCE)
set(WITH_SIMULATION_MODULES OFF CACHE INTERNAL "Disable WPILib simulation functionality" FORCE)
set(WITH_TESTS OFF CACHE INTERNAL "Disable WPILib unit test functionality" FORCE)
set(WITH_WPILIB OFF CACHE INTERNAL "Disable WPILib HAL and wpilibc/j functionality" FORCE)
set(WITH_WPIMATH OFF CACHE INTERNAL "Disable WPILib math functionality" FORCE)
set(WITH_PROTOBUF OFF CACHE INTERNAL "Disable WPILib protobuf functionality" FORCE)

add_subdirectory(lib/allwpilib)

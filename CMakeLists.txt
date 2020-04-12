cmake_minimum_required( VERSION 3.0 )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( RobotSimulation )

get_filename_component( CINDER_PATH "/home/gortium/Software/Cinder" ABSOLUTE )
get_filename_component( APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE )

include( "${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake" )

set( PROJECT_SOURCES src/RobotSimulationApp.cpp )

# add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

ci_make_app(
	APP_NAME    "RobotSimulationApp"
	#BLOCKS		Cinder-ImGui
	CINDER_PATH ${CINDER_PATH}
	SOURCES     ${PROJECT_SOURCES}
	# INCLUDES    ${APP_PATH}/include
	# RESOURCES   ${APP_PATH}/resources/cinder_app_icon.ico
)
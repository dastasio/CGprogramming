cmake_minimum_required( VERSION 3.0)
project( CGprog)
set( EXEC_NAME "turtle")
set( SRC_lib "${PROJECT_SOURCE_DIR}/lib")
set( CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
set( SRC_exec main.cpp)

find_package( OpenGL REQUIRED)
find_package( GLUT REQUIRED)
find_package( GLEW REQUIRED)

add_subdirectory( ${SRC_lib})
add_executable( ${EXEC_NAME} ${SRC_exec})

target_link_libraries( ${EXEC_NAME} my_lib ${OPENG_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
include_directories( ${EXEC_NAME} ${SRC_lib} ${OPENG_INCLUDE_DIRS}
					${GLUT_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})


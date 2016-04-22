cmake_minimum_required(VERSION 2.8)
find_package(Boost 1.50.0 COMPONENTS python REQUIRED)
find_package(VTK REQUIRED)
if (VTK_FOUND)
    add_definitions(-DHAVE_VTK)
endif(VTK_FOUND)

find_package(PythonLibs REQUIRED)

#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wno-deprecated -std=c++0x -fopenmp -D_GLIBCXX_PARALLEL")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wno-deprecated -std=c++0x")
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wno-deprecated -std=c++0x -ftemplate-backtrace-limit=0")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")

include_directories(${VTK_INCLUDE_DIRS} ${Boost_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS} Aboria/src)

PYTHON_ADD_MODULE (init python.cpp init.cpp)
TARGET_LINK_LIBRARIES(init ${PYTHON_LIBRARIES} ${VTK_LIBRARIES} ${Boost_LIBRARIES})

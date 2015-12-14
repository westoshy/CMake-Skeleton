CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT(template_project)
set(LIBRARY_NAME mylib)



#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/cotire/CMake)
#include(cotire)
if(WIN32)
  set(OpenCV_DIR "C:/Dev/opencv3.0/build/install/")
  # set(VTK_DIR "C:/Dev/PCL-1.7.2/3rdParty/VTK/lib/cmake/vtk-6.2/")
  # set(PCL_DIR "C:/Dev/PCL-1.7.2/cmake")
endif()
# find_package(VTK REQUIRED)
# find_package(PCL 1.7.2  REQUIRED)
# find_package(OpenCV REQUIRED)

# set(THIRD_PARTY_LIBRARIES
#   ${OpenCV_LIBS}
# 

# configure file header
configure_file(
  "${CMAKE_SOURCE_DIR}/cmake/config.h.in" 
  "${CMAKE_SOURCE_DIR}/modules/mylib/config.h"
)
# build batch file
configure_file(
  "${CMAKE_SOURCE_DIR}/cmake/build.bat.in" 
  "${CMAKE_SOURCE_DIR}/build/build.bat"
)
# install batch file
configure_file(
  "${CMAKE_SOURCE_DIR}/cmake/install.bat.in" 
  "${CMAKE_SOURCE_DIR}/build/install.bat"
)

# message(${OpenCV_LIBS})
message(STATUS ${CMAKE_SOURCE_DIR})
message(STATUS ${CMAKE_CURRENT_LIST_DIR})

# Select Compiler 
if(WIN32)
  set(CMAKE_CXX_COMPILER "Visual Studio 12" CACHE STRING compiler)
elseif(UNIX)
  set(CMAKE_CXX_COMPILER "clang++-3.5")
  add_definitions("-std=c++11")
endif(WIN32)


# copy and install data files 
file(GLOB_RECURSE DATA_FILES 
  RELATIVE ${PROJECT_SOURCE_DIR}/data
  ${PROJECT_SOURCE_DIR}/data/*)
foreach(DATA_FILE ${DATA_FILES})
  configure_file(
    ${PROJECT_SOURCE_DIR}/data/${DATA_FILE}
    ${CMAKE_CURRENT_BINARY_DIR}/bin/data/${DATA_FILE} COPYONLY)
  #message(${CMAKE_CURRENT_BINARY_DIR})
  get_filename_component(DIRNAME ${DATA_FILE} DIRECTORY)
  install(FILES ${PROJECT_SOURCE_DIR}/data/${DATA_FILE}
    DESTINATION data/${DIRNAME})
  message(${DATA_FILE})
endforeach()


set(STATIC_LIBS
  mylib_hoge
  mylib_fuga
)

file(GLOB SUB_DIRECTORIES "bin/*" "modules/mylib/*")
message("===== Taget programs and modules =====")
foreach(DIR ${SUB_DIRECTORIES})
  if(IS_DIRECTORY "${DIR}")
    message(${DIR})
    add_subdirectory(${DIR})
  endif()
endforeach(DIR ${SUB_DIRECTORIES})
message("======================================")

# Source Code


# Set location of installation
# Use "sudo make install" to apply this installation in Linux or
# Build "INSTALL" project in Visual Studio
if(UNIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local/" CACHE STRING installer)
elseif(WIN32)
  set(CMAKE_INSTALL_PREFIX "C:/Dev/${LIBRARY_NAME}" CACHE STRING installer)
  # install(TARGETS piyo DESTINATION bin)
endif()

# install configure file header
set(CONFIG_HEADER ${PROJECT_SOURCE_DIR}/modules/mylib/config.h)
install (FILES ${CONFIG_HEADER} DESTINATION "include/${LIBRARY_NAME}")

# file(GLOB DATA_FILES ${PROJECT_SOURCE_DIR}/data/*)
# install(FILES ${DATA_FILES} DESTINATION data)

message("This project will be installed at ${CMAKE_INSTALL_PREFIX}")
# version require
cmake_minimum_required (VERSION 2.6)

# set project name
project (test_prj)

# Set project version number.
set (test_prj_VERSION_MAJOR 1)
set (test_prj_VERSION_MINOR 0)

# Set Debug or Release
# ======================================
# set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug") 

# set output position
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Lib/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Lib/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

# set link directory
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG})

# ==========================================
# Macro define Part
# should we use our own math functions?
option (USE_MYMATH 
        "Use tutorial provided math implementation" ON)

# ========================================
# Add 3rd lib. \\ for example: MatchFunctions
# Sub project's CMake must be put into subdir of main CMakeLists.txt

if(USE_MYMATH)
include_directories(../MathFunctions)
add_subdirectory(MathFunctions)

# set macro define EXTRA_LIBS
set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

endif (USE_MYMATH)
# ===========================================
# header part: Configuration header file
# Add include path to search path
include_directories(../header)


# ============================================
# src part:
# all source code
# aux_source_directory("${PROJECT_SOURCE_DIR}/../src" src)
#----------------------------------
# Required: Add all source code to Target project
add_executable(test_prj 
	../header/header.h
	../src/main.cpp 
	../src/src.cpp
	)


target_link_libraries (test_prj ${EXTRA_LIBS})

#----------------------------------
# One dir multi-files, may be write like that.
# aux_source_directory(../src DIR_SRCS)
# add_executable(test_prj ${DIR_SRCS})
#----------------------------------

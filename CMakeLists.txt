# version require
cmake_minimum_required (VERSION 2.6)

# set project name
project (test_prj)

# Set project version number.
set (test_prj_VERSION_MAJOR 1)
set (test_prj_VERSION_MINOR 0)

# ==========================================
# Macro define Part
# should we use our own math functions?
option (USE_MYMATH 
        "Use tutorial provided math implementation" ON)

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
#----------------------------------
# One dir multi-files, may be write like that.
# aux_source_directory(../src DIR_SRCS)
# add_executable(test_prj ${DIR_SRCS})
#----------------------------------

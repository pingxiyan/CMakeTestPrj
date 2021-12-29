cmake_minimum_required(VERSION 3.2)
cmake_policy(VERSION 3.2)

set(TARGET_NAME testprj)

project(${TARGET_NAME})

# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories
include_directories(./)

ADD_DEFINITIONS(-DIMPLEMENT_API)
add_library(${TARGET_NAME}_mylib SHARED mylib.cpp mylib.h)

if (${CMAKE_INSTALL_PREFIX})
	SET(OUTPUT_DIR ${CMAKE_INSTALL_PREFIX})
else ()
	SET(OUTPUT_DIR ${CMAKE_BINARY_DIR})
endif ()

install(TARGETS ${TARGET_NAME}_mylib
	CONFIGURATIONS Release
	RUNTIME DESTINATION ${OUTPUT_DIR}/Release/install/lib
	)
install(FILES mylib.h CONFIGURATIONS Release DESTINATION ${OUTPUT_DIR}/Release/install/include)


# Target
add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME} ${TARGET_NAME}_mylib)


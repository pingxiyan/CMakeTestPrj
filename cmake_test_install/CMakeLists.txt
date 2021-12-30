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

# Install binaries path.
MESSAGE("**********************************")
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE INTERNAL "export CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}" FORCE)
	MESSAGE("Don't pass CMAKE_INSTALL_PREFIX")
endif ()
MESSAGE("Install CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
MESSAGE("**********************************")

install(TARGETS ${TARGET_NAME}_mylib
	CONFIGURATIONS Release
	DESTINATION bin
	COMPONENT bins
	)
install(FILES mylib.h CONFIGURATIONS Release DESTINATION include COMPONENT includes)

# Target
add_executable(${TARGET_NAME} main.cpp)
target_link_libraries(${TARGET_NAME} ${TARGET_NAME}_mylib)
install(TARGETS ${TARGET_NAME}
	CONFIGURATIONS Release
	DESTINATION bin
	COMPONENT bins
	)

# CPack
# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "testprj_install")

set(CPACK_PACKAGE_VENDOR "LIMUTECT")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyLib - CPack Component Installation Example")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Testprj")

set(CPACK_COMPONENTS_ALL includes bins)
set(CPACK_COMPONENT_INCLUDES_DISPLAY_NAME "Include files folder")
set(CPACK_COMPONENT_BINS_DISPLAY_NAME "Binaries folder")

set(CPACK_COMPONENT_INCLUDES_DESCRIPTION "Save all include files, default ignore.")
set(CPACK_COMPONENT_BINS_DESCRIPTION "Save all excutable and libraries.")

include(CPack)
# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
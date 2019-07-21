cmake_minimum_required (VERSION 2.6)
project (Clab-midi)
set (Clab-midi_VERSION_MAJOR 0)
set (Clab-midi_VERSION_MINOR 1)
set (DEST_DIR "${CMAKE_INSTALL_PREFIX}")
set (prefix "${DEST_DIR}")
set (exec_prefix "${prefix}")
set (libdir "${prefix}/lib")
set (PACKAGE_NAME "${CMAKE_PROJECT_NAME}")
set (PACKAGE_VERSION "${Clab-midi_VERSION_MAJOR}.${Clab-midi_VERSION_MINOR}")
set (API_VERSION "${Clab-midi_VERSION_MAJOR}")
set (includedir "${prefix}/include")

configure_file(
	"${PROJECT_SOURCE_DIR}/src/config.h.in"
	"${PROJECT_BINARY_DIR}/src/config.h"
	)
configure_file(
	"${PROJECT_SOURCE_DIR}/Clab-midi.pc.in"
	"${PROJECT_BINARY_DIR}/Clab-midi-${API_VERSION}.pc"
	@ONLY
	)
configure_file(
	"${PROJECT_SOURCE_DIR}/src/Clab-midi.h.in"
	"${PROJECT_BINARY_DIR}/src/Clab-midi.h"
	@ONLY
	)
include_directories("${PROJECT_BINARY_DIR}/src")

#include_directories (src)
find_package (PkgConfig REQUIRED)
pkg_check_modules(Clab REQUIRED Clab-0)
pkg_check_modules(RtMidi REQUIRED rtmidi)

add_library(Clab-midi SHARED src/MidiOut.cpp src/Clab-midi.cpp)
set_target_properties(Clab-midi PROPERTIES OUTPUT_NAME "${CMAKE_PROJECT_NAME}-${API_VERSION}")
set_target_properties(Clab-midi PROPERTIES SOVERSION "${PACKAGE_VERSION}")
target_link_libraries(Clab-midi ${Clab_LIBRARIES} ${RtMidi_LIBRARIES})
target_include_directories(Clab-midi PUBLIC ${Clab_INCLUDE_DIRS} ${RtMidi_INCLUDE_DIRS})
target_compile_options(Clab-midi PUBLIC ${Clab_CFLAGS_OTHER} ${RtMidi_CFLAGS_OTHER})

add_executable(clabtest EXCLUDE_FROM_ALL src/main.cpp)
target_link_libraries(clabtest Clab-midi)

install(TARGETS Clab-midi LIBRARY DESTINATION lib)
install(FILES ${PROJECT_BINARY_DIR}/src/Clab-midi.h src/MidiOut.h src/Manager.h DESTINATION include/Clab-${API_VERSION})
install(FILES "${PROJECT_BINARY_DIR}/Clab-midi-${API_VERSION}.pc" DESTINATION lib/pkgconfig)

set(CPACK_PACKAGE_VERSION ${PACKAGE_VERSION})
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "jmb")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")
include(CPack)

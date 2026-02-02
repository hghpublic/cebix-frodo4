cmake_minimum_required(VERSION 3.30)

project(frodo
    VERSION 4.5.0
    HOMEPAGE_URL https://frodo.cebix.net/
    DESCRIPTION "Frodo is a portable Commodore 64 emulator that runs on a variety of platforms."
    LANGUAGES CXX
)

# build options

option(BUILD_FRODO "Build Frodo app." ON)
# if using valgrind, set BUILD_WITH_ASAN to OFF
option(BUILD_WITH_ASAN "Build with ASAN" OFF)

# frodo target

if(BUILD_FRODO)
set(target Frodo)
else()
set(target FrodoLite)
endif()

add_executable(${target})
target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/dev/configure/include")

set(FRODO_INSTALL_DIR "$ENV{WORKSPACE_ROOT}/dev/install")
target_compile_definitions(${target} PRIVATE
    -DHAVE_CONFIG_H
    -DFRODO_SC
    -DDATADIR="${FRODO_INSTALL_DIR}/Frodo/"
    -DHTMLDIR="${FRODO_INSTALL_DIR}/doc/Frodo/"
    -D_REENTRANT 
    -DPREFPATH="${FRODO_INSTALL_DIR}/Frodo/"
)
target_compile_features(${target} PRIVATE cxx_std_26)
target_link_options(${target} PRIVATE -rdynamic)

# dependencies

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE SDL2::SDL2)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk+-3.0)
target_link_libraries(${target} PRIVATE PkgConfig::GTK)
pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0)
target_link_libraries(${target} PRIVATE PkgConfig::GLIB)

# sanitizer or valgrind

if(BUILD_WITH_ASAN)
target_compile_options(${target} PRIVATE -fsanitize=address)
target_link_options(${target} PRIVATE -fsanitize=address)
endif()

set(VALGRIND_DIR "$ENV{WORKSPACE_ROOT}/dev/valgrind")
add_custom_target(valgrind
    COMMAND valgrind
        --leak-check=full
        --show-leak-kinds=all
        --track-origins=yes
        -s --suppressions=${VALGRIND_DIR}/frodo.valgrind.supp
        --gen-suppressions=all
        --log-file=${VALGRIND_DIR}/logs/memcheck.log
        $<TARGET_FILE:${target}>
    DEPENDS ${target}
    WORKING_DIRECTORY $<TARGET_FILE_DIR:${target}>
    COMMENT "Running Frodo with valgrind"
)

add_subdirectory(src)

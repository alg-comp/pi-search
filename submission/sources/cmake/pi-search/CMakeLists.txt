# CMakeList.txt : CMake project for pi-search, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("pi-search")

# Add source to this project's executable.
add_executable (pi-search "pi-search.cpp" "pi-search.h" "generate-pi.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pi-search PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
find_package(PkgConfig REQUIRED)
pkg_check_modules(gmpxx REQUIRED IMPORTED_TARGET gmpxx)
target_link_libraries(pi-search PkgConfig::gmpxx)

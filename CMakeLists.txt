cmake_minimum_required(VERSION 3.14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(monsun VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Werror")

find_package(Doxygen)
option(BUILD_DOCS "Create and install documentation (requires doxygen)" ${DOXYGEN_FOUND})
option(BUILD_TESTS "Build tests (requires Google Test)" ${GTest_FOUND})

if(BUILD_DOCS)
  if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen is needed to build the documentation")
  endif()

  set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doc/docgen)
  set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

  configure_file(${doxyfile_in} ${doxyfile} @ONLY)
  message("Building documentations...")

  add_custom_target(doc
    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_in}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)
endif()

configure_file(monsun.h.in monsun.h)

add_executable(${PROJECT_NAME} src/main.cpp)
add_subdirectory(lib)

if(BUILD_TESTS)
  if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test is needed to build tests")
  endif()

  enable_testing()
  add_subdirectory(test)
endif()

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_BINARY_DIR}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    lib
)

target_link_directories(${PROJECT_NAME}
  PRIVATE
    lib
)

target_link_libraries(${PROJECT_NAME} customer linkedlist)

# cmake --install
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/monsun.h" DESTINATION include)

# cpack
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${olas_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${olas_VERSION_MINOR}")
include(CPack)

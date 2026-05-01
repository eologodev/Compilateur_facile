cmake_minimum_required(VERSION 3.0)
project(facile VERSION 1.0.0 LANGUAGES C)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

flex_target(
  FACILE_SCANNER
  facile.lex
  "${CMAKE_CURRENT_BINARY_DIR}/facile.lex.c"
)

bison_target(
  FACILE_PARSER
  facile.y
  "${CMAKE_CURRENT_BINARY_DIR}/facile.y.c"
)

add_flex_bison_dependency(FACILE_SCANNER FACILE_PARSER)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB2 REQUIRED glib-2.0)

add_executable(
  facile
  ${FLEX_FACILE_SCANNER_OUTPUTS}
  ${BISON_FACILE_PARSER_OUTPUTS}
)

target_include_directories(facile PRIVATE ${GLIB2_INCLUDE_DIRS})
target_link_directories(facile PRIVATE ${GLIB2_LIBRARY_DIRS})
target_compile_options(facile PRIVATE ${GLIB2_CFLAGS_OTHER})
target_link_libraries(facile fl ${GLIB2_LIBRARIES})


set(CPACK_SOURCE_IGNORE_FILES "build;$;${CPACK_SOURCE_IGNORE_FILES}")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)

include(FetchContent)

# Remove unnecessary build files
# and steps from GTest's CMake
option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(TrigramParserTest TrigramParserTests.cpp)

target_link_libraries(TrigramParserTest
 PRIVATE
  GTest::GTest
  TrigramParser)

add_test(trigram_parser_gtests TrigramParserTest)

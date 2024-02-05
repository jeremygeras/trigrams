add_executable(TrigramParserApp main.cpp)

add_subdirectory(TrigramParser)

target_link_libraries(TrigramParserApp
 PRIVATE
  TrigramParser)

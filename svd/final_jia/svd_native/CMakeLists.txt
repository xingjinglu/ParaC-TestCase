cmake_minimum_required(VERSION 2.8)

file(GLOB cl_list "${CMAKE_CURRENT_SOURCE_DIR}/svd.cl" )

file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/kernels.cpp "// This file is auto-generated. Do not edit!
")

foreach(cl ${cl_list})
  get_filename_component(cl_filename "${cl}" NAME_WE)
  #message("${cl_filename}")

  file(READ "${cl}" lines)

  string(REPLACE "\r" "" lines "${lines}\n")
  string(REPLACE "\t" "  " lines "${lines}")


  string(REGEX REPLACE "[ ]*//[^\n]*\n"                 "\n" lines "${lines}") # single-line comments
  string(REGEX REPLACE "/\\*([^*]/|\\*[^/]|[^*/])*\\*/" ""   lines "${lines}") # multiline comments
  #  string(REGEX REPLACE "\n[ ]*(\n[ ]*)*"                "\n" lines "${lines}") # empty lines & leading whitespace
  string(REGEX REPLACE "^\n"                            ""   lines "${lines}") # leading new line

  string(REPLACE "\\" "\\\\" lines "${lines}")
  string(REPLACE "\"" "\\\"" lines "${lines}")
  string(REPLACE "\n" "\\n\"\n\"" lines "${lines}")

  string(REGEX REPLACE "\"$" "" lines "${lines}") # unneeded " at the eof

  file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/kernels.cpp "const char* ${cl_filename}=\"${lines};\n")
endforeach()

file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/kernels.cpp "")

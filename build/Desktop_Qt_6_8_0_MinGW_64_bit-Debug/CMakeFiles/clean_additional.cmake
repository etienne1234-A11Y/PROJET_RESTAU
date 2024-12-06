# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\resto_projet_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\resto_projet_autogen.dir\\ParseCache.txt"
  "resto_projet_autogen"
  )
endif()

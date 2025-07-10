# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HuffmanCompressorGUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HuffmanCompressorGUI_autogen.dir\\ParseCache.txt"
  "HuffmanCompressorGUI_autogen"
  )
endif()

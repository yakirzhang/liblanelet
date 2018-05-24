aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE_FILES)
add_library(liblanelet STATIC ${SOURCE_FILES})
target_include_directories(liblanelet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

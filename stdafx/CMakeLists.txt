set(CMAKE_CXX_STANDARD 17)

set(LIB_SOURCES stdafx.cpp)

set(LIB_HEADERS stdafx.hpp)

find_package(Boost REQUIRED)

add_library(stdafx STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_precompile_headers(
    stdafx PUBLIC ${CMAKE_SOURCE_DIR}/stdafx/stdafx.hpp
)

target_link_libraries(stdafx PUBLIC Boost::boost)

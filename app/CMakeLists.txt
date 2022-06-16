cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
)

add_executable(FileSignatureGenerator
    ${PROJECT_SOURCES}
)

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )

target_link_libraries(FileSignatureGenerator LINK_PUBLIC ${Boost_LIBRARIES})
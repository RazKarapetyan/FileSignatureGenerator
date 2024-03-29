cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_HEADERS
        Prototypes.hpp
        FileSignatureGenerator.hpp
        exception/Exception.hpp
        exception/InvalidBlockSizeException.hpp
        exception/BadFileException.hpp
        fileUtils/FileUtils.hpp
        commandLineUtils/CommandLineUtils.hpp
        hash/IHash.hpp
        hash/CrcHash.hpp)

set(PROJECT_SOURCES 
        main.cpp
        FileSignatureGenerator.cpp
        exception/InvalidBlockSizeException.cpp
        exception/BadFileException.cpp
        fileUtils/FileUtils.cpp
        commandLineUtils/CommandLineUtils.cpp
        hash/CrcHash.cpp)

add_executable(FileSignatureGenerator
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

find_package(Boost COMPONENTS program_options filesystem REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )

target_include_directories(FileSignatureGenerator PUBLIC ${CMAKE_SOURCE_DIR}/stdafx)

target_link_libraries(FileSignatureGenerator LINK_PUBLIC ${Boost_LIBRARIES} stdafx)

target_precompile_headers(FileSignatureGenerator REUSE_FROM stdafx)

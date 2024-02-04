cmake_minimum_required(VERSION 3.21)

project(hatsuki)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    src/main.cpp
    src/commands.cpp
    src/commands/nya_c.cpp
    src/core/sqlite.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC 
     dpp
     spdlog::spdlog
     sqlite3
)
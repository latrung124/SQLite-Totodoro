cmake_minimum_required(VERSION 3.22)
project(sqlite-example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DSOURCE_DIR="${CMAKE_SOURCE_DIR}/Database")

set(SOURCES
    Connection/IDatabaseConnection.h
    Connection/SQLiteConnection.cpp
    Connection/SQLiteConnection.h

    Repository/IUserRepository.h
    Repository/UserRepository.cpp
    Repository/UserRepository.h

    DataStructure/User.h

    main.cpp
)

find_package(SQLiteCpp REQUIRED)

add_executable(sqlite-example ${SOURCES})

target_include_directories(sqlite-example PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(sqlite-example PRIVATE
    SQLiteCpp)
cmake_minimum_required(VERSION 3.14)
project(StudentManagmentSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(Drogon REQUIRED)

# --- Console App ---
add_executable(StudentManagmentSystem
    main.cpp
    globals.cpp
)

target_link_libraries(StudentManagmentSystem
    PRIVATE
    Drogon::Drogon
    jsoncpp
)

# --- Web Server App ---
add_executable(StudentWebServer
    WebServer.cpp
    globals.cpp
)

target_link_libraries(StudentWebServer
    PRIVATE
    Drogon::Drogon
    jsoncpp
)





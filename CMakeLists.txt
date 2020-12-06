cmake_minimum_required(VERSION 3.16.3)
project(server VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Pistache 0.0.2 REQUIRED)
add_executable(server 
    src/main.cpp
    )
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries( server PUBLIC pistache_shared)
add_custom_target(run
    COMMAND ./server
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
# sudo add-apt-repository ppa:pistache+team/stable
# sudo apt update
# sudo apt install libpistache-dev
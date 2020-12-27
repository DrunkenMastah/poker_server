cmake_minimum_required(VERSION 3.16.3)
project(server VERSION 0.1.0)
find_program(CCACHE_FOUND ccache)
add_compile_options(-fdiagnostics-color=always)
if(CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) # Less useful to do it for linking, see edit2
endif(CCACHE_FOUND)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMA pKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Pistache 0.0.2 REQUIRED)
add_executable(server 
    src/main.cpp
    )
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries( server PRIVATE 
    pistache_shared
    Threads::Threads
)
add_custom_target(run

    COMMAND ./server
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

# sudo add-apt-repository ppa:pistache+team/stable
# sudo apt update
# sudo apt install libpistache-dev

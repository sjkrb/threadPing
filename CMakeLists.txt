cmake_minimum_required(VERSION 3.5)

project(threadPing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(threadPing main.cpp
    ping.h)

include(GNUInstallDirs)
install(TARGETS threadPing
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

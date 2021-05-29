cmake_minimum_required(VERSION 3.17)
project(minitalk C)

set(CMAKE_C_STANDARD 99)


include_directories(libft)


add_executable(minitalk
        server/server.c
#        client/client.c
        )

link_directories(libft/)
target_link_libraries(minitalk ${CMAKE_SOURCE_DIR}/libft/libft.a)

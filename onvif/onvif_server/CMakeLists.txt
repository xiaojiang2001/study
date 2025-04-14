cmake_minimum_required(VERSION 3.10)

project(onvif_server C)

set(CMAKE_C_STANDARD 99)

# 编译器选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# 包含头文件路径
include_directories(
                    ${CMAKE_CURRENT_SOURCE_DIR}/soap
                    ${CMAKE_CURRENT_SOURCE_DIR}/onvif
                )

# 源文件列表
set(SOURCES 
              ${CMAKE_CURRENT_SOURCE_DIR}/main.c        
              ${CMAKE_CURRENT_SOURCE_DIR}/soap/duration.c
              ${CMAKE_CURRENT_SOURCE_DIR}/soap/soapC.c
              ${CMAKE_CURRENT_SOURCE_DIR}/soap/soapClient.c
              ${CMAKE_CURRENT_SOURCE_DIR}/soap/soapServer.c
              ${CMAKE_CURRENT_SOURCE_DIR}/soap/stdsoap2.c

              ${CMAKE_CURRENT_SOURCE_DIR}/server/onvif_server_interface.c
              ${CMAKE_CURRENT_SOURCE_DIR}/server/onvif_server.c
)


# 生成可执行文件
add_executable(onvif_server ${SOURCES})

# 链接系统所需库
target_link_libraries(onvif_server m pthread)

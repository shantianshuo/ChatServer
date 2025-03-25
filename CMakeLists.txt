cmake_minimum_required (VERSION 3.0)
project (chat)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #可执行文件输出路径
include_directories(${PROJECT_SOURCE_DIR}/include) #头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include/server)
include_directories(${PROJECT_SOURCE_DIR}/include/server/model)
include_directories(${PROJECT_SOURCE_DIR}/include/server/db)
include_directories(${PROJECT_SOURCE_DIR}/thirdparty)
add_subdirectory(src)#加载子目录 目标目录里也应该有CMakeLists.txt

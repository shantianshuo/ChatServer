aux_source_directory(. SRC_LIST) #定义变量SRC_LIST，包括了当前路径的所有cpp文件
aux_source_directory(./db DB_LIST) #子文件目录的cpp也要编译，保存在另一个变量中
aux_source_directory(./model MODEL_LIST)
add_executable(ChatServer ${SRC_LIST} ${DB_LIST} ${MODEL_LIST})# 可执行文件的名字 + cpp文件路径。
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient pthread)#链接的库文件
# CMakeList.txt: Rocky.List.Helper 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。


# 读取 cxx文件和 头文件,  追加模式  到 srcs变量
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
#声明 类库, 将 相关文件 ,借助变量 添加类库中
add_library(randomList STATIC ${srcs})  
#目标头文件路径  该类库需要用到的头文件
target_include_directories(randomList PUBLIC include)
# TODO: 如有需要，请添加测试并安装目标。

#----------------- 链接 类库 ---------------
target_link_libraries(randomList PUBLIC tutorial_compiler_flags)



#----------------------Message-----------------
message(STATUS ------------- randomList  CMakeLists message-------------------------)
message(STATUS  srcs ---- ${srcs})
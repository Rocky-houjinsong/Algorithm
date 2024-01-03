# CMakeList.txt: Rocky.List.Helper 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#if (CMAKE_VERSION VERSION_GREATER 3.12)
 # set_property(TARGET Rocky.List.Helper PROPERTY CXX_STANDARD 20)
#endif()


# 读取 cxx文件和 头文件,  追加模式  到 srcs变量
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cxx include/*.h)
#声明 类库, 将 相关文件 ,借助变量 添加类库中
add_library(randomList STATIC ${srcs})  
#目标头文件路径  该类库需要用到的头文件
target_include_directories(randomList INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
# TODO: 如有需要，请添加测试并安装目标。

#----------------- 链接 类库 ---------------
target_link_libraries(randomList PUBLIC tutorial_compiler_flags)
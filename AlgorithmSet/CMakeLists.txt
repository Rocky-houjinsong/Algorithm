# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#--------------------------------基础设置 -------------------------------------
# 设置CMAKE 最小版本为 3.20
cmake_minimum_required (VERSION 3.20)
# 声明 该项目 为  <算法集合> 版本为 0.1
project (AlgorithmSet VERSION 0.1)
#-----------------------------------编译器设置 -------------------------------
# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
#设置编译模式 - 发布模式
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
#--------------------------类库子文件夹声明(类库使用)-------------------
add_subdirectory(randomList)



#----------------------------- 类库添加 --------------------------------
#虚拟接口库 -- 启用C++标准/特性 使用
add_library(tutorial_compiler_flags INTERFACE) 
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)


#-----------------------------类库链接 -----------------------------

target_link_libraries(AlgorithmSet PUBLIC randomList tutorial_compiler_flags)


#----------------------- 项目直接引用的头文件添加 -------------------

#模板文件 对应的头文件所在路径
target_include_directories(AlgorithmSet PUBLIC "${PROJECT_BINARY_DIR}")

#---------------------------模板文件 -----------------------------------
#借助模板文件 CXX 可读取 CMake文件变量
configure_file(TutorialConfig.h.in TutorialConfig.h)

#----------------可执行程序 -----------------------
add_executable(AlgorithmSet tutorial.cxx)

# 包含子项目。
add_subdirectory ("Rocky.List.Helper")

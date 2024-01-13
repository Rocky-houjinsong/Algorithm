# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#--------------------------------00基础设置 -------------------------------------
# 设置CMAKE 最小版本为 3.20
cmake_minimum_required (VERSION 3.20)
# 声明 该项目 为  <算法集合> 版本为 0.1
# --$$: C++语言, 版本为 2.1
project (Demo LANGUAGES CXX VERSION 2.1 )

#可执行程序 
add_executable(Demo tutorial.cpp)
set_target_properties(Demo PROPERTIES LINKER_LANGUAGE CXX)

#-----------------------------------01编译器设置 -------------------------------
# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


#----Clang tidy 设置
if(CMAKE_VERSION VERSION_GREATER 3.6)
    # Add clang-tidy if available
    option(CLANG_TIDY_FIX "Perform fixes for Clang-Tidy" OFF)
    find_program(
        CLANG_TIDY_EXE
        NAMES "clang-tidy"
        DOC "Path to clang-tidy executable"
    )

    if(CLANG_TIDY_EXE)
        if(CLANG_TIDY_FIX)
            set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}" "-fix")
        else()
            set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
        endif()
    endif()
endif()
#----------end 

#设置编译模式 - 发布模式
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
#Specify MSVC UTF-8 encoding   添加以下两行 做UTF8编译
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

#--------------------C++ 特性/标准启用
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_MODULE_PATH}")

#为了跨平台关闭GCC扩展语法
set(CMAKE_CXX_EXTENSIONS OFF)
#----导入脚本---
include(MyUsefulFuncs)

#--------------------------02 类库子文件夹声明(类库使用)-------------------
add_subdirectory(randomList)

#----------------------------- 类库添加 --------------------------------
#虚拟接口库 -- 启用C++标准/特性 使用
add_library(tutorial_compiler_flags INTERFACE) 
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)


#-----------------------------类库链接 -----------------------------
# tutorial_compiler_flags
target_link_libraries(Demo PUBLIC randomList tutorial_compiler_flags )


#----------------------- 项目直接引用的头文件添加 -------------------

#模板文件 对应的头文件所在路径

target_include_directories(Demo PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          ${srcs}
                          )

#---------------------------03 模板文件 -----------------------------------
#借助模板文件 CXX 可读取 CMake文件变量
configure_file(TutorialConfig.h.in TutorialConfig.h)





#----------------------------------  生成阶段 变量查看----------------------
message(STATUS -------------顶级CMakeLists message-------------------------)
message(STATUS Cmake Install_Dir ----------------"${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "${Tutorial_VERSION_MAJOR}")
message(STATUS "${Tutorial_VERSION_MINOR}")
message(STATUS  srcs ---- "${srcs}")
message(STATUS Project BINARY_DIR   -----------------"${PROJECT_BINARY_DIR}")
message(STATUS CMAKE_BUILD_TYPE   -----------------"${CMAKE_BUILD_TYPE}")



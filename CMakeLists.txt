cmake_minimum_required(VERSION 3.10)
project(CMakeProjectTemplate)

set(CMAKE_CXX_STANDARD 17)

# 设置默认值（如果用户未通过命令行指定构建系统的版本的话）
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 添加 include 路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加 `src` 目录下的所有 .cpp 和 .c 文件（不包含子目录）
file(GLOB SOURCES 	
	"src/*.cpp" )
add_executable(${PROJECT_NAME} ${SOURCES})

# 启用项目的测试功能，允许后续使用 add_test() 命令。
enable_testing()
# 加载子目录 tests/ 中的 CMakeLists.txt，将其作为子项目构建。
add_subdirectory(tests)

# 创建静态库目标（）
add_library(lib_linkedStack STATIC
    package/stack/linked_stack.cpp
)
# 使用lib_linkedStack的项目会自动包含下面目录中的头文件
target_include_directories(lib_linkedStack PUBLIC 
	package/stack)
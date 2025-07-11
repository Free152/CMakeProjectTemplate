# 查找并加载 Google Test 的 CMake 配置文件。
find_package(GTest CONFIG REQUIRED)

set(TestName "GoogleTestTemplate")

# 添加测试用例代码
add_executable(${TestName}
       package/stack/test_linked_stack.cpp)

# 链接自定义静态库和谷歌测试库
target_link_libraries(${TestName} PRIVATE
       lib_linkedStack
       GTest::gtest_main)

# 自动发现测试
include(GoogleTest)
gtest_discover_tests(${TestName})

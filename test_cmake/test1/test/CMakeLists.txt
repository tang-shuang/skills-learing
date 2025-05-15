add_executable(test_add test_add.cpp)
target_link_libraries(test_add mylib)

# 向CTest注册测试
add_test(NAME TestAdd COMMAND test_add)


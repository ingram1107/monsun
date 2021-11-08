set(This gtest)
set(Tests
  test.cpp
  testCustomer.cpp
  testLinkedList.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest")

add_executable(${This}
  ${Tests})

target_link_libraries(${This}
  PRIVATE
    gtest_main
    customer
    linkedlist
)

include(GoogleTest)
gtest_discover_tests(${This})

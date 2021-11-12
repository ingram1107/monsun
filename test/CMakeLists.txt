set(This unit_test)
set(Tests
  test.cpp
  testPerson.cpp
  testLinkedList.cpp
)

if(GTest_FOUND)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest")
endif()

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

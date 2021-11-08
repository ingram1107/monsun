add_library(customer Customer.cpp)
add_library(linkedlist LinkedList.cpp)

target_include_directories(customer
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(linkedlist
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

install(TARGETS customer DESTINATION lib)
install(FILES Customer.hpp DESTINATION include)
install(TARGETS linkedlist DESTINATION lib)
install(FILES LinkedList.hpp DESTINATION include)

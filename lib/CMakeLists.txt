function(includeUserLib libName libFile)
  add_library(${libName} ${libFile})
  target_include_directories(${libName}
    PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}
  )
  install(TARGETS ${libName} DESTINATION lib)
  install(FILES ${libFile} DESTINATION include)
endfunction()

includeUserLib(customer Customer.cpp)
includeUserLib(linkedlist LinkedList.cpp)

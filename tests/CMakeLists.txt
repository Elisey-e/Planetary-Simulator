add_executable(test_function ./src/test_function.cpp)


# install(TARGETS test_function
#         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#         COMPONENT test_function)



install(TARGETS test_function
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

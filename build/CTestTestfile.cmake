# CMake generated Testfile for 
# Source directory: /home/vlad/vsCode/GoogleTest/-Google_Test_C-
# Build directory: /home/vlad/vsCode/GoogleTest/-Google_Test_C-/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test1 "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/build/test1_app")
set_tests_properties(Test1 PROPERTIES  _BACKTRACE_TRIPLES "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;29;add_test;/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;0;")
add_test(Test2 "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/build/test2_app")
set_tests_properties(Test2 PROPERTIES  _BACKTRACE_TRIPLES "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;30;add_test;/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;0;")
add_test(Test3 "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/build/test3_app")
set_tests_properties(Test3 PROPERTIES  _BACKTRACE_TRIPLES "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;31;add_test;/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;0;")
add_test(Test4 "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/build/test4_app")
set_tests_properties(Test4 PROPERTIES  _BACKTRACE_TRIPLES "/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;32;add_test;/home/vlad/vsCode/GoogleTest/-Google_Test_C-/CMakeLists.txt;0;")
subdirs("lib/googletest")

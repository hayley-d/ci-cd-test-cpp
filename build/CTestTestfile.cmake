# CMake generated Testfile for 
# Source directory: /home/hayley/Downloads/Gridlock-Gurus-main
# Build directory: /home/hayley/Downloads/Gridlock-Gurus-main/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(all_tests "/home/hayley/Downloads/Gridlock-Gurus-main/build/tests")
set_tests_properties(all_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/hayley/Downloads/Gridlock-Gurus-main/CMakeLists.txt;32;add_test;/home/hayley/Downloads/Gridlock-Gurus-main/CMakeLists.txt;0;")
subdirs("googletest")

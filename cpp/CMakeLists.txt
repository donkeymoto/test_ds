cmake_minimum_required(VERSION 3.22)

project(test_proj)

#set(CMAKE_C_COMPILER   "/usr/bin/x86_64-w64-mingw32-gcc")
#set(CMAKE_CXX_COMPILER "/usr/bin/x86_64-w64-mingw32-g++")

#set(CMAKE_C_COMPILER   "x86_64-w64-mingw32-gcc")
#set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")

set(CMAKE_BUILD_TYPE "Debug")
set (CMAKE_CXX_FLAGS "-lstdc++fs -std=c++17")
message("Build type: ${CMAKE_BUILD_TYPE} ----")


execute_process(COMMAND uname -o OUTPUT_VARIABLE OS) 
message("Current OS is: ${OS}")
message("Current SYS is: ${CMAKE_SYSTEM_NAME}")

message("before: ASAN is ${ASAN}")
option(ASAN  "Enalbe asan")
message("after: ASAN is ${ASAN}")
message("laaaa is ${LAAAA}")

if (ASAN)
	message("Asan is ON ----")
endif()


#add_subdirectory(cppunit)
add_executable(coremask core_map.cpp)
add_executable(hex hex.cpp)
add_executable(for_loop for_loop.cpp)
add_executable(string_test string.cpp)
add_executable(thread_test thread_test.cpp)
target_link_libraries(thread_test PRIVATE pthread)
add_executable(vector_test vector.cpp)
add_executable(std_move_test std.move.cpp)
add_executable(singleton_test singleton_test.cpp)
add_executable(err_print err_print.cpp)
add_executable(fstream fstream_test.cpp)
add_executable(bitset bitmask.cpp)
add_executable(va_args va_args.cpp)
add_subdirectory(lib_test)
add_subdirectory(name_space)
add_executable(tls tls.cpp)
target_link_libraries(tls PRIVATE pthread)
add_executable(coredump coredump.cpp)
add_executable(callconvention call_convention.cpp)
add_executable(printer printer.cpp printer_user.cpp)

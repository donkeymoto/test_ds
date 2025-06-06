#set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")
set(target_name cppunit_test)
add_executable(${target_name})
target_sources(${target_name} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/course.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/student.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test_student.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/main_test_student.cpp)

#target_include_directories(${target_name} PRIVATE ${CMAKE_CXX_COMPILER})
target_link_libraries(${target_name} cppunit)

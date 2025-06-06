add_library(printb STATIC printb.cpp)

add_library(printa SHARED printa.cpp)
target_link_libraries(printa PRIVATE printb)


#add_library(mainlib SHARED main.c other.c)
add_executable(lib_test main.cpp other.cpp)
target_link_libraries(lib_test printa pthread)


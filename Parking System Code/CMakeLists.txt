cmake_minimum_required(VERSION 3.22)

set(headers Parking)
set(source Vehicle)
# Locate GTest
find_package(GTest REQUIRED)

 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(a.out Vehicle.cpp Parking.cpp tests.cpp)
target_link_libraries(a.out ${GTEST_LIBRARIES})

enable_testing()
add_test(add a.out)

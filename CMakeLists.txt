cmake_minimum_required(VERSION 3.30)
project(OpenCV_Lern VERSION 0.1.0 LANGUAGES C CXX)

# Найти OpenCV
find_package(OpenCV REQUIRED)

# Включить директории OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.cpp)



include(CTest)
enable_testing()

# Слинковать библиотеки OpenCV
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

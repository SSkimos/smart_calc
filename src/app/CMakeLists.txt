cmake_minimum_required(VERSION 3.5)
project(HelloWorld)
 
set(CMAKE_CXX_STANDARD 17)
set(Qt5Core_DIR /usr/local/opt/homebrew/Cellar/qt/6.4.0/lib/cmake/Qt6Core)

# Include a library search using find_package() 
# via REQUIRED, specify that libraries are required
find_package(Qt6Core REQUIRED)
find_package(Qt6Gui REQUIRED)
find_package(Qt6Widgets REQUIRED)
 
set(SOURCE_FILES main.cpp)
add_executable(HelloWorld ${SOURCE_FILES})
 
# specify which libraries to connect
target_link_libraries(${PROJECT_NAME} Qt6::Core)
target_link_libraries(${PROJECT_NAME} Qt6::Gui)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)

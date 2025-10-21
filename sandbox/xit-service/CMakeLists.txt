project(sandbox_xit_service)

find_package(nil-clix CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE nil::service)
target_link_libraries(${PROJECT_NAME} PRIVATE nil::clix)
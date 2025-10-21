project(sandbox_service)

find_package(nil-clix CONFIG REQUIRED)
find_package(nil-service CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE nil::service)
target_link_libraries(${PROJECT_NAME} PRIVATE nil::clix)

nil_install_targets(${PROJECT_NAME})

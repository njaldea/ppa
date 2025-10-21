project(sandbox_xit_gtest)

find_package(nil-xit-test CONFIG REQUIRED COMPONENTS gtest)
find_package(nlohmann_json CONFIG REQUIRED)

# Create the test executable with sources and GUI target
add_xit_test(
    ${PROJECT_NAME}
    SOURCES
        main.cpp
        frame_setup.hpp
        userland_utils.cpp
        userland_utils.hpp
    GROUPS
        "xit=${CMAKE_CURRENT_SOURCE_DIR}/gui"
        "base=${CMAKE_CURRENT_SOURCE_DIR}/gui"
        "test=${CMAKE_CURRENT_SOURCE_DIR}/files"
)

target_link_libraries(${PROJECT_NAME} PRIVATE nil::xit-gtest)

nil_install_targets(${PROJECT_NAME})
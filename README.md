This is a sample repo where all of the dependencies are installed using apt.

1. add nil-ppa to apt

```shell
echo "deb [trusted=yes] https://njaldea.github.io/ppa ./" | sudo tee /etc/apt/sources.list.d/njaldea.list
```

2. update apt

```shell
sudo apt update
```

3. install dependencies

```shell
sudo apt install [package]
```

4. add to your target dependencies

```shell
nil-clix provides CMake targets:

  find_package(nil-clix CONFIG REQUIRED)
  target_link_libraries(main PRIVATE nil::clix)

nil-xalt provides CMake targets:

  find_package(nil-xalt CONFIG REQUIRED)
  target_link_libraries(main PRIVATE nil::xalt)

nil-service provides CMake targets:

    find_package(nil-service CONFIG REQUIRED)
    target_link_libraries(TARGET PUBLIC nil::service)

    # for nil::service_ssl
    find_package(nil-service CONFIG REQUIRED COMPONENTS ssl)
    target_link_libraries(TARGET PUBLIC nil::service-ssl)


nil-xit provides CMake targets:

  find_package(nil-xit CONFIG REQUIRED)
  target_link_libraries(main PRIVATE nil::xit)

nil-gate provides CMake targets:

    find_package(nil-gate CONFIG REQUIRED)
    target_link_libraries(TARGET PUBLIC nil::gate)

    # for nil::gate-c-api
    find_package(nil-gate CONFIG REQUIRED COMPONENTS c-api)
    target_link_libraries(TARGET PUBLIC nil::gate-c-api)


nil-xit-test provides CMake targets:

    find_package(nil-xit-test CONFIG REQUIRED)
    target_link_libraries(TARGET PUBLIC nil::xit-test)

    # for nil::xit-gtest
    find_package(nil-xit-test CONFIG REQUIRED COMPONENTS gtest)

    # register a test
    add_xit_test(
        TARGET
        SOURCES
            <your files...>
        GROUPS
            <key=value...>
    )
    target_link_libraries(TARGET PUBLIC nil::xit-gtest)
```
if (TARGET tinyusb_device)
    add_executable(blinkSerial
            blinkSerial.c
            )

# pull in common dependencies
target_link_libraries(blinkSerial
    pico_stdlib  # for core functionality
    pico_cyw43_arch_lwip_threadsafe_background  # we need Wifi to access the GPIO, but we don't need anything else
    )

pico_enable_stdio_usb(blinkSerial 1)
pico_enable_stdio_uart(blinkSerial 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(blinkSerial)

target_include_directories(blinkSerial PRIVATE ${CMAKE_CURRENT_LIST_DIR} )


elseif(PICO_ON_DEVICE)
    message(WARNING "not building blinkSerial because TinyUSB submodule is not initialized in the SDK")
endif()

if (TARGET tinyusb_device)
    add_executable(blinkSerial
            blinkSerial.c
            )

    # pull in common dependencies
    target_link_libraries(blinkSerial pico_stdlib)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(blinkSerial 1)
    pico_enable_stdio_uart(blinkSerial 0)

    # create map/bin/hex file etc.
    pico_add_extra_outputs(blinkSerial)

    #add url via pico_set_program_url
    example_auto_set_url(blinkSerial)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building blinkSerial because TinyUSB submodule is not initialized in the SDK")
endif()

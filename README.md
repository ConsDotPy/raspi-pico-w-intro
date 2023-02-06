# Raspberry Pi Pico W Setup
Testing Raspberry Pi Pico W. Blinking LED and enabling serial USB communication.

## Blinking LED
First, RP2040 has to be flashed with simple blinking LED plus sending "Hello, World!" by serial communication.

![Raspberry Pi Pico W Pinout](images/PicoW-A4-Pinout-1.jpg)

## Debugger
Setting up debugger helps to understand what's inside RP2040. Allows to flash it without BOOTSEL button.

![Working Debugger, make things easier.](images/debugSetup.png)

## GitHub Actions
Test with GitHub Actions were done. Now releases are done automatically as pushes to branch "master" keep coming.
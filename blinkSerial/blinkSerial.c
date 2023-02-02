/**
 * @file blinkSerial.c
 * @author AdCon (ad_con.reload@protonmail.ch)
 * @brief Simple test for Raspberry Pi Pico W. Blink LED plus Serial Comm.
 * @version 0.1
 * @date 2023-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include <stdio.h>
 #include "pico/stdlib.h"
 #include "pico/binary_info.h"

 const uint LED_PIN = 22;

 int main() 
 {
    stdio_init_all();
    bi_decl(bi_program_description("New Serial Blink"));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-Board LED"));
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while(true)
    {
        gpio_put(LED_PIN, 1);
        printf("Hello, ");
        sleep_ms(1000);
        gpio_put(LED_PIN, 0);
        printf("World!\n");
        sleep_ms(1000);
    }
 }
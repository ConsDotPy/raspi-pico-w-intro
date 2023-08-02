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
    bi_decl(bi_program_description("New Serial Blink"));
    bi_decl(bi_1pin_with_name(LED_PIN, "ProtoBoard LED"));
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while(true)
    {
        gpio_put(LED_PIN, 1);
        printf("Hello, "); // DevSkim: ignore DS154189
        sleep_ms(100);
        gpio_put(LED_PIN, 0);
        printf("World!\n"); // DevSkim: ignore DS154189
        sleep_ms(100);
    }
 }
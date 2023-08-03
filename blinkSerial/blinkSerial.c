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
#include "pico/cyw43_arch.h"

const uint LED_PIN = 22;

char ssid[] = "AdCon";
char password[] = "Constante123";

int main() 
{
    bi_decl(bi_program_description("New Serial Blink"));
    bi_decl(bi_1pin_with_name(LED_PIN, "ProtoBoard LED"));
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    if(cyw43_arch_init_with_country(CYW43_COUNTRY_MEXICO)){
        printf("Failed to init WiFi\n"); // DevSkim: ignore DS154189
        return 1;
    }
    printf("Connecting to %s\n", ssid); // DevSkim: ignore DS154189
    cyw43_arch_enable_sta_mode();
    if (cyw43_arch_wifi_connect_timeout_ms(ssid, password, CYW43_AUTH_WPA2_AES_PSK, 10000))
    {
        printf("Failed to connect\n"); // DevSkim: ignore DS154189
        return 1;
    }
    printf("Connected\n"); // DevSkim: ignore DS154189
    while(true)
    {
        gpio_put(LED_PIN, 1);
        printf("Hello, "); // DevSkim: ignore DS154189
        sleep_ms(100); // DevSkim: ignore DS154189
        gpio_put(LED_PIN, 0);
        printf("World!\n"); // DevSkim: ignore DS154189
        sleep_ms(100);
    }
}
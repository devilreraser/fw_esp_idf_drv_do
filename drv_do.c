/* *****************************************************************************
 * File:   drv_do.c
 * Author: XX
 *
 * Created on YYYY MM DD
 * 
 * Description: ...
 * 
 **************************************************************************** */

/* *****************************************************************************
 * Header Includes
 **************************************************************************** */
#include "drv_do.h"
#include "cmd_do.h"

#include "driver/gpio.h"
#include "esp_log.h"

/* *****************************************************************************
 * Configuration Definitions
 **************************************************************************** */
#define TAG "drv_do"

/* *****************************************************************************
 * Constants and Macros Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Enumeration Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Type Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Function-Like Macros
 **************************************************************************** */

/* *****************************************************************************
 * Variables Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Prototype of functions definitions
 **************************************************************************** */

/* *****************************************************************************
 * Functions
 **************************************************************************** */
esp_err_t drv_do_pin_setup(drv_do_e_pin_t do_pin, gpio_num_t gpio_pin)
{
#if CONFIG_DRV_DO_USE_DYNAMIC_INITIALIZATION
    //to do dynamic pin initialization (table DO pin (drv_do_pin_t) <-> gpio pin num (gpio_num_t))
#endif
    return ESP_OK;
}

drv_do_e_pin_t drv_do_get_do_num(gpio_num_t gpio_pin)
{
    gpio_num_t do_pin;
    do_pin = GPIO_NUM_NC;
#if CONFIG_DRV_DO_USE_DYNAMIC_INITIALIZATION
    do_pin = (drv_do_e_pin_t)gpio_pin;  //for test - redirect directly to gpio pin
    //to do dynamic pin get (table DO pin (drv_do_pin_t) <-> gpio pin num (gpio_num_t))
#endif
    
    if (do_pin == GPIO_NUM_NC)
    {
        //to do get gpio from configuration
        if (gpio_pin == (gpio_num_t)DRV_DO_0_GPIO) do_pin = DRV_DO_0;
        if (gpio_pin == (gpio_num_t)DRV_DO_1_GPIO) do_pin = DRV_DO_1;
        if (gpio_pin == (gpio_num_t)DRV_DO_2_GPIO) do_pin = DRV_DO_2;
        if (gpio_pin == (gpio_num_t)DRV_DO_3_GPIO) do_pin = DRV_DO_3;
        if (gpio_pin == (gpio_num_t)DRV_DO_4_GPIO) do_pin = DRV_DO_4;
        if (gpio_pin == (gpio_num_t)DRV_DO_5_GPIO) do_pin = DRV_DO_5;
        if (gpio_pin == (gpio_num_t)DRV_DO_6_GPIO) do_pin = DRV_DO_6;
        if (gpio_pin == (gpio_num_t)DRV_DO_7_GPIO) do_pin = DRV_DO_7;
        if (gpio_pin == (gpio_num_t)DRV_DO_8_GPIO) do_pin = DRV_DO_8;
    }
    return do_pin;
}


gpio_num_t drv_do_get_gpio_num(drv_do_e_pin_t do_pin)
{
    gpio_num_t gpio_pin;
    gpio_pin = GPIO_NUM_NC;
    
#if CONFIG_DRV_DO_USE_DYNAMIC_INITIALIZATION
    gpio_pin = (gpio_num_t)do_pin;  //for test - redirect directly to gpio pin
    //to do dynamic pin get (table DO pin (drv_do_pin_t) <-> gpio pin num (gpio_num_t))
#endif

    if (gpio_pin == GPIO_NUM_NC)
    {
        //get gpio from configuration
        switch (do_pin)
        {
            case DRV_DO_0:
                gpio_pin = DRV_DO_0_GPIO;
                break;
            case DRV_DO_1:
                gpio_pin = DRV_DO_1_GPIO;
                break;
            case DRV_DO_2:
                gpio_pin = DRV_DO_2_GPIO;
                break;
            case DRV_DO_3:
                gpio_pin = DRV_DO_3_GPIO;
                break;
            case DRV_DO_4:
                gpio_pin = DRV_DO_4_GPIO;
                break;
            case DRV_DO_5:
                gpio_pin = DRV_DO_5_GPIO;
                break;
            case DRV_DO_6:
                gpio_pin = DRV_DO_6_GPIO;
                break;
            case DRV_DO_7:
                gpio_pin = DRV_DO_7_GPIO;
                break;
            case DRV_DO_8:
                gpio_pin = DRV_DO_8_GPIO;
                break;
            default:
                gpio_pin = GPIO_NUM_NC;
                break;
        }
    }
    return gpio_pin;
}

void drv_do_pin_init(drv_do_e_pin_t do_pin)
{
    gpio_num_t gpio_pin;
    gpio_pin = drv_do_get_gpio_num(do_pin);
    gpio_config_t io_config = 
    {
        .pin_bit_mask = (1ULL << gpio_pin),
    };
    gpio_config(&io_config);
    //gpio_pad_select_gpio(gpio_pin);
    gpio_set_direction(gpio_pin, GPIO_MODE_OUTPUT);
}

void drv_do_pin_set(drv_do_e_pin_t do_pin)
{
    gpio_num_t gpio_pin;
    gpio_pin = drv_do_get_gpio_num(do_pin);
    gpio_set_level(gpio_pin, 1);
    ESP_LOGI(TAG, "DO_%d=1 (GPIO_%d)", drv_do_get_do_num(gpio_pin), gpio_pin);
}

void drv_do_pin_clr(drv_do_e_pin_t do_pin)
{
    gpio_num_t gpio_pin;
    gpio_pin = drv_do_get_gpio_num(do_pin);
    gpio_set_level(gpio_pin, 0);
    ESP_LOGI(TAG, "DO_%d=0 (GPIO_%d)", drv_do_get_do_num(gpio_pin), gpio_pin);
}

void drv_do_init(void)
{
    cmd_do_register();
}

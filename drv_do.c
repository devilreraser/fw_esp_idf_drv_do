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
    //to do dynamic pin get (table DO pin (drv_do_pin_t) <-> gpio pin num (gpio_num_t))
#endif
    
    if (do_pin == GPIO_NUM_NC)
    {
        //to do get gpio from configuration
        if (gpio_pin == (gpio_num_t)DRV_DO_0) do_pin = 0;
        if (gpio_pin == (gpio_num_t)DRV_DO_1) do_pin = 1;
        if (gpio_pin == (gpio_num_t)DRV_DO_2) do_pin = 2;
        if (gpio_pin == (gpio_num_t)DRV_DO_3) do_pin = 3;
        if (gpio_pin == (gpio_num_t)DRV_DO_4) do_pin = 4;
        if (gpio_pin == (gpio_num_t)DRV_DO_5) do_pin = 5;
        if (gpio_pin == (gpio_num_t)DRV_DO_6) do_pin = 6;
        if (gpio_pin == (gpio_num_t)DRV_DO_7) do_pin = 7;
        if (gpio_pin == (gpio_num_t)DRV_DO_8) do_pin = 8;
    }
    return do_pin;
}



gpio_num_t drv_do_get_gpio_num(drv_do_e_pin_t do_pin)
{
    gpio_num_t gpio_pin;
#if CONFIG_DRV_DO_USE_DYNAMIC_INITIALIZATION
    gpio_pin = GPIO_NUM_NC;
    //to do dynamic pin get (table DO pin (drv_do_pin_t) <-> gpio pin num (gpio_num_t))
    
    if (gpio_pin == GPIO_NUM_NC)
    {
        //to do get gpio from configuration
        switch (do_pin)
        {
            case 0:
                gpio_pin = DRV_DO_0;
                break;
            case 1:
                gpio_pin = DRV_DO_1;
                break;
            case 2:
                gpio_pin = DRV_DO_2;
                break;
            case 3:
                gpio_pin = DRV_DO_3;
                break;
            case 4:
                gpio_pin = DRV_DO_4;
                break;
            case 5:
                gpio_pin = DRV_DO_5;
                break;
            case 6:
                gpio_pin = DRV_DO_6;
                break;
            case 7:
                gpio_pin = DRV_DO_7;
                break;
            case 8:
                gpio_pin = DRV_DO_8;
                break;
        }
    }
#else
    gpio_pin = (gpio_num_t)do_pin;
#endif
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

/* *****************************************************************************
 * File:   drv_do.h
 * Author: XX
 *
 * Created on YYYY MM DD
 * 
 * Description: ...
 * 
 **************************************************************************** */
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/* *****************************************************************************
 * Header Includes
 **************************************************************************** */
#include "sdkconfig.h"
    
#include "driver/gpio.h"

/* *****************************************************************************
 * Configuration Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Constants and Macros Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Enumeration Definitions
 **************************************************************************** */
typedef enum
{
    DRV_DO_0,
    DRV_DO_1,
    DRV_DO_2,
    DRV_DO_3,
    DRV_DO_4,
    DRV_DO_5,
    DRV_DO_6,
    DRV_DO_7,
    DRV_DO_8,
    DRV_DO_COUNT
}drv_do_e_pin_t;

typedef enum
{
    DRV_DO_0_GPIO = CONFIG_DRV_DO_PIN_0,
    DRV_DO_1_GPIO = CONFIG_DRV_DO_PIN_1,
    DRV_DO_2_GPIO = CONFIG_DRV_DO_PIN_2,
    DRV_DO_3_GPIO = CONFIG_DRV_DO_PIN_3,
    DRV_DO_4_GPIO = CONFIG_DRV_DO_PIN_4,
    DRV_DO_5_GPIO = CONFIG_DRV_DO_PIN_5,
    DRV_DO_6_GPIO = CONFIG_DRV_DO_PIN_6,
    DRV_DO_7_GPIO = CONFIG_DRV_DO_PIN_7,
    DRV_DO_8_GPIO = CONFIG_DRV_DO_PIN_8,
}drv_do_e_gpio_pin_t;

/* *****************************************************************************
 * Type Definitions
 **************************************************************************** */

/* *****************************************************************************
 * Function-Like Macro
 **************************************************************************** */

/* *****************************************************************************
 * Variables External Usage
 **************************************************************************** */ 

/* *****************************************************************************
 * Function Prototypes
 **************************************************************************** */
esp_err_t drv_do_pin_setup(drv_do_e_pin_t do_pin, gpio_num_t gpio_pin);
drv_do_e_pin_t drv_do_get_do_num(gpio_num_t gpio_pin);
gpio_num_t drv_do_get_gpio_num(drv_do_e_pin_t do_pin);
esp_err_t drv_do_pin_init(drv_do_e_pin_t do_pin);
void drv_do_pin_set(drv_do_e_pin_t do_pin);
void drv_do_pin_clr(drv_do_e_pin_t do_pin);
void drv_do_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */



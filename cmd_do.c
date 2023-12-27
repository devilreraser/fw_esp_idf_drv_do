/* *****************************************************************************
 * File:   cmd_do.c
 * Author: Dimitar Lilov
 *
 * Created on 2022 06 18
 * 
 * Description: ...
 * 
 **************************************************************************** */

/* *****************************************************************************
 * Header Includes
 **************************************************************************** */
#include "cmd_do.h"
#include "drv_do.h"

#include <string.h>

#include "esp_log.h"
#include "esp_console.h"
#include "esp_system.h"

#include "argtable3/argtable3.h"

/* *****************************************************************************
 * Configuration Definitions
 **************************************************************************** */
#define TAG "cmd_do"

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

static struct {
    struct arg_str *pin;
    struct arg_str *cmd;
    struct arg_end *end;
} do_args;


/* *****************************************************************************
 * Prototype of functions definitions
 **************************************************************************** */

/* *****************************************************************************
 * Functions
 **************************************************************************** */
static int command_do(int argc, char **argv)
{
    ESP_LOGI(__func__, "argc=%d", argc);
    for (int i = 0; i < argc; i++)
    {
        ESP_LOGI(__func__, "argv[%d]=%s", i, argv[i]);
    }

    int nerrors = arg_parse(argc, argv, (void **)&do_args);
    if (nerrors != ESP_OK)
    {
        arg_print_errors(stderr, do_args.end, argv[0]);
        return ESP_FAIL;
    }

    const char* do_number = do_args.pin->sval[0];

    drv_do_e_pin_t do_pin = atoi(do_number);
    ESP_LOGI(TAG, "do_pin=%d", do_pin);
    
    //int gpio_pin = drv_do_get_gpio_num_from_configuration(do_pin);
    //ESP_LOGI(TAG, "gpio_pin=%d", gpio_pin);

    const char* do_command = do_args.cmd->sval[0];

    if (strcmp(do_command,"set") == 0)
    {
        drv_do_pin_set(do_pin);
    }
    else if (strcmp(do_command,"clr") == 0)
    {
        drv_do_pin_clr(do_pin);
    }
    else
    {
        ESP_LOGE(TAG, "Unknown command %s", do_command);
        return ESP_FAIL;
    }
    return 0;
}

static void register_do(void)
{
    do_args.pin = arg_strn("p", "pin",      "<pin number>",         1, 1, "Specify pin number : do -p {0|1|2|3|4|5|6|7|8}");
    do_args.cmd = arg_strn("c", "command",  "<command>",            1, 1, "Command can be     : do -c {set|clr}");
    do_args.end = arg_end(2);

    const esp_console_cmd_t cmd_do = {
        .command = "do",
        .help = "DO Command Request",
        .hint = NULL,
        .func = &command_do,
        .argtable = &do_args,
    };

    //do_args.device->sval[0] = null_string_do;
    //do_args.ip->sval[0] = null_string_do;
    //do_args.mask->sval[0] = null_string_do;
    //do_args.gw->sval[0] = null_string_do;

    ESP_ERROR_CHECK(esp_console_cmd_register(&cmd_do));
}


void cmd_do_register(void)
{
    register_do();
}

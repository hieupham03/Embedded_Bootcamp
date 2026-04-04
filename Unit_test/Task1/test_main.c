#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cmd_line.h"
bool is_led_mock_called = false;
bool INFO_FLAG = false;

void mock_led_handler(char *argv[], uint8_t argc) {
    is_led_mock_called = true;
}

void mock_info_handler(char *argv[], uint8_t argc) {
    INFO_FLAG = true;
}
cmd_line_t cmd_table[] = {
    {"led", (pf_cmd_func)mock_led_handler, "LED command"},
    {"info", (pf_cmd_func)mock_info_handler, "Info command"},
    {NULL, NULL, NULL} 
};

int main() {
    char test_command1[] = "led on";
    char test_command2[] = "info ";
    cmd_line_parser(cmd_table, (uint8_t*)test_command1);
    if (is_led_mock_called) {
        printf("LED handler called successfully.\n");
    } else {
        printf("LED handler was not called.\n");
    }
    cmd_line_parser(cmd_table, (uint8_t*)test_command2);
    if (INFO_FLAG) {
        printf("Info handler called successfully.\n");
    } else {
        printf("Info handler was not called.\n");
    }
}
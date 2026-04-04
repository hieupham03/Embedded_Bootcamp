#ifndef CMD_LINE_MINE_H
#define CMD_LINE_MINE_H

#include <stdint.h>

typedef int32_t (*pf_cmd_func)(char *argv[], uint8_t argc);

typedef struct {
    const char *cmd;       
    pf_cmd_func func;     
    const char *help;  
} cmd_line_t;

void cmd_line_parse(char* raw_str);

#endif
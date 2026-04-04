#include "cmd_line_mine.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

extern const cmd_line_t cmd_table[];
extern const uint8_t cmd_table_size;

void tokenize_string(char* raw_str, char* argv[], uint8_t *argc) {
    *argc = 0; 

    char *token = strtok(raw_str, " \r\n");
    while (token != NULL && *argc < 10) { 
        argv[*argc] = token; 
        (*argc)++;    
        
        token = strtok(NULL, " \r\n");
    }
}

void cmd_line_parse(char* raw_str) {
    char* argv[10];
    uint8_t argc = 0;
    tokenize_string(raw_str, argv, &argc);

    if (argc == 0) {
        return; 
    }

    bool is_found = false;
    for (int i = 0; i < cmd_table_size; i++) {
        
        if (strcmp(argv[0], cmd_table[i].cmd) == 0) {
            cmd_table[i].func(argv, argc); 
            is_found = true;             
            break;                     
        }
        
    }
    if (is_found == false) {
        printf("[ERROR] Command '%s' not found!\n", argv[0]);
    }
}
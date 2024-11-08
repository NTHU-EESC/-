/* repl.c */
/* 2021-01-22T00:07:24+00:00 */
/* 108061112 */

#ifndef REPL_C
#define REPL_C

#include "repository.c"

uint8_t length(const uint8_t * string) /* a simple strlen() */
{
        uint8_t index = 0u;
        
        for (;;)
        {
                if (NULL == string[index])
                {
                        return index;
                }
                index++;
        }
}

uint8_t match(const uint8_t * string_1, const uint8_t * string_2)
{
        for (;;)
        {
                if (NULL == *string_1)
                {
                        return TRUE;
                }
                if (NULL == *string_2)
                {
                        return TRUE;
                }
                if (*string_1 != *string_2)
                {
                        return FALSE;
                }
                string_1++;
                string_2++;
        }
}

uint8_t eval(const uint8_t * command) /* parse input and access resources */
{
        if (NULL == *command)
        {
                return repo_no_command_supplied();
        }
        
        if (TRUE == match("help", command))
        {
                return repo_help_page();
        }
        
        if (TRUE == match("led", command))
        {
                return repo_led(command);
        }
        
        if (TRUE == match("prompt", command))
        {
                return repo_change_prompt();
        }
        
        if (TRUE == match("temperature", command))
        {
                return repo_temperature();
        }
        
        if (TRUE == match("math", command))
        {
                return repo_math();
        }
        
        if (TRUE == match("gyroscope", command))
        {
                return repo_gyroscope();
        }
        
        if (TRUE == match("accelerometer", command))
        {
                return repo_accelerometer();
        }
        
        return repo_unknown_command();
}

void repl(void) /* an interactive shell environment similar to LISP machine */
{
        OLED_Init();
        
        for (;;)
        {
                newline();
                print_string(prompt);
                read_line();
                eval(buffer + length(prompt));
        }
}

#endif /* REPL_C */
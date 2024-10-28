/* repository.c */
/* 2021-01-22T13:17:23+00:00 */
/* 108061112 */

#ifndef REPOSITORY_C
#define REPOSITORY_C

#include "io.c"

uint8_t repo_help_page(void)
{
        newline();
        print_string("help");
        newline();
        print_string("led");
        newline();
        print_string("prompt");
        newline();
        print_string("temperature");
        newline();
        print_string("math");
        newline();
        print_string("gyroscope");
        newline();
        print_string("accelerometer");
        return 0u;
}

uint8_t repo_no_command_supplied(void)
{
        newline();
        print_string("No command supplied.");
        newline();
        print_string("Type 'h' for help.");
        return 1u;
}

uint8_t repo_unknown_command(void)
{
        newline();
        print_string("Unknown command.");
        newline();
        print_string("Type 'h' for help.");
        return 1u;
}

uint8_t repo_led(const uint8_t * command)
{
        uint8_t io = NULL;
        
        if ((uint8_t) 'n' == command[7u])
        {
                io = 0u;
        }
        else if ((uint8_t) 'f' == command[7u])
        {
                io = 1u;
        }
        else
        {
                newline();
                print_string("led [0-7] [on/off]");
                return 1u;
        }
        
        switch (command[4u])
        {
                case '0':
                        P1_0 = io;
                        break;
                case '1':
                        P1_1 = io;
                        break;
                case '2':
                        P1_2 = io;
                        break;
                case '3':
                        P1_3 = io;
                        break;
                case '4':
                        P1_4 = io;
                        break;
                case '5':
                        P1_5 = io;
                        break;
                case '6':
                        P1_6 = io;
                        break;
                case '7':
                        P1_7 = io;
                        break;
                default:
                        newline();
                        print_string("led [0-7] [on|off]");
                        return 1u;
        }
        return 0u;
}

uint8_t repo_change_prompt(void)
{
        uint8_t index = OLED_CHAR_PER_PAGE;
        
        newline();
        print_string("Enter new prompt:");
        newline();
        read_line();
        
        while (index --> 0u)
        {
                prompt[index] = buffer[index];
        }
        return 0u;
}

uint8_t repo_temperature(void)
{
        uint16_t object_temperature = NULL;
        uint16_t ambient_temperature = NULL;
        
        newline();
        print_string("object:  ");
        object_temperature = (uint16_t) readTemp(OBJECT_TEMP);
        print_char('0' + object_temperature % 1000u / 100u);
        print_char('0' + object_temperature % 100u / 10u);
        print_char('.');
        print_char('0' + object_temperature % 10u / 1u);
        print_string(" ~C");
        
        newline();
        print_string("ambient: ");
        ambient_temperature = (uint16_t) readTemp(AMBIENT_TEMP);
        print_char('0' + ambient_temperature % 1000u / 100u);
        print_char('0' + ambient_temperature % 100u / 10u);
        print_char('.');
        print_char('0' + ambient_temperature % 10u / 1u);
        print_string(" ~C");
        
        return 0u;
}

uint8_t is_numeric(uint8_t character)
{
        return (((uint8_t) '0' <= character) &&
                ((uint8_t) '9' >= character));
}

void print_int32_t(int32_t number)
{
        int32_t power_of_ten = 1000000000u;
        uint8_t single_digit = NULL;
        if ((int32_t) 0 == number)
        {
                print_char('0');
                return;
        }
        if ((int32_t) 0 > number)
        {
                print_char('-');
                number *= (int32_t) -1;
        }
        while (0u == number / power_of_ten)
        {
                power_of_ten /= (int32_t) 10; /* find most significant digit */
        }
        while (0u != power_of_ten)
        {
                single_digit = number / power_of_ten % (int32_t) 10; /* cast */
                print_char((uint8_t) '0' + single_digit);
                power_of_ten /= (int32_t) 10;
        }
        return;
}

uint8_t repo_math(void)
{
        int32_t accumulator = 0u;
        
        for (;;)
        {
                uint8_t index = 0u;
                int32_t operand = 0u;
                
                newline();
                print_string("math> ");
                read_line();
                
                while (NULL != buffer[index]) /* parse unsigned part */ 
                {
                        if (is_numeric(buffer[index]))
                        {
                                operand *= (int32_t) 10u;
                                operand += buffer[index] - (uint8_t) '0';
                        }
                        index++;
                }
                
                while (index --> (uint8_t) 0u) /* parse minus sign */ 
                {
                        if ((uint8_t) '-' == buffer[index])
                        {
                                operand *= (int32_t) -1;
                        }
                }
                
                if ((uint8_t) '+' == buffer[6u])
                {
                        accumulator += operand;
                }
                else if ((uint8_t) '-' == buffer[6u])
                {
                        accumulator += operand; /* '-' already parsed earlier */
                }
                else if ((uint8_t) '*' == buffer[6u])
                {
                        accumulator *= operand;
                }
                else if ((uint8_t) '/' == buffer[6u])
                {
                        accumulator /= operand;
                }
                else if ((uint8_t) '%' == buffer[6u])
                {
                        accumulator %= operand;
                }
                else if ((uint8_t) '^' == buffer[6u])
                {
                        index = operand;
                        operand = accumulator;
                        while (index --> (uint8_t) 1u)
                        {
                                accumulator *= operand;
                        }
                }
                else if ((uint8_t) '!' == buffer[6u])
                {
                        index = (uint8_t) accumulator;
                        while (index --> (uint8_t) 1u)
                        {
                                accumulator *= (int32_t) index;
                        }
                }
                else if ((uint8_t) 'o' == buffer[6u])
                {
                        newline();
                        print_string("+ (addition)");
                        newline();
                        print_string("- (subtraction)");
                        newline();
                        print_string("* (multiplication)");
                        newline();
                        print_string("/ (division)");
                        newline();
                        print_string("% (modulo)");
                        newline();
                        print_string("^ (exponentiation)");
                        newline();
                        print_string("! (factorial)");
                }
                else if ((uint8_t) 'c' == buffer[6u])
                {
                        accumulator = 0u;
                }
                else if ((uint8_t) 'q' == buffer[6u])
                {
                        return 0u;
                }
                else if ((uint8_t) 'h' == buffer[6u])
                {
                        newline();
                        print_string("[operand]");
                        newline();
                        print_string("[operator] [operand]");
                        newline();
                        print_string("operator list");
                        newline();
                        print_string("clear");
                        newline();
                        print_string("quit");
                        newline();
                        print_string("help");
                }
                else if (NULL == buffer[6u])
                {
                        newline();
                        print_string("No command supplied.");
                        newline();
                        print_string("Type 'h' for help.");
                }
                else if ((int32_t) 0u != operand)
                {
                        accumulator = operand;
                }
                else
                {
                        newline();
                        print_string("Unknown command.");
                        newline();
                        print_string("Type 'h' for help.");
                }
                
                if ((int32_t) 0u != accumulator)
                {
                        newline();
                        print_string("      = ");
                        print_int32_t(accumulator);
                }
        }
}

void print_mpu6050(int * pointer, uint8_t axis)
{
        newline();
        print_char((uint8_t) 'X' + axis);
        print_string("-axis: ");
        print_int32_t((int32_t) pointer[axis]);
        return;
}

uint8_t repo_gyroscope(void)
{
        MPU6050_INIT();
        readMPU6050_GyroData(gyro_data);
        print_mpu6050(gyro_data, 0u);
        print_mpu6050(gyro_data, 1u);
        print_mpu6050(gyro_data, 2u);
        return 0u;
}

uint8_t repo_accelerometer(void)
{
        MPU6050_INIT();
        readMPU6050_AccelData(accel_data);
        print_mpu6050(accel_data, 0u);
        print_mpu6050(accel_data, 1u);
        print_mpu6050(accel_data, 2u);
        return 0u;
}

#endif /* REPOSITORY_C */
#include <stdio.h>
#include <stdlib.h>

void compiler(void);  //function declaration
void calculator(void);
int convert_character_to_hexadecimal(char x);
int convert_hexadecimal_to_character(char x,char y);
int error_detect_com(int a[],int x);
int error_detect_cal(int a[],int x);

int main(void)  //begin assignment
{
    int option;

    printf("Please enter a number for option (1 for compiler, 2 for calculator):");
    scanf("%d",&option);  //Let user enter a number to choose which function to operate.

    if(option==1){
        compiler();  //When user enters 1, the program executes compiler.
    }
    else if(option==2){
        calculator();  //When user enters 1, the program executes calculator.
    }
    else {
        printf("ERROR");  //When user enters numbers exclusive of 1 and 2, the program ends with printing ERROR.
    }

    return 0;  //end assignment
}

void compiler(void)  //compiler function
{
    char scan_result[100];
    int convert_result[100];
    int convert_result_line[100];
    int i,counter=1,line,error=0;
    int k=1;

    FILE *fptr;
    fptr = fopen("com_input1.txt","r");  //Open a file and set fptr as a pointer to read the file

    for(i=1;fscanf(fptr,"%c",&scan_result[i])!=EOF;i++){  //Keep scanning the characters of the file until the end of file(EOF)
        if(convert_character_to_hexadecimal(scan_result[i])!=20){  //change the format from character to integer by using "convert_character_to_hexadecimal function
           convert_result[k] = convert_character_to_hexadecimal(scan_result[i]);  //put the format in array scan_result to array convert_result with skipping space
           k++;  //add 1 to k for next input
       }
    }
    convert_result[k]=30;  //set the last format 30(\n)

    //Divide the format into several arrays, each of them represents one line.

    for(line=1;counter<k;line++){  //Keep increasing the value of line until the end of file
        for(i=1;convert_result[counter]!=30;i++){
            convert_result_line[i] = convert_result[counter];  //When the format is not 30(\n), put the format into the new array.
            counter++;
        }
        convert_result_line[i]=30;  //Set the last format of the new array 30(\n)

        if(error_detect_com(convert_result_line,i)==1){  //Execute error_detect function for the new array. If the function returns 1, print the error message and end the compiler.
            error++;
            printf("ERROR:LINE %d",line);
            break;
        }
        counter++;
    }

    if(error==0){  //If error_detect function return 0, print the result of compile.
        for(i=1;i<=k;i++){
            if(convert_result[i]!=30){
                printf("%.2X",convert_result[i]);
            }
        }
    }

    fclose(fptr);  //close the file

    //end compiler
}

void calculator(void)  //calculator function
{
    char scan_result[100];
    int convert_result[100];
    int i,j,length,line,start_of_line=1,line_error=0;

    FILE*fptr;
    fptr=fopen("cal_input1.txt","r");  //Open a file and set fptr as a pointer to read the file

    for(i=1;fscanf(fptr,"%c",&scan_result[i])!=EOF;i++){  //Keep scanning the characters of the file until the end of file(EOF)

    }


    for(length=1;length<=i/2;length++){
        convert_result[length]=convert_hexadecimal_to_character(scan_result[length*2-1],scan_result[length*2]);
        //take two formats and convert them to one integer format by using convert_hexadecimal_to_character function
        //store the formats in the new array
    }
    convert_result[length]=99;  //set the last format of the array 99

    //start error detecting

    if(error_detect_cal(convert_result,length)==1){
        printf("ERROR:LINE 1");
    }
    else if(error_detect_cal(convert_result,length)==2){
        printf("ERROR:LINE 2");
    }
    else if(error_detect_cal(convert_result,length)==3){
        printf("ERROR:LINE 3");
    }

    //If there is no error occurs, start calculate the format.

    else{
        for(line=1;line<=3;line++){
            for(i=start_of_line;convert_result[i]!=14;i++){
                //Execute multiplication and division first.
                if(convert_result[i]==12){
                    convert_result[i-1] = convert_result[i-1] * convert_result[i+1];
                    //When the format is 12(*), multiply the previous and the later number.
                    for(j=i;convert_result[j]!=99;j++){
                        convert_result[j]=convert_result[j+2];
                    }
                    //make the format left two characters forward
                    convert_result[j]=99;  //set the last format of the array 99
                    i--;
                }
                if(convert_result[i]==13){
                    if(convert_result[i+1]==0){  //If there is a number divided by 0, make line_error=1.
                        line_error++;
                        convert_result[i-1] = convert_result[i-1] + convert_result[i+1];
                        for(j=i;convert_result[j]!=99;j++){
                            convert_result[j]=convert_result[j+2];
                        }
                        convert_result[j]=99;
                        i--;
                    }
                    else{
                        convert_result[i-1] = convert_result[i-1] / convert_result[i+1];
                        //When the format is 13(/), divide the previous and the later number.
                        for(j=i;convert_result[j]!=99;j++){
                            convert_result[j]=convert_result[j+2];
                        }
                        //make the format left two characters forward
                        convert_result[j]=99;  //set the last format of the array 99
                        i--;
                    }
                }
            }
            //Execute addition and subtraction
            for(i=start_of_line;convert_result[i]!=14;i++){
                if(convert_result[i]==10){
                    convert_result[i-1] = convert_result[i-1] + convert_result[i+1];
                    //When the format is 10(+), add the previous and the later number.
                    for(j=i;convert_result[j]!=99;j++){
                        convert_result[j]=convert_result[j+2];
                    }
                    //make the format left two characters forward
                    convert_result[j]=99;   //set the last format of the array 99
                    i--;
                }
                if(convert_result[i]==11){
                    convert_result[i-1] = convert_result[i-1] - convert_result[i+1];
                    //When the format is 11(-), subtract the previous and the later number.
                    for(j=i;convert_result[j]!=99;j++){
                        convert_result[j]=convert_result[j+2];
                    }
                    //make the format left two characters forward
                    convert_result[j]=99;  //set the last format of the array 99
                    i--;
                }
            }

            if(convert_result[i]==14){  //By the time the program meets ";" :
                if(line_error!=0){
                    printf("ERROR\n");  //If the line has a number divided by 0, print error as the result.
                    line_error=0;
                }
                else{
                    printf("%d\n",convert_result[line*2-1]);  //If there is no error occurs, print the result of calculate.
                }
                start_of_line=i+1;
            }
        }
    }

    fclose(fptr);  //close the file

    //end calculator

}

int convert_character_to_hexadecimal(char x)  //function to convert number from character type to integer
{
    if(x=='0'){
        return 0;
    }
    else if(x=='1'){
        return 1;
    }
    else if(x=='2'){
        return 2;
    }
    else if(x=='3'){
        return 3;
    }
    else if(x=='4'){
        return 4;
    }
    else if(x=='5'){
        return 5;
    }
    else if(x=='6'){
        return 6;
    }
    else if(x=='7'){
        return 7;
    }
    else if(x=='8'){
        return 8;
    }
    else if(x=='9'){
        return 9;
    }
    else if(x=='+'){
        return 10;
    }
    else if(x=='-'){
        return 11;
    }
    else if(x=='*'){
        return 12;
    }
    else if(x=='/'){
        return 13;
    }
    else if(x==';'){
        return 14;
    }
    else if(x==' '){
        return 20;
    }
    else if(x=='\n'){
        return 30;
    }
    else return 99;
}

int convert_hexadecimal_to_character(char x,char y)  ////function to convert number from character type to integer
{
    if(x=='0' && y=='0'){
        return 0;
    }
    if(x=='0' && y=='1'){
        return 1;
    }
    if(x=='0' && y=='2'){
        return 2;
    }
    if(x=='0' && y=='3'){
        return 3;
    }
    if(x=='0' && y=='4'){
        return 4;
    }
    if(x=='0' && y=='5'){
        return 5;
    }
    if(x=='0' && y=='6'){
        return 6;
    }
    if(x=='0' && y=='7'){
        return 7;
    }
    if(x=='0' && y=='8'){
        return 8;
    }
    if(x=='0' && y=='9'){
        return 9;
    }
    if(x=='0' && y=='A'){
        return 10;
    }
    if(x=='0' && y=='B'){
        return 11;
    }
    if(x=='0' && y=='C'){
        return 12;
    }
    if(x=='0' && y=='D'){
        return 13;
    }
    if(x=='0' && y=='E'){
        return 14;
    }
    else return 15;
}

int error_detect_com(int a[],int x)  //function to detect whether error occurs in compiler
{
    int i,error=0,oper=0;

    for(i=1;i<x;i++){
        if(a[i]==10||a[i]==11||a[i]==12||a[i]==13||a[i]==14){
            if(a[i+1]==10||a[i+1]==11||a[i+1]==12||a[i+1]==13||a[i+1]==14){
                 error++;  //detect the situation of two continuous operators
                 break;
            }
        }
        if(a[1]==10||a[1]==11||a[1]==12||a[1]==13||a[1]==14){
            error++;  //detect operator at the beginning of the line
            break;
        }
        if(a[i+1]==30 && a[i]!=14){
            error++;  //detect the situation of no semicolon at the end of a line
            break;
        }
        if(a[i]==0||a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9){
            if(a[i+1]==0||a[i+1]==1||a[i+1]==2||a[i+1]==3||a[i+1]==4||a[i+1]==5||a[i+1]==6||a[i+1]==7||a[i+1]==8||a[i+1]==9){
                error++;  //detect the situation of two continuous numbers
                break;
            }
        }
        if(a[i]==10||a[i]==11||a[i]==12||a[i]==13){
            oper++;
        }
        if(a[i]==99){
            error++;  //detect the situation of not numbers or operators
        }
    }
    if(oper>=3){
        error++;  //detect the situation of more than two operators
    }

    if(error>=1){
        return 1;  //When error occurs, return value 1 to the compiler function.
    }
    else return 0;  //If there's no error, return value 0.
}

int error_detect_cal(int a[],int x)
{
    int i,line=1,error=0,oper=0;

    for(i=1;i<=x;i++){
        if(a[i]==10||a[i]==11||a[i]==12||a[i]==13||a[i]==14){
            if(a[i+1]==10||a[i+1]==11||a[i+1]==12||a[i+1]==13||a[i+1]==14){
                 error++;  //detect the situation of two continuous operators
                 break;
            }
        }
        if(a[1]==10||a[1]==11||a[1]==12||a[1]==13||a[1]==14){
            error++;  //detect operator at the beginning of the line
            break;
        }
        if(a[i]==0||a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9){
            if(a[i+1]==0||a[i+1]==1||a[i+1]==2||a[i+1]==3||a[i+1]==4||a[i+1]==5||a[i+1]==6||a[i+1]==7||a[i+1]==8||a[i+1]==9){
                error++;  //detect the situation of two continuous numbers
                break;
            }
        }
        if(a[i]==10||a[i]==11||a[i]==12||a[i]==13){
            oper++;
        }
        if(a[i]==15){
            error++;  //detect the situation of not numbers or operators
            break;
        }
        if(a[i]==14){
            if(oper>=3){
                error++;  //detect the situation of more than two operators
                break;
            }
            else{
                oper=0;
                line++;
            }
        }
    }

    if(error>=1){
        if(line==1) return 1;  //When error occurs, return value 1 to the compiler function.
        if(line==2) return 2;
        else return 3;
    }
    else return 0;  //If there's no error, return value 0.
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char **args = (char**)malloc(100*sizeof(char));
    char buff[100], input_string[100], letter;
    
    for(int i = 0; i < 100; i++){
        
        buff[i] = '\0';
        input_string[i] = '\0';
    }
    for(int i = 0; (letter = getchar())!='\n'; i++){
        input_string[i] = letter;
    }
    
    int args_num = 0;
    for(int i = 0, j = 0; i < 100;i++){
        
        if((input_string[i] == ' ')||(input_string[i]=='\0')){
            //reset j = 0
            j = 0;
            args[args_num] = malloc(strlen(buff+1));
            strcpy(args[args_num++],buff);
            for(int i = 0; i < 100; i++)buff[i] = '\0';
        }else buff[j++] = input_string[i];
        
    }    
    
    for(int i = 0; i < args_num; i++){
        printf("%s ",args[i]);
    }    
}

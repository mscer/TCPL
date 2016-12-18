#include <stdio.h>
#include <ctype.h>
#include <string.h>

double atof(char tmp[]);

int main()
{
    char * line = NULL;
    size_t len = 0;
    while(getline(&line,&len,stdin) != -1){
        if(line[0]=='q'){
            return 0;
        }
        double d_tmp = 0.0;
        d_tmp = atof(line);
        fprintf(stdout,"%s\tis\t%f",line,d_tmp);
    }
}

double atof(char tmp[])
{
    size_t len = strlen(tmp);
    size_t i = 0;
    //space
    for(;i<len &&isspace(tmp[i]);++i);
    //sign
    int sign = 1;
    if(tmp[i]=='-'){
        sign = -1;
        ++i;
    } 
    //int
    double sum = 0;
    for(;i<len&&isdigit(tmp[i]);++i){
       sum = sum*10+tmp[i]-'0';  
    }
    if(i<len&&tmp[i]=='.'){
        ++i; 
    }
    int power = 1;
    for(;i<len&&isdigit(tmp[i]);++i){
        sum = sum*10+tmp[i]-'0';
        power *= 10;
    }
    sum = power>0?sum/power:sum;
    sum *=sign;
    //exp
    if((i<len&&tmp[i]=='e')||(i<len&&tmp[i]=='E')){
        ++i; 
    }
    sign = 1;
    if(i<len&&tmp[i]=='-'){
        sign = -1; 
        ++i;
    }
    int exp = 0;
    for(;i<len&&isdigit(tmp[i]);++i){
        exp = exp*10+ tmp[i]-'0'; 
    }
    double base = sign==1?10:1.0/10;
    for(int j=0;j<exp;++j){
        sum = sum*base; 
    } 
    return sum;
    
}

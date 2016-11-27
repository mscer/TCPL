#include<stdio.h>

//宏定义
#define MAXSIZE 1000

//函数定义
int my_getLine(char line[],int length);
void reverse(char from[],char to[]);

int main(){
    char line[MAXSIZE];
    char temp[MAXSIZE];
    int length;
    while((length=my_getLine(line,MAXSIZE))!=0){
        if (length>0){
            printf("%s",line);
            reverse(line,temp);
            printf("%s",temp);
        } 
    }

}


//函数定义
int my_getLine(char line[],int length){
    int i=0;
    int c=0;
    for(;i<(length-1)&&(c=getchar())!=EOF;++i){
        line[i]=c;
        if ('\n'==c){
            break; 
        } 
    }
    line[++i]='\0';
    if(EOF==c){
        --i; 
    }
    return i;

}
void reverse(char from[],char to[]){
    int i=0;
    while(from[i]!='\n'){
        ++i; 
    }
    i--;
    for(int j=0;j<=i;j++){
        to[j]=from[i-j]; 
    }
    to[++i]='\n';
    to[++i]='\0';
}

#include<stdio.h>

//宏定义
#define MAXSIZE 1000
#define LIMIT 8

//函数声明
int my_getline(char line[],int length);
void copy(char from[],char to[]);


//main function
int main(){
    char line[MAXSIZE];
    int length=0;
    while((length=my_getline(line,MAXSIZE))!=0){
        if (length >LIMIT ){
            printf("%s",line);
        }
    }
    return 0;
}




//函数定义

int my_getline(char line[],int length){
    int c=0;
    int i=0;
    for (;i<(length-1) && (c=getchar())!=EOF ;i++){
        line[i]=c; 
        if ('\n'==c){
            break; 
        }
    }

    line[++i]='\0';
    if(c==EOF){
        i--; 
    }
    return i;
}

void copy(char from[],char to[]){
    int i=0;
    while((to[i]=from[i])!='\0'){
        i++; 
    }
}

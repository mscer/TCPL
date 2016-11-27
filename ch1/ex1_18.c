#include<stdio.h>

//宏定义
#define MAXSIZE 1000

//函数定义
int my_getLine(char line[],int length);
void copy(char from[],char to[]);
int filter_sent(char from[],char to[]);


int main(){
    
    char line[MAXSIZE],temp[MAXSIZE];
    int len=0;
    while((len=my_getLine(line,MAXSIZE))!=0){
        if (filter_sent(line,temp)>0){
            printf("%s",temp); 
        } 
    }
}


//函数实现
int my_getLine(char line[],int length){
    int i=0;
    int c=0;
    for(;(c=getchar())!=EOF &&i<(length-1);++i){
       line[i]=c;
       if('\n'==c){
            break; 
       }
    }
    line[++i]='\0';
    if(EOF==c){
       --i;  
    }
    return i;

}

void copy(char from[],char to[]){
    int i=0;
    while((to[i]=from[i])!='\0'){
        ++i; 
    }
}

int filter_sent(char from[],char to[]){
    int len=0;
    while(from[len]!='\0'){
        len++; 
    }
    int i=len-1;
    for (;i>=0;i--){
        if ('\n'==from[i] ||(' '==from[i])||('\t'==from[i])) {
            continue;
        }
        else{
            break;  
        }
    }    
    if(i<0){
        return -1; 
    }
    else{
        from[++i]='\0'; 
    }

    copy(from,to);
    return 1;
}

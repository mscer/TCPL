#include<stdio.h>

//宏定义
#define MAXSIZE 2

//函数声明
int my_getline(char line[],int length);
void copy(char from[],char to[]);


//main function
int main(){
    char line[MAXSIZE];
    char temp[MAXSIZE];
    int length=0,maxlen=0;
    while((length=my_getline(line,MAXSIZE))!=0){
        if (length >maxlen){
            maxlen=length;
            copy(line,temp); 
        }
    }

    if(maxlen>0){
        printf("%s",temp);
    }
    printf("max length is:%d",maxlen);
    return 0;
}




//函数定义

int my_getline(char line[],int length){
    int c=0;
    int i=0;
    /*
    for (;i<(length-1) && (c=getchar())!=EOF ;i++){
        line[i]=c; 
        if ('\n'==c){
            break; 
        }
    }
    */

   for(;(c=getchar())!=EOF;++i){
       if(i<length-1){
           line[i] =c;
       }  
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

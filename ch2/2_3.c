#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

//全局函数定义
int htoi(char* hex,int *res);

int main()
{
    char *hex = NULL;
    long unsigned int length;
    int res=0;
    while(getline(&hex,&length,stdin)!=-1){
        printf("inputs is :\t%s\n",hex);
        if(htoi(hex,&res))
            printf("input is :\t%d\n",res);
    }
    //free后的变量不能被继续使用
    free(hex);
}


//函数定义
int htoi(char* hex,int *res)
{
    int beg=0;
    //找到开始位置
    while(hex[beg]!='0'&& hex[beg]!='\0'&&hex[beg]!='\n'){
        beg++; 
    }
    if (hex[beg]=='\0' || '\n'==hex[beg]){
        return FALSE;
    }
    if(('0'!=hex[beg] &&'\0'!=hex[(beg+1)]\
            &&'x'!=hex[(beg+1)])){
       return FALSE; 
    }

    //转10进制
    *res = 0;
    for (int i=beg+2;hex[i]!='\0'&&hex[i]!='\n';++i){
        *res=(*res)*16+hex[i]-'0' ;
    }
    return TRUE;
}

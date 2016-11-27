#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE

//全局函数
void escape(char * s,char *t);

int main()
{
    char *sent=NULL;
    size_t len=0;
    while(-1 != getline(&sent,&len,stdin)){
        char * res=(char*)malloc(len+1); 
        escape(sent,res);
        fprintf(stdout,"original input is: %s\n",sent);
        fprintf(stdout,"result output is: %s\n",res);
    }


}




void escape(char * s,char *t)
{
    int tmp;
    int i=0,j=0;
    for (;s[i]!='\0';++i,++j){
        tmp = s[i];
        switch(tmp){
            case '\n':
                t[j] = '\\';
                t[++j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                t[++j] = 't';
                break;
            default :
                t[j] = tmp;
        }
    }
    t[j] = '\0';
    //todo
}

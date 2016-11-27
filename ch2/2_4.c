#include<stdio.h>
#include<stdlib.h>

//全局函数
void squeeze(char *s1,char*s2);


int main()
{
    char *s1=NULL;
    char *s2=NULL;
    long unsigned int len_s1=0,len_s2=0;

    //getline
    if (getline(&s1,&len_s1,stdin)==-1){
        return -1;
    }


    if (getline(&s2,&len_s2,stdin)==-1){
        return -1;
    }

    char *res=(char*)malloc(len_s1+len_s2+1);    
    free(res);
    squeeze(s1,s2);
    printf("sent1:%s\n",s1);
    printf("sent2:%s\n",s2);
}



void squeeze(char *s1,char*s2)
{
    int i=0,j=0,m=0;
    int occins2=0;
    for (;s1[i]!='\0';++i){
        for(m=0;s2[m]!='\0';++m){
            if (s1[i]==s2[m]){
                occins2 = 1;
                break;
            }
        } 
        if (0==occins2){
           s1[j++]=s1[i];
        }
    }
    s1[j]='\0';
}

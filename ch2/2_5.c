#include<stdio.h>

int any(char *s1,char *s2);

int main()
{
    char *s1=NULL,*s2=NULL;
    long unsigned int len_s1=0,len_s2=0;

    if(getline(&s1,&len_s1,stdin)==-1){
        return -1; 
    }

    if (getline(&s2,&len_s2,stdin)==-1){
        return -1; 
    }

    printf("first occu is %d\n",any(s1,s2));
}



int any(char *s1,char *s2)
{
    int i=0,j=0;
    for (;s1[i]!='\0';++i){
        for(j=0;s2[j]!='\0';++j){
            if (s1[i]==s2[j]){
                return i; 
            } 
        }
    }
    return -1;
}

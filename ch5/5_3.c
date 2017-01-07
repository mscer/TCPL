#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char * strcat2(char *dst,char *src);

int main()
{
    char dst[MAXSIZE] = {'\0'};
    char *src;
    size_t len = 0;
    while(getline(&src,&len,stdin) != -1){
        char * tmp ;
        tmp = strcat2(dst,src);
        if(NULL == tmp){
            printf("error dst");
            exit(-1);
        }
        fprintf(stdout,"dst is %s",dst);
    }
    //free(src);
    return 0;
}

char * strcat2(char *dst,char *src)
{
    if(strlen(dst)+strlen(src) > MAXSIZE){
        return NULL;  
    }else{
        size_t len = strlen(dst) > 0? strlen(dst)-1:0;
        dst = dst + len;
        while((*dst++ = *src++) != '\0'){
            ; 
        }
    } 
    return dst;
}

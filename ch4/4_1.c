#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//函数声明
int strrindex(char* src,char*sub);

int main()
{
   char * src = NULL;
   char * sub = NULL;
   size_t len;
   while(getline(&src,&len,stdin)>0 &&
         getline(&sub,&len,stdin)>0 ){
       printf("last occur is %d\n",strrindex(src,sub));
   }
   free(src);
   free(sub);
}

//函数实现
int strrindex(char* src,char*sub){
    int len_src = strlen(src);
    int len_sub = strlen(sub);
    if (0 == len_src || 0 ==len_sub){
        return -1; 
    }
    printf("len_src is %d",len_src);
    printf("len_sub is %d",len_sub);
    int i = len_src-2;
    int j = len_sub-2;
    int k =0;
    for (;i >= 0;i--){
        for(k = i,j = len_sub-2;(j>=0) && (src[k] == sub[j]); k--,j--){
        }
        if (j<0){
            return k+1; 
        }
    }
    return -1;
}

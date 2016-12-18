#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
int reverse(char *data,size_t index,size_t mid);
void swap(char *left,char *right);

int main()
{
   char data[MAXSIZE]; 
   char *line =  NULL;
   size_t len = 0;
   while(getline(&line,&len,stdin)!=-1){
       if(line[0] == 'q'){
           exit(0); 
       }
       strcpy(data,line);
       fprintf(stdout,"source input is :%s",line);
       fprintf(stdout,"%d",(int)strlen(data));
       reverse(data,0,strlen(data)/2);
       fprintf(stdout,"update input is :%s",data);
   }
}

int reverse(char *data,size_t index,size_t mid)
{
    //终止条件
    if(index >= mid){
        return 0; 
    }
    size_t len = strlen(data);
    if(len<1){
        return 0; 
    }
    size_t r_index = len -1-index; 
    swap(&data[index],&data[r_index]);
    reverse(data,++index,mid);
    return 0;
}
void swap(char *left,char *right)
{
    char tmp = *left;
    *left = *right;
    *right = tmp;
}

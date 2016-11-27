#include<stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 10

int main(){
   
    int wordl[MAX_LENGTH];
    //长度初始化
    for (int i=0;i<MAX_LENGTH;++i){
        wordl[i] = 0; 
    }


    int c = 0,wl=0;
    int state=OUT;
    while((c=getchar())!=EOF){
       if (' '==c || '\t'==c ||'\n'==c){
           if (IN == state){
                ++wordl[wl]; 
                state=OUT ;
           }
           ++wordl[0];
       }else{
           if(IN ==state){
               ++wl;
           } else{
               state = IN;
               wl=1;
           }
       } 
    }

    //水平打印结果
    for (int i=0;i<MAX_LENGTH;++i){
        printf("%3d\t",i);
       for (int j=0;j<wordl[i];++j){
           printf("\u2665");
       }  
       printf("\n");
    }

    //垂直打印结果
    int max=0; 
    for (int i=0;i<MAX_LENGTH;++i){
        if(wordl[i]>max){
            max=wordl[i]; 
        } 
        printf("%1d\t",i);
    }
    for (int i=0;i< max+3;++i){
        for (int j=0;j<MAX_LENGTH;j++){
            if((wordl[j]+i)>(max+2)){
                printf("\u2665\t");
            } 
            else{
                printf(" \t"); 
            }
        } 
        printf("\n");
    }
        
    return 0;
}

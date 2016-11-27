#include<stdio.h>
#define IN 1
#define OUT 0

int main(){
    int c=0;
    int state=OUT;
    while((c=getchar())!=EOF){
        if  (IN==state && (' '==c ||'\t'==c||'\n'==c)){
            putchar('\n') ;
            state=OUT;
        }else if(' '==c ||'\t'==c||'\n'==c){
            state=OUT;
            continue;
        }else{
            putchar(c); 
            state=IN;
        }
    }

    return 0;
}

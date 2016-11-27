#include<stdio.h>

int main(){
    int c=0,prec=0;
    while((c=getchar())!=EOF){
        if (' '==c && ' '==prec) {
            ;
        }else{
            putchar(c);
        }
        prec=c;
    }

    return 0;
}

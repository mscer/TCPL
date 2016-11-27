#include<stdio.h>

//函数定义
float fahr2cel(float fahr);

int main(){
    float fahr=0,cel=0;
    int lower=0,step=20,upper=300;

    printf("%3s %6s","fahr","cel\n");
    for (fahr=upper;fahr>=lower;fahr-=step){
        cel=fahr2cel(fahr); 
        printf("%3.0f %6.1f\n",fahr,cel);
    }
    return 0;
}



//函数实现
float fahr2cel(float fahr){
    float cel=(5.0/9.0)*(fahr-32.0);
    return cel;
}

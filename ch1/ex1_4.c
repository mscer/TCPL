#include<stdio.h>

//函数定义
float fahr2cel(float fahr);
float cel2fahr(float cel);



int main(){
    float fahr=0,cel=0;
    int lower=0,step=20,upper=300;

    printf("%3s %6s","fahr","cel\n");
    while(lower<upper){
        fahr=lower;
        cel=fahr2cel(fahr);
        printf("%3.0f %6.1f\n",fahr,cel); 
        lower=fahr+step;
    }

    printf("%3s %6s","cel","fahr\n");
    lower=0;
    while(lower<upper){
        cel=lower;
        fahr=cel2fahr(cel);
        printf("%3.0f %6.1f\n",cel,fahr); 
        lower=cel+step;
    }
    return 0;
}



//函数实现
float fahr2cel(float fahr){
    float cel=(5.0/9.0)*(fahr-32.0);
    return cel;
}


float cel2fahr(float cel){
   float fahr = cel*(9.0/5.0)+32.0;
   return fahr;
}

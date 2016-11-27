#include<stdio.h>
#include<limits.h>

int main()
{
    //rang of uchar
    printf("min uchar is :\t%u\n",0); 
    printf("max uchar is :\t%u\n",UCHAR_MAX); 

    //rang of ushort
    printf("min ushort is :\t%u\n",0); 
    printf("max ushort is :\t%u\n",USHRT_MAX); 

    //range of uint 
    printf("min uint is :\t%u\n",0); 
    printf("max uint is :\t%u\n",UINT_MAX); 

    //range of ulong 
    printf("min ulong is :\t%lu\n",(long)0); 
    printf("max ulong is :\t%lu\n",ULONG_MAX); 



    //rang of char
    printf("min char is :\t%d\n",CHAR_MIN); 
    printf("max char is :\t%d\n",CHAR_MAX); 

    //rang of short
    printf("min short is :\t%d\n",SHRT_MIN); 
    printf("max short is :\t%d\n",SHRT_MAX); 

    //range of int 
    printf("min int is :\t%d\n",INT_MIN); 
    printf("max int is :\t%d\n",INT_MAX); 

    //range of long 
    printf("min long is :\t%ld\n",LONG_MIN); 
    printf("max long is :\t%ld\n",LONG_MAX); 
}

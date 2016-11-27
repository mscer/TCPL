#include<stdio.h>

unsigned setbits(unsigned int *x,int p,int n,int y);

int main()
{
    unsigned int x=0, p=3,n=2,y=0;
    scanf("%d",&x);
    scanf("%d",&y);
    fprintf(stdout,"%d\n",x);
    fprintf(stdout,"%d\n",y);
    setbits(&x,p,n,y);
    fprintf(stdout,"%u\n",x);
}



unsigned setbits(unsigned int *x,int p,int n,int y)
{
    int mask=0;
    mask=y & ~(~0<<n);
    mask=y<<p;
    mask=(y&mask)| (~mask);

    fprintf(stdout,"%d\n",mask);
    *x=(*x) & mask;
    return 1;
}

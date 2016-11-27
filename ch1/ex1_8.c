#include<stdio.h>

int main(){
    int c=0;
    int sc=0,tc=0,nc=0;
    while ((c=getchar())!=EOF){
        if  (' '==c) ++sc;
        if ('\t'==c) ++tc;
        if ('\n'==c) ++nc;
    }
    
    printf("sc is:\t%d\n",sc);
    printf("tc is:\t%d\n",tc);
    printf("nc is:\t%d\n",nc);
}

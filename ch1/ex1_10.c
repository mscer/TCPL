#include<stdio.h>

int main(){
    int c;
    while((c=getchar())!=EOF){
        if (' '==c) {
            putchar('\\');
			putchar('b');
        }else if ('\t'==c){
            putchar('\\');
			putchar('t');
		} else if('\\'==c){
			putchar('\\');	
			putchar('\\');	
		}
		else{
			putchar(c);
		}

    }
	printf("%d",c=2);


	return 0;
}

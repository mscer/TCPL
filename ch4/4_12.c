#include <stdio.h>
#include <stdlib.h>

/*stck for num*/
#define MAXSIZE 100
typedef struct stack{
   char data[MAXSIZE];
   size_t top;
}Stack;
int push(Stack *stk,char c_tmp);
char pop(Stack *stk);

int itoa(int num,Stack *stk);

int main()
{
    char *line = NULL;
    size_t len = 0;
    Stack stk;
    stk.top = 0;
    while(getline(&line,&len,stdin)!=-1){
        if(line[0] == 'q'){
            exit(0); 
        }
        int num = atoi(line);
        //clear stk
        stk.top = 0;
        itoa(num,&stk);
        fprintf(stdout,"input is %s",stk.data);
    }
}


int push(Stack *stk,char c_tmp)
{
    if(stk->top<MAXSIZE-1){
        stk->data[stk->top++] = c_tmp;
        stk->data[stk->top] = '\0';
        return 0;
    }else{
        fprintf(stderr,"error:stack is full");
        return -1;
    }
}
char pop(Stack *stk)
{
    if(stk->top>0){
        return stk->data[--stk->top];
    }else{
        fprintf(stderr,"error:stack is full");
        return '0';
    
    }
}
int itoa(int num,Stack *stk)
{
    if(num<0){
        push(stk,'-');   
        num = -1*num;
    }
    //终止条件
    if(num<10){
        push(stk,num%10+'0'); 
        return 0;
    }else{
        itoa(num/10,stk); 
        push(stk,num%10+'0');
    }
    return 0;
}

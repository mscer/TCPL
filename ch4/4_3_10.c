#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER '0'
#define MAXOP 10

/*stack for calc*/
#define MAXSIZE 100
struct Stack{
    double data[MAXSIZE];
    size_t top; 
};
int push(Stack *stk,double d_t);
double pop(Stack *stk);

/*queue for calc*/
#define MAXSIZE 100
struct Queue{
    char data[MAXSIZE];
    size_t beg;
    size_t end; 
};
int push(Queue*que,char d_t);
char pop(Queue*que);

/*get operator*/
int getopt(Queue *que,char opt[]);

int main()
{
    Stack stk;
    stk.top = 0;
    Queue que;
    que.beg=que.end=0;
    char opt[MAXOP];
    int type = NUMBER;
    double d_tmp = 0.0;
    while((type = getopt(&que,opt)) !=-1){
        switch (type){
            case NUMBER:
                push(&stk,atof(opt));
                break;
            case '+':
                push(&stk,pop(&stk)+pop(&stk));
                break;
            case '*':
                push(&stk,pop(&stk)*pop(&stk));
                break;
            case '/':
                d_tmp = pop(&stk);
                push(&stk,pop(&stk)/d_tmp);
                break;
            case '-':
                d_tmp = pop(&stk);
                push(&stk,pop(&stk)-d_tmp);
                break;
            case '\n':
                fprintf(stdout,"%f",pop(&stk));
                break;
            default:
                fprintf(stderr,"invalid input");
                break;
        } 
    }
}

/*stack for calc*/
int push(Stack *stk,double d_t)
{
    if(stk->top<MAXSIZE){
        stk->data[stk->top]=d_t;
        stk->top++;
        return 0;
    }else{
        fprintf(stderr,"error:stack is full"); 
        return -1;
    }
}
double pop(Stack *stk){
    if(stk->top>0){
        return stk->data[--stk->top]; 
    }else{
        fprintf(stderr,"error:stack is empty"); 
        return -1;
    }
}
/*queue for calc*/
int push(Queue*que,char d_t)
{
    if(que->end<MAXSIZE-1){
        que->data[que->end++] = d_t;
        que->data[que->end++] = '\0';
        return 0;
    }else{
        fprintf(stderr,"error:queue is full"); 
        return -1;
    }

}
char pop(Queue*que){
    char tmp;
    if(que->beg<=que->end&&que->beg<MAXSIZE-1){
        tmp = que->data[que->beg++];
    }else{
        fprintf(stderr,"error:queue is empty"); 
        return '0';
    
    }
    return tmp;
}

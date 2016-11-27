#include<stdio.h>
#include<time.h>

int binsearch(int x, int *list,int length);

int main()
{
    int a[]={1,2,3,4,5,6,7,8};

    time_t tb=time(NULL);
    clock_t clb=clock();
    int index = binsearch(5,a,sizeof(a)/sizeof(int));
    clock_t cle=clock();
    time_t te=time(NULL);
        
    printf("index is :%d\n",index);
    printf("runtime is :%ld\n",(cle-clb)/CLOCKS_PER_SEC);
    printf("runtime is :%s\n",ctime(&tb));
    printf("runtime is :%s\n",ctime(&te));
    printf("runtime is :%f\n",difftime(tb,te));
}


int binsearch(int x, int *list,int length){
   int low=0;
   int high=length-1;
   int middle=0;
   while(low<=high){
       middle=low+(high-low)/2;
       if (x == list[middle]){
            return middle;       
       }else if(x<list[middle]){
            high = middle;  
       }else{
            low = middle; 
       }

   }
   return -1;
}

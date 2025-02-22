#include<stdio.h>
#define SIZE 7

int* Sort(int array[])
{
    for(int i=0;i<SIZE;i++){
        int min=i;
      
        for(int j=i+1;j<SIZE;j++){
            if(array[min]>array[j]){
                min=j;
            }
               
        }
        int temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
    return array;
}
                  
int main()
{
    int array[SIZE]={10,2,34,5,6,7,8};
    int *result=Sort(array);
    for(int i=0;i<SIZE;i++){
        printf("%d ",array[i]);
    }
    return 0;

}
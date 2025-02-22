#include<stdio.h>
#define SIZE 5
int* Sort(int *array);

int* Sort(int *array){
    for(int i=0;i<SIZE;i++){
        for(int j=i+1;j<SIZE;j++){
            if(array[i]>array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
                
        }
    }
    return array;
}

int main(){
    int array[10]={34,2,4,56,7};
    int *result=Sort(array);
    printf("sorted array is \n");
    for(int i=0;i<SIZE;i++)
        printf("%d ",*(result+i));
}


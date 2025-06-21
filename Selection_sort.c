#include<stdio.h>
#include<time.h>
#include<stdlib.h>



void selection_sort(int array[],int n){
    int small;
    for(int i=0;i<n;i++){
        small=i;
        for(int j=i+1;j<n;j++){
            if(array[j]<array[small]){
                int temp=array[small];
                array[small]=array[j];
                array[j]=temp;
            }
        }
    }
}


void main(){
    int n,array[100000];
    clock_t s,e;

    printf("enter the size of the array\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //array[i]=rand();
        //array[i]=i;
        array[i]=n-i;
    }

    // printf("\nBEFORE :-  array element are\n");
    // for(int i=0;i<n;i++){
    //     printf("%d ",array[i]);
    // }

    s=clock();
    selection_sort(array,n);
    e=clock();

    // printf("\nAFTER :-  array element are\n");
    // for(int i=0;i<n;i++){
    //     printf("%d ",array[i]);
    // }

    printf("\nTHe total time taken is %f",(double)(e-s)/CLOCKS_PER_SEC);


}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partision(int array[],int Lb,int Ub){
    int start,end,pivot;
    start=Lb;
    end=Ub;
    pivot=array[Lb];

    while(start<end){
        while(array[start]<=pivot){
            start++;
        }
        while(array[end]>pivot){
            end--;
        }
       if(start<end){
            int temp=array[start];
            array[start]=array[end];
            array[end]=temp;
       }
    }

    int temp=array[Lb];
    array[Lb]=array[end];
    array[end]=temp;
    return end;

}

void Quick_sort(int array[],int Lb,int Ub){
    if(Lb<Ub){
        int end=partision(array,Lb,Ub);
        Quick_sort(array,Lb,end-1);
        Quick_sort(array,end+1,Ub);
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

    printf("\nBEFORE :-  array element are\n");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }

    s=clock();
    Quick_sort(array,0,n-1);
    e=clock();

    printf("\nAFTER :-  array element are\n");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }

    printf("\nTHe total time taken is %f",(double)(e-s)/CLOCKS_PER_SEC);


}
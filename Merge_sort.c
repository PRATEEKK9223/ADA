#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Merge(int array[],int Lb,int mid,int Ub);



void merge_sort(int array[],int Lb,int Ub){
    if(Lb<Ub){
        int mid=(Lb+Ub)/2;
        merge_sort(array,Lb,mid);
        merge_sort(array,mid+1,Ub);
        Merge(array,Lb,mid,Ub);
    }
}

void Merge(int array[],int Lb,int mid,int Ub){
    int i,j,Temp[100000],k=Lb;
    i=Lb;
    j=mid+1;

    while(i<=mid && j<=Ub){
        if(array[i]<array[j]){
            Temp[k]=array[i];
            i++;
        }
        else{
            Temp[k]=array[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        Temp[k]=array[i];
        i++;
        k++;
    }
    while(j<=Ub){
        Temp[k]=array[j];
        j++;
        k++;
    }

    for(int i=Lb;i<=Ub;i++){
        array[i]=Temp[i];
    }


}


void main(){
    int n,array[100000];
    clock_t s,e;

    printf("enter the size of the array\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        array[i]=rand();
        //array[i]=i;
        //array[i]=n-i;
    }

    // printf("\nBEFORE :-  array element are\n");
    // for(int i=0;i<n;i++){
    //     printf("%d ",array[i]);
    // }

    s=clock();
    merge_sort(array,0,n-1);
    e=clock();

    // printf("\nAFTER :-  array element are\n");
    // for(int i=0;i<n;i++){
    //     printf("%d ",array[i]);
    // }

    printf("\nTHe total time taken is %f",(double)(e-s)/CLOCKS_PER_SEC);


}
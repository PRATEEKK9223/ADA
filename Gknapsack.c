#include<stdio.h>
void Gknapsack();
int M,w[10],p[10],n,sol[10];
float ratio[10];

void main(){
    printf("enter the number of items\n");
    scanf("%d",&n);
    printf("enter the wieight of each element\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    printf("enter the profit of each elemnt \n");
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    printf("enter the knapsack capacity\n");
    scanf("%d",&M);

    Gknapsack();
}

void Gknapsack(){
    
    int sum=0;
    for(int i=1;i<=n;i++){
        ratio[i]=(float)p[i]/w[i];
    }
    
    for(int q=1;q<=n;q++){
        float max=0.0;
        int k=0;
        for(int i=1;i<=n;i++){

            if(ratio[i]>max && sol[i]==0){
                max=ratio[i];
                k=i;
            }
        }

        if(M>=w[k]){
            sum+=p[k];
            M=M-w[k];
            sol[k]=1;
        }else{
            sol[k]=-1;
        }

    }

    for(int i=1;i<=n;i++){
        if(sol[i]==-1){
            sol[i]=0;
        }
    }

    printf("toatal profit is=%d",sum);

    printf("solution vector is\n");
    for(int i=1;i<=n;i++){
        printf("%d ",sol[i]);
    }
}

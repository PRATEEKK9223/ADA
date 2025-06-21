#include<stdio.h>
void Dnapsack();

int M,w[10],p[10],v[10][10],n;


int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void main(){
    printf("enter te number of items\n");
    scanf("%d",&n);
    printf("enter the weight of each item\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    printf("enter the profit of each item\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }

    printf("enter the knapsck capacity\n");
    scanf("%d",&M);

    Dnapsack();
}

void Dnapsack(){
    int sol[10];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=M;j++){
            if(i==0 || j==0){
                v[i][j]=0;
            }
            else if(j-w[i]<0){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
            }
        }
    }

    //to print the DP table

    for(int i=0;i<=n;i++){
        for(int j=0;j<=M;j++){
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }

    printf("\nthe optimal solution is %d \n",v[n][M]);

    //Backtrac to find the solution vector

    int cap=M;
    for(int i=n;i>=1;i--){
        if(v[i][cap]!=v[i-1][cap]){
            sol[i]=1;
        }
        else{
            sol[i]=0;
        }
    }

    printf("the solution vector is\n");
    for(int i=1;i<n;i++){
        printf("%d ",sol[i]);
    }

}

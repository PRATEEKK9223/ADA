#include<stdio.h>

int cost[10][10],Result[10][10],n;

void read_data(){
    printf("enter the size\n");
    scanf("%d",&n);
    printf("entert he cost matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
}

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

 void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            Result[i][j]=cost[i][j];
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                Result[i][j]=min(Result[i][j],Result[i][k]+Result[k][j]);
            }
        }
    }
}

void write_data(){
    printf("All pair shorest path matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",Result[i][j]);
        }
        printf("\n");
    }
}


void main(){
    read_data();
    floyd();
    write_data();
}
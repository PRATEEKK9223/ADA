#include<stdio.h>

int cost[10][10],n;

void krushkal(){
    int parent[10],min=0,mincost=0,u,v,a,b,ne=0;

    for(int i=1;i<=n;i++){
        parent[i]=0;
    }

    while (ne!=n-1){
        min=999;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    u=a=i;
                    v=b=j;
                }
            }
        }

        while(parent[u]!=0){
            u=parent[u];
        }
        while(parent[v]!=0){
            v=parent[v];
        }

        if(u!=v){
            printf("%d--->%d=%d\n",a,b,min);
            ne=ne+1;
            parent[v]=u;
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Mincost =%d",mincost);
    
}



void main(){
    printf("enter the size\n");
    scanf("%d",&n);
    printf("enter the cost matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    krushkal();
}

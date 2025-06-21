#include<stdio.h>

int cost[10][10],n,vis[10];

void prims(){
    int ne=0,min=0,mincost=0,u,v;
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    vis[1]=1;

    while(ne!=n-1){
        min=999;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(vis[i]==1){
                    if(cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        if(vis[v]!=1){
            printf("%d----->%d = %d\n",u,v,min);
            ne=ne+1;
            mincost+=min;
            vis[v]=1;
        }
        cost[u][v]=cost[v][u]=999;
    }
    printf("mincost=%d",mincost);
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
    prims();
}

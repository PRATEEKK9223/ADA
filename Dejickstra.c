#include<stdio.h>

int cost[10][10],dist[10],vis[10],src,n;


void Dijistra(){
    int min=0,u,count=0;
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        dist[i]=cost[src][i];
    }

    vis[src]=1;
    dist[src]=0;
    count=1;
   while(count!=n){
        min=999;
        for(int i=1;i<=n;i++){
            if(dist[i]<min && vis[i]!=1){
                min=dist[i];
                u=i;
            }
        }

        vis[u]=1;
        count++;

        for(int i=1;i<=n;i++){
            if(min+cost[u][i]<dist[i] && vis[i]!=1){
                dist[i]=min+cost[u][i];
            }
        }
   }
   for(int i=1;i<=n;i++){
    printf("%d--->%d = %d\n",src,i,dist[i]);
   }

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
    printf("enter the src node\n");
    scanf("%d",&src);
    Dijistra();
}
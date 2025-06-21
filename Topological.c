#include<stdio.h>
int a[10][10],n,indegree[10],Temp[10];


void T_sort(){
    //printf("inside function");
    int sum=0,top=-1,stack[10],u,k=0;
    for(int i=1;i<=n;i++){
        sum=0;
        for(int j=1;j<=n;j++){
            sum+=a[j][i];
            indegree[i]=sum;
        }
    }

    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            top++;
            stack[top]=i;
        }
    }

    while(top!=-1){
        u=stack[top];
        top--;
        Temp[k++]=u;

        for(int i=1;i<=n;i++){
            if(a[u][i]==1){
                indegree[i]--;

                 if(indegree[i]==0){
                    top++;
                    stack[top]=i;
                }
            }

        }
    }

    printf("Topological order is\n");
    for(int i=0;i<k;i++){
        printf("%d",Temp[i]);
    }
}

void main(){
    printf("ente the size\n");
    scanf("%d",&n);
    printf("enter the adjecency matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    T_sort();
}

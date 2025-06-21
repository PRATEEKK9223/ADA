#include<stdio.h>

int a[10][10],n;


void warshal(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(a[i][j]!=1){ 

                    if(a[i][k]==1 && a[k][j]==1){
                        a[i][j]=1;
                    }
                }
            }
        }
    }

    printf("path matrix is\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
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
    warshal();
}
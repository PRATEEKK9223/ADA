#include<stdio.h>

void Nqueens(int n);
int place(int x[],int k);
void print(int x[],int n);

void main(){
    int n;
    printf("enter the number of Queens\n");
    scanf("%d",&n);
    if(n==2 || n==3){
        printf("solution for %d queens not posible\n",n);
    }
    else{
        Nqueens(n);
    }
}

void print(int x[],int n){
    char c[10][10];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j]='X';
        }
    }

    for(int i=1;i<=n;i++){
        c[i][x[i]]='Q';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c ",c[i][j]);
        }
        printf("\n");
    }
}

int place(int x[],int k){
    for(int i=1;i<=k-1;i++){
        if(x[i]==x[k] || (i-x[i])==(k-x[k]) || (i+x[i])==(k+x[k])){
            return 0;
        }
    }
    return 1;
}

void Nqueens(int n){
    int x[10],k=1,count=0;
    x[k]=0;
    while(k!=0){
        x[k]++;
        while(x[k]<=n && !place(x,k)){
            x[k]++;
        }
        if(x[k]<=n){
            if(k==n){
                printf("solution %d\n",++count);
                for(int i=1;i<=n;i++){
                    printf("Row %d -> Column %d\n",i,x[i]);
                }
                printf("solution in form of chess board\n");
                print(x,n);
            }else{
                k++;
                x[k]=0;
            }
        }else{
            k--;
        }
    }

    if(count==0){
        printf("no solution .....\n");
    }
}
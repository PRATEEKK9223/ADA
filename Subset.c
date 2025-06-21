#include<stdio.h>
void subset(int m,int k,int sum);
int s[10],n,d,x[10],count=0;

void main(){
    int sum=0;
    printf("enter the number of elemnts\n");
    scanf("%d",&n);
    printf("enter the elemnts in ascending order\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }
    printf("enter the required sum\n");
    scanf("%d",&d);
    for(int i=1;i<=n;i++){
        sum+=s[i];
    }

    if(sum<d || s[0]>d){
        printf("\nsolution not exist...\n");
    }
    else{
        subset(0,1,sum);
        if(count==0){
        printf("\nno soltioon exits..\n");
    }

    }
}


void subset(int m,int k,int sum){
    x[k]=1;
    if(m+s[k]==d){
        printf("\nthe subset solution of %d is\n",++count);
        for(int i=1;i<=k;i++){
            if(x[i]==1){
                printf("%d ",s[i]);
            }
        }
        printf("\n");
    }

    else if(m+s[k]+s[k+1]<=d ){
        subset(m+s[k],k+1,sum-s[k]);
    }
    x[k]=0;

    if(m+sum-s[k]>=d && m+s[k+1]<=d ){
        
        subset(m,k+1,sum-s[k]);
    }

    
}

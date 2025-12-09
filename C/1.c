#include<stdio.h>
int visited[20];
int cur=0;
int def;
int sum=0;
void check(int a[20][20],int n,int start,int step){
    if(step==n){
        cur+=a[start][0];
        if(cur<=def) sum++;
        cur-=a[start][0];
        return;
    }
    for(int i=1;i<n;i++){
        if(visited[i]!=0) continue;
        cur+=a[start][i];
        visited[i]=1;
        check(a,n,i,step+1);
        cur-=a[start][i];
        visited[i]=0;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%d",&def);
    int a[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++) visited[i]=0;
    visited[0]=1;
    check(a,n,0,1);
    printf("%d",sum);
}
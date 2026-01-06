#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long muoi(int x){
    long sum=1;
    if(x==0) return sum;
    else{
        for(int i=1;i<=x;i++) sum*=10;
    }
    return sum;
}
struct hash{
    char id[11];
    int money;
    struct hash *next;
};
typedef struct hash* hash;
int returnindex(char str[]){
    long long sum=0;
    long long somu=0;
    for(int i=strlen(str)-1;i>0;i--){
        sum+=(str[i]-'0')*muoi(somu);
        somu++;
    }
    return sum%200007;
}
hash array[200007];
hash find(char id[]){
    int index=returnindex(id);
    hash p=array[index];
    while(p!=NULL){
        if(strcmp(p->id,id)==0){
            return p;
        }
        p=p->next;
    }
    return p;
}
void insert(char id[],int tien){
    int index=returnindex(id);
    hash p=find(id);
    if(p==NULL){
        hash tmp=(hash)malloc(sizeof(struct hash));
        strcpy(tmp->id,id);
        tmp->money=0;
        tmp->money+=tien;
        tmp->next=array[index];
        array[index]=tmp;
    }else if(p!=NULL){
        p->money+=tien;
    }
}
int main(){
    while(1){
        char from[11];
        char to[11];
        int money;
        char time[9];
        char atm[5];
        scanf("%s",from);
        if(strcmp(from,"#")==0) break;
        scanf("%s %d %s %s",to,&money,time,atm);
        insert(from,money);
    }
    while(1){
        char cmd[30];
        char id[11];
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0) break;
        scanf("%s",id);
        printf("%d\n",find(id)->money);
    }
}
#include <stdio.h>
#include <string.h>

struct sv{
    char id[8];
    int grade;
};
typedef struct sv sv;

int main(){
    int n;
    scanf("%d",&n);

    int d[1000]={0};
    sv ds[1000];

    for(int i=0;i<n;i++){
        char str[10];
        scanf("%s", str);                     // đọc chuỗi đúng
        int idx = str[6] - '0';               // lấy chỉ số đúng

        d[idx] = 1;                           // đánh dấu đã có
        strcpy(ds[idx].id, str);              // lưu id
        scanf("%d", &ds[idx].grade);          // lưu điểm
    }

    // In ra theo thứ tự có trong d[]
    for(int i=0;i<1000;i++){
        if(d[i]){
            printf("%s %d\n", ds[i].id, ds[i].grade);
        }
    }
}

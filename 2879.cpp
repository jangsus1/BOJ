#include<stdio.h>


int N;
int cur[1005];
int ans[1005];
int diff[1005];

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", cur+i);
    }
    for(int i=0; i<N; i++){
        scanf("%d", ans+i);
        diff[i] = ans[i] - cur[i];
    }
    int count = 0;
    int flag = true;
    while(flag){
        flag = false;
        int grouping = false;
        int recent = false;
        for(int i=0;i<N;i++){
            if(diff[i]>0) grouping = flag = true;
            else if(diff[i]<=0) grouping = false;
            if(grouping) {
                diff[i] -= 1;
                if(!recent){
                    count++;
                }
            }
            recent = grouping;
        }
    }
    flag = true;
    while(flag){
        flag = false;
        int grouping = false;
        int recent = false;
        for(int i=0;i<N;i++){
            if(diff[i]<0) grouping = flag = true;
            else if(diff[i]>=0) grouping = false;
            if(grouping) {
                diff[i] += 1;
                if(!recent){
                    count++;
                }
            }
            recent = grouping;
        }
        
    }
    printf("%d", count);
}
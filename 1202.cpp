#include<stdio.h>
#include<algorithm>
#include<functional>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> p;
int N, K;
p jam[300005];
int C[300005];
priority_queue<int> pq;
int currentIndex=0;

bool compareJam(const p& p1,const p& p2){
    return p1.first < p2.first;
}

int main(){
    long long sum = 0;
    scanf("%d%d", &N, &K);
    for(int i=0;i<N;i++){
        scanf("%d%d", &jam[i].first, &jam[i].second);
    }
    for(int i=0;i<K;i++){
        scanf("%d", &C[i]);
    }
    sort(C, C+K);
    sort(jam, jam+N, compareJam);
    for(int i=0;i<K;i++){
        int size = C[i];
        //printf("recentsize : %d index : %d size : %d\n", recentSize, currentIndex, size);
        while(currentIndex < N && size>=jam[currentIndex].first){
            pq.push(jam[currentIndex].second);
            currentIndex++;
        }
        
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        
    }
    printf("%lld", sum);

}
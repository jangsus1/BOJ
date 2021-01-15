#include<stdio.h>
#include<vector>

using namespace std;

vector<int> list[300005];
int N;

long long traverse(int second){
    long long sum = 0;
    int size1 = list[second].size();
    for(int i=0;i<size1;i++){
        int third = list[second][i];
        sum += (list[third].size()-1)*(size1-1);
    }
    return sum;
}

long long combination3(long long n){
    if(n >= 3) return n * (n-1) * (n-2) / 6;
    else return 0;
}


int main(){
    scanf("%d", &N);

    for(int i=0; i<N-1 ;i++){
        int start, end;
        scanf("%d%d", &start, &end);
        list[start-1].push_back(end-1);
        list[end-1].push_back(start-1);
    }

    long long D = 0, G = 0;
    for(int i=0;i<N;i++){
        D += traverse(i);
        G += combination3(list[i].size());
    }
    D /= 2;

    if(D > 3*G) printf("D");
    else if(D < 3*G) printf("G");
    else printf("DUDUDUNGA");
}
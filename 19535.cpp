#include<stdio.h>
#include<vector>

using namespace std;

vector<int> list[300005];
int N;

int DFS(int depth){
    if(depth == 1){
        
    }
    else {

    }
}

int main(){
    scanf("%d", &N);

    for(int i=0; i<N-1 ;i++){
        int start, end;
        scanf("%d%d", &start, &end);
        list[start].push_back(end);
        list[end].push_back(start);
    }

}
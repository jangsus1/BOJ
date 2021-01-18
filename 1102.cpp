#include<stdio.h>

int dp[1<<16];
int N;
int arr[16][16];
int status[16];
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &arr[i][j]);
		}
	}
	for(int i=0;i<N;i++){
		char c;
		scanf("%c", &c);
		if(c=='Y') status[i]=1;
		else status[i]=0;
	}
	
	
}
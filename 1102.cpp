#include<stdio.h>
#define min(x, y) ((x)>(y)? (y) : (x))

int dp[1<<16];
int N, P;
int arr[16][16];
int status[16];
int bitmark[16];
int answer[17];

int check(int num, int count){
    for(int i=0;i<N;i++){
        if((num>>i)&1) {
            count--;
            bitmark[i] = 1;
        }
        else {
            bitmark[i]=0;
        }
    }
    if(count == 0) return 1;
    else return 0;
}

int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &arr[i][j]);
		}
	}
    int count = 0;
    int cost = 0;
    getchar();
	for(int i=0;i<N;i++){
		char c;
		scanf("%c", &c);
		if(c=='Y') {
            status[i]=1;
            count++;
        }
		else status[i]=0;
	}
    scanf("%d", &P);

    


    int loopCount = (1<<N);
    for(int i=0;i<loopCount;i++){
        dp[i] = 10000000;
    }

    int turnOnBitmask=0;
    int turnOnCount = 0;
    for(int i=0;i<N;i++){
        turnOnBitmask += (status[i]<<i);
        turnOnCount += status[i];
    }
    dp[turnOnBitmask] = 0;
    if(!turnOnBitmask){
        if(P>0) printf("-1");
        else printf("0");
        return 0;
    }

    if(turnOnCount >= P){
        printf("0");
        return 0;
    }
    
    

    for(int i=0;i<=N;i++){
        answer[i] = 10000000;
    }


    for(int on=count; on < P; on++){
        for(int num=0; num<loopCount; num++){
            if(check(num, on)){
                for(int target=0;target<N;target++){
                    if(!bitmark[target]){
                        for(int generator = 0;generator<N;generator++){
                            if(bitmark[generator]){
                                dp[num+(1<<target)] = min(dp[num+(1<<target)], dp[num]+arr[generator][target]);
                                answer[on+1] = min(answer[on+1], dp[num+(1<<target)]);
                            }
                        }
                    } 
                }
            }
        }
    }

    printf("%d", answer[P]);
	
}
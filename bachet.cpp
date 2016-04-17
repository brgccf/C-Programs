#include <bits/stdc++.h>

using namespace std;

int main(){
	int numb_stones, m;
	int a[10];
	bool dp[1000001];

	while(scanf("%d %d",&numb_stones,&m)==2){
		for(int i = 0; i < m; i++) scanf("%d",&a[i]);
		dp[0] = false;
		for(int i = 1 ; i <= numb_stones; i++){
			dp[i] = false;
			for(int j = 0 ; j < m; j++)
				if(i >= a[j] && !dp[i-a[j]]){
					dp[i] = true;
					break;
				}
		}
		if(dp[numb_stones]) printf("Stan wins\n");
		else printf("Ollie wins\n");
		}
	return 0;
}
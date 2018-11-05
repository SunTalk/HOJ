#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "206"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

// int main(int argc, char const *argv[])
// {
// 	#ifdef DBG
// 	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
// 	freopen("hoj" PROBLEM ".out", "w", stdout);
// 	#endif

// 	while( ~scanf("%d %d",&one,&two) ){

// 		if( (one*two)%2 != 0 ){
// 			printf("0\n");
// 			continue;
// 		}

// 	}

// 	return 0;
// }
//-------------------------------------------------

long long int dp[14][8192];
int n,m;
int k,y;
long long int v;
void dfs(int x,int key){
	if(x==n){
		dp[y][key]+=v;
		return;
	}
	if( !( k & (1<<x) ) ){
		dfs( x+1 , key | (1<<x) );
		if(x+1<n)
			if(!(k&1<<(x+1)))
				dfs(x+2,key);
	}
	else{
		dfs(x+1,key);
	}
}
int main(){

	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	while(~scanf("%d%d",&n,&m)){
		//if((n*m)&1){puts("0");continue;}
		int top=(1<<n)-1;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=m;i++){
			for(int j=0;j<=top;j++){
				if(dp[i-1][j]){
					//printf("%d %d\n",i-1,j);
					k=j;y=i,v=dp[i-1][j];
					dfs(0,0);
				}
			}
		}
		printf("%lld\n",dp[m][0]);
	}
	return 0;
}


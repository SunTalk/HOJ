#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "32"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	int times,tmp,i,j;
	scanf("%d",&times);
	int bee[times];
	int ans[times+1][2]={0};

	for( i = 0 ; i < times ; i++ )
		scanf("%d",&bee[i]);

	for( i = 0 ; i < times ; i++ ){
		scanf("%d",&tmp);
		for( j = 1 ; j <= times ; j++ ){
			if( tmp == bee[j-1] )
				ans[j][1] = ans[j-1][0]+1;
			else
				ans[j][1] = max(ans[j-1][1],ans[j][0]);
		}
		for( j = 1 ; j <= times ; j++ )
			ans[j][0] = ans[j][1];
	}
	
	printf("%d\n",ans[times][1] );

	return 0;
}
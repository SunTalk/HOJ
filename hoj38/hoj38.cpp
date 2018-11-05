#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "38"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	int budget,position,people;

	scanf("%d %d %d",&budget,&position,&people);
	
	int ans[10005][2];
	memset(ans,0,sizeof(ans));
	int money,power,i,j;

	while( position-- ){

		for( i = 0 ; i < people ; i++ ){
			scanf("%d %d",&money,&power);

			for( j = 1 ; j <= budget ; j++ )
				if( j >= money ){
					ans[j][1] = max( ans[j][1] , ans[j][0] );
					ans[j][1] = max( ans[j][1] , ans[j-money][0]+power );
				}

		}

		for( i = 1 ; i <= budget ; i++ )
			ans[i][0] = ans[i][1];

	}

	printf("%d\n",ans[budget][1] );

	return 0;
}
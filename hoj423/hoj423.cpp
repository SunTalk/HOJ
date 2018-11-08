#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "423"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	int bag[100010][2];
	pair<int,int> rock[105];//weight,num
	int number,weight;
	int i,j;

	while( ~scanf("%d %d",&number,&weight) && number && weight ){

		for( i = 1 ; i <= number ; i++ )
			scanf("%d",&rock[i].first);
		for( i = 1 ; i <= number ; i++ )
			scanf("%d",&rock[i].second);

		memset(bag,0,sizeof(bag));
		int tmp;

		for( i = 1 ; i <= number ; i++ ){
			tmp = 1;
			while( tmp <= rock[i].second ){

				for( j = 1 ; j <= weight ; j++  )
					if( j >= rock[i].first*tmp )
						bag[j][1] = max( bag[j-rock[i].first*tmp][0] + rock[i].first*tmp , bag[j][0] );
				
				for( j = 1 ; j <= weight ; j++ )
					bag[j][0] = bag[j][1];

				rock[i].second = rock[i].second - tmp;
				tmp = tmp*2;

			}
			if( rock[i].second > 0 ){
				tmp = rock[i].second;
				for( j = 1 ; j <= weight ; j++  )
					if( j >= rock[i].first*tmp )
						bag[j][1] = max( bag[j-rock[i].first*tmp][0] + rock[i].first*tmp , bag[j][0] );
				
				for( j = 1 ; j <= weight ; j++ )
					bag[j][0] = bag[j][1];
			}		
		}

		int ans = 0;

		for( i = 1 ; i <= weight ; i++ )
			if( bag[i][1] == i )
				ans++;
		
		printf("%d\n",ans );

	}

	return 0;
}
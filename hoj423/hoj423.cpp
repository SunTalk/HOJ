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

	int bag[100005][2];
	pair<int,int> rock[105];//weight,num
	int number,weight;
	int i,j,k;

	while( ~scanf("%d %d",&number,&weight) && number && weight ){

		for( i = 1 ; i <= number ; i++ )
			scanf("%d",&rock[i].first);
		for( i = 1 ; i <= number ; i++ )
			scanf("%d",&rock[i].second);

		memset(bag,0,sizeof(bag));
		int check = 1;
		int tmp;

		for( i = 1 ; i <= number ; i++ ){
			tmp = 1;
			check = 1;
			while(1){
				if( tmp == 0 )
					break;

				for( k = 1 ; k <= weight ; k++  )
					if( k >= rock[i].first*tmp )
						bag[k][1] = max( bag[k-rock[i].first*tmp][0] + rock[i].first*tmp , bag[k][0] );
				for( k = 1 ; k <= weight ; k++ )
					bag[k][0] = bag[k][1];

				if(check == 2)
					break;
				else if( rock[i].second - tmp*2 + 1 <= tmp*2 ){
					tmp = rock[i].second - tmp*2 + 1;
					check = 2;
				}
				else
					tmp = tmp*2;

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
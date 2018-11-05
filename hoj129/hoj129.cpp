#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "129"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define MAX 3005

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif
	
	int row,column;
	scanf("%d %d",&row,&column);

	int Big,i,j;
	int rectangle[MAX][2];
	pair <int,int> after[MAX][2];
	pair <int,int> TmpA,TmpB;
	int tmpA,tmpB;
	Big = 0;
	memset(rectangle,-1,sizeof(rectangle));
	for( i = 0 ; i < MAX ; i++ ){
		after[i][0].first = after[i][1].first = 0;
		after[i][0].second = after[i][1].second = 0;
	}
	after[1][1].first = 1;
	after[1][1].second = 1;
	for( i = 1 ; i <= row ; i++ ){
		for( j = 1 ; j <= column ; j++ )
			scanf("%d ",&rectangle[j][1]);

		for( j = 1 ; j <= column ; j++ ){
			if( rectangle[j][1] == rectangle[j][0] && rectangle[j][1] == rectangle[j-1][1] ){
				after[j][1].first = max(after[j][0].first,after[j-1][1].first);
				after[j][1].second = max(after[j][0].second,after[j-1][1].second);
			}
			else if( rectangle[j][1] == rectangle[j][0] ){
				after[j][1] = after[j][0];
				after[j][1].second = j;
			}
			else if( rectangle[j][1] == rectangle[j-1][1] ){
				after[j][1] = after[j-1][1];
				after[j][1].first = i;
			}
			else{
				after[j][1].first = i;
				after[j][1].second = j;
			}

			Big = max( Big , (i-after[j][1].first+1)*(j-after[j][1].second+1) );

		}

		for( j = 1 ; j <= column ; j++ ){
			rectangle[j][0] = rectangle[j][1];
			after[j][0] = after[j][1];
		}

		// printf("Big:%d\n",Big);
		// for( j = 1 ; j <= column ; j++ )
		// 	printf("(%d,%d) ",after[j][1].first,after[j][1].second );
		// printf("\n");

	}

	printf("%d\n",Big );

	return 0;
}

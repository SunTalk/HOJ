#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "31"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	int one,two;
	scanf("%d %d",&one,&two);
	int table[one+1][2]={0};
	int sequence[one];
	int tmp,i,j;
	for( i = 0 ; i < one ; i++ ){
		scanf("%d",&tmp);
		sequence[i] = tmp;
	}
	for( i = 0 ; i < two ; i++ ){
		scanf("%d",&tmp);
		for( j = 1 ; j <= one ; j++ ){
			if( tmp == sequence[j-1] )
				table[j][1] = table[j-1][0]+1;
			else
				table[j][1] = max(table[j-1][1],table[j][0]);
		}
		for( j = 1 ; j <= one ; j++ )
			table[j][0] = table[j][1];
	}

	printf("%d\n",table[one][1] );

	return 0;
}
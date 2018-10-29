#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "41"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	int backage,prop;
	scanf("%d %d",&backage,&prop);

	int value,weight;
	int ans[backage+1][2],i;
	memset(ans,0,sizeof(ans));

	while( prop-- ){
		scanf("%d %d",&value,&weight);

		for( i = 0 ; i <= backage ; i++ )
			if( i >= weight )
				ans[i][1] = max(ans[i-weight][1]+value,ans[i][0]);

		for( i = 0 ; i <= backage ; i++ )
			ans[i][0] = ans[i][1];

	}

	printf("%d\n",ans[backage][1] );

	return 0;
}
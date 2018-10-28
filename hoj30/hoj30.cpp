#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "30"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	int times,number;
	vector <int> list;
	scanf("%d",&times);
	times--;
	scanf("%d",&number);
	list.push_back(number);

	while( times-- ){
		
		scanf("%d",&number);
		if( number > list.back() )
			list.push_back(number);
		else
			*lower_bound(list.begin(),list.end(),number) = number;
	}
	
	printf("%d\n",list.size() );

	return 0;
}
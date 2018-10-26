#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "431"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define MAX_P 46340
#define NUM_P 4792

bool prime[MAX_P+5];

void build()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	for(int i = 2; i <= MAX_P; i++)
	{
		if(prime[i])
		{
			prime[i] = true;
			for(int j = i*i; j <= MAX_P; j += i)
				prime[j] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif
	int l, r;

	build();

	int cnt = 0;
	for(int i = 2; i <= MAX_P; i++)
		if(prime[i])
			cnt++;

	cout << cnt << '\n';

	while(cin >> l >> r)
	{

	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

// by roy4801 hoj 144 (AC)

#define TESTC ""
#define PROBLEM "144"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define MAX_N 100000

int n, q; // number, query
int t[4*MAX_N+5]; // 1-index
int in[MAX_N+5];  // 1-index

#define LEFT(x) ((x)<<1)
#define RIGHT(x) (((x)<<1)+1)

void buildSeg(int inL, int inR, int p)
{
	if(inL == inR)
	{
		t[p] = in[inL];
		return;
	}
	
	int mid = (inL+inR)/2;
	buildSeg(inL, mid, LEFT(p));    // build left subtree
	buildSeg(mid+1, inR, RIGHT(p)); // build right subtree
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}

void modify(int L, int R, int p, int i, int x)
{
	// stop point
	if(i == L && L == R)
	{
		t[p] = x;
		return;
	}

	int mid = (L+R) / 2;
	if(i <= mid)
		modify(L, mid, LEFT(p), i, x);
	else
		modify(mid+1, R, RIGHT(p), i, x);
	// update this node
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}

int query(int L, int R, int p, int quL, int quR)
{
	// stop point
	if(quL <= L && R <= quR)
	{
		// cout << "bbb" << endl;
		return t[p];
	}

	// cout << "L: " << L << " R: " << R << " div2: " << (L+R)/2 << endl << "quL: " << quL << " quR: " << quR << endl;
	
	int mid = (L+R) / 2;

	if(quR <= mid) // left
		return query(L, mid, LEFT(p), quL, quR);
	else if(mid < quL) // right
		return query(mid+1, R, RIGHT(p), quL, quR);
	else // middle
		return max(query(L, mid, LEFT(p), quL, quR),
				   query(mid+1, R, RIGHT(p), quL, quR));
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif
	USE_CPPIO();
	int opt, inl, inr; // option, inputL, inputR (for option)

	while(cin >> n >> q)
	{
		// cout << n << ' ' << q << '\n';
		for(int i = 1; i <= n && cin >> in[i]; i++);

		buildSeg(1, n, 1);

		// for(int i = 1; i <= pow(__lg(4*n)); i++)
			// cout << t[i] << ' ';
		// cout << endl;

		for(int i = 0; i < q && cin >> opt >> inl >> inr; i++)
		{
			switch(opt)
			{
				// modify
				case 1:
					modify(1, n, 1, inl, inr);
				break;
				// query
				case 2:
					cout << query(1, n, 1, inl, inr) << '\n';
				break;
			}
		}

	}

	return 0;
}
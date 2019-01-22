#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "138"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct edge{
	int to,len;
	edge(){}
	edge(int a,int b){
		to = a;
		len = b;
	}
	bool operator < (const edge &a) const{
		return len > a.len;
	}
};

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("hoj" PROBLEM TESTC ".in", "r", stdin);
	freopen("hoj" PROBLEM ".out", "w", stdout);
	#endif

	int point,path;
	scanf("%d %d",&point,&path);
	vector <edge> con[point+1];

	int min_path[point+1],i,j;
	bool vis[point+1];

	for( i = 0 ; i <= point ; i++ ){
		min_path[i] = INT_MAX;
		vis[i] = false;
	}

	int one,two,len;
	for( i = 0 ; i < path ; i++ ){
		scanf("%d %d %d",&one,&two,&len);
		con[one].emplace_back(two,len);
		con[two].emplace_back(one,len);
	}

	priority_queue <edge> dijkstra;

	dijkstra.emplace(1,0);
	min_path[1] = 0;
	edge tmp;

	while( !dijkstra.empty() ){
		tmp = dijkstra.top();
		dijkstra.pop();

		i = tmp.to;
		int tmp_len = min_path[i];
		if( vis[i] )
			continue;
		vis[i] = true;

		for( j = 0 ; j < con[i].size() ; j++ ){
			
			tmp = con[i][j];

			if( tmp_len + tmp.len < min_path[tmp.to] ){
				min_path[tmp.to] = tmp_len + tmp.len;
				tmp.len = min_path[tmp.to];
				dijkstra.push(tmp);
			}
		
		}

	}

	if( min_path[point] == INT_MAX )
		printf("-1\n");
	else
		printf("%d\n",min_path[point] );

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX/10;
int dist[1005];


int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
	for(int i=0;i<adj.size();++i)
		dist[i] = inf;
	dist[0] = 0;
	// N*E
	for(int k=0;k<adj.size();++k)
	{
		for(int i=0;i<adj.size();++i)
		{
			for(int j=0;j<adj[i].size();++j)
			{
				int x = adj[i][j];
				dist[x]  = min(dist[x],dist[i]+cost[i][j]);
			}
		}
	}

	for(int i=0;i<adj.size();++i)
	{
		for(int j=0;j<adj[i].size();++j)
		{
			int x = adj[i][j];
			if(dist[x] > dist[i]+cost[i][j])
				return 1;
		}
	}

	//for(int i=0;i<adj.size();++i) cout<<dist[i]<<" ";

	//cout<<endl;
  	return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}

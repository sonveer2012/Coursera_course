#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int dist[100001];
const int inf = INT_MAX/10;
typedef pair<int,int> pii;
bool visited[100001];
void init()
{
  for(int i=0;i<100001;++i)
  {
    dist[i] = inf;visited[i]=false;
  }
}
class Prioritize
{
public:
  int operator() (const pii &P1, const pii &P2)
  {
    return P1.second>P2.second;
  }
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  init();

  priority_queue<pii,vector<pii>,Prioritize> PQ;
  PQ.push(mp(s,0));
  dist[s] = 0;
  while(!PQ.empty())
  {
    int V = PQ.top().first;
   // cout<<"sonveer"<<endl;
    PQ.pop();
    if(visited[V])
      continue;
    visited[V] = true;
    for(int i=0;i<adj[V].size();++i)
    {
      int x = adj[V][i];
      int w = cost[V][i];
      if(!visited[x])
      {
        dist[x] = min(dist[x],dist[V]+w);
        PQ.push(mp(x,dist[x]));
      }
    }
  }
  if(dist[t]==inf)
    return -1;
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) 
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
int dist[1000000];
vector<int> adj[1000000];
#define mp make_pair
const int inf =  100000000;
typedef std::pair<int,int> pii;
void init()
{
  for(int i=0;i<1000000;++i)
    dist[i] = inf;
}
int distance(int s, int t) 
{

  queue<int> Q;
  Q.push(s);

  dist[s] = 0;
  while(!Q.empty())
  {
      int V = Q.front();
      Q.pop();
      for(int i=0;i<adj[V].size();++i)
      {
        int x = adj[V][i];
        if(dist[x] == inf)
        {
          Q.push(x);
          dist[x] = dist[V]+1;
        }
      }
  }
  if(dist[t] == inf)
    return -1;
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  init();
  
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance( s, t);
}

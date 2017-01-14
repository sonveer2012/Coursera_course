#include <iostream>
#include <vector>
#define white 1
#define black 3
#define gray 2
#define temp 4
using std::vector;
using std::pair;
int par[1000];
int color[1000];
void init()
{
  for(int i=0;i<1000;++i)
    {
      color[i] = white;
    }
}
bool DFS(int v,vector<vector<int> > &adj)
{
    int size = adj[v].size();
    color[v] = gray;
    for(int i=0;i<size;++i)
    {
      if(color[adj[v][i]] == gray)
          return true;
      if(color[adj[v][i]]==white && DFS(adj[v][i],adj))
      {
        return true;
      }
    } 
    color[v] = black;
    return false;
}
int acyclic(vector<vector<int> > &adj) {
  init();
  int N=adj.size();
  for(int i=0;i<N;++i)
    if(color[i]==white && DFS(i,adj))
      return 1;
  return 0;
}

int main() 
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}

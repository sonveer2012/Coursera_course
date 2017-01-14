#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int color[100000];
void init()
{
  for(int i=0;i<100000;++i)
    color[i] = -1;
}
int bipartite(vector<vector<int> > &adj) {
  //write your code here
  queue<int> Q;
   
  for(int i=0;i<adj.size();++i)
  {
    if(color[i]==-1)
    {
      color[i] = 0;
      Q.push(i);
      while(!Q.empty())
      {
        int V = Q.front();
        Q.pop();
        for(int i=0;i<adj[V].size();++i)
        {
            int x = adj[V][i];
           // cout<<x<<"  "<<V<<endl;
            if(color[V] == color[x])
            {
            //  cout<<V<<"  "<<x<<endl;
              return 0;
            }
            if(color[x]==-1)
            {
              Q.push(x);
              color[x] = (color[V]+1)%2;
            }
        }
      }
    }
  }
  
  return 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  init();
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) 
  {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  cout << bipartite(adj);
}

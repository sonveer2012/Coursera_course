#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) 
{
  used[x] = 1;
  int K=adj[x].size();
  for(int i=0;i<K;++i)
  {
    int V = adj[x][i];
    if(used[V] == 0)
      dfs(adj,used,order,V);
  }
  order.push_back(x);
}    

void dfs1(vector<vector<int> > &adj, vector<int> &used,int x)
{
    used[x] = 0;
    int K=adj[x].size();
    for(int i=0;i<K;++i)
    {
        int V = adj[x][i];
        if(used[V] == 1)
            dfs1(adj,used,V);
    }
}
int number_of_strongly_connected_components(vector<vector<int> > adj) {
      int result = 0;
      vector<int> used(adj.size(), 0);
      vector<int> order;

        for(int i=0;i<adj.size();++i)
                if(used[i] == 0)
                  dfs(adj,used,order,i);
    //    int ans=0;
      vector<vector<int> > transpose_adj(adj.size(), vector<int>());;
      for(int i=0;i<adj.size();++i)
      {
        used[i] = 1;
        for(int j=0;j<adj[i].size();++j)
        {
          int src,dst;
          src = i;
          dst = adj[i][j];
          transpose_adj[dst].push_back(src);
        }
      }
      /*
      for(int i=0;i<transpose_adj.size();++i)
      {
        cout<<"#    "<<i<<"   :   ";
        for(int j=0;j<transpose_adj[i].size();++j)
          cout<<transpose_adj[i][j]<<" ";
        cout<<endl;
      }
      */
       for(int i=adj.size()-1;i>=0;--i)
       {
          //cout<<order[i]<<" ";
            if(used[order[i]]==1)
            {
                dfs1(transpose_adj,used,order[i]);
                result++;
            }
       }
       //cout<<endl;
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}

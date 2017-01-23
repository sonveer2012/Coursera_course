#include <bits/stdc++.h>
using namespace std;
typedef pair<double,pair<int,int> > piii;
int pare__nt[201];
int ra__nk[201];
#define dist_ first
#define point_x second.first
#define point_y second.second
piii Array[80001];

void init()
{
  for(int i=0;i<201;++i)
  {
    ra__nk[i] = 0;
    pare__nt[i] = i;
  }
}
int find(int x)
{
  while(x!=pare__nt[x])
  {
    x = pare__nt[x];
  }
  return x;
}
bool Union(int x,int y)
{
    x = find(pare__nt[x]);
    y = find(pare__nt[y]);
   // cout<<x<<" union  "<<y<<"  ";
    if(x==y)
      return false;

    if(ra__nk[x] < ra__nk[y])
      pare__nt[x]  = y;
    else if(ra__nk[x] > ra__nk[y])
      pare__nt[y] = x;
    else
    {
      pare__nt[y] = x;
      ra__nk[x]++;
    }
    return true;

}
double dist(int x1,int y1,int x2,int y2)
{
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}


double clustering(vector<int> x, vector<int> y, int k) 
{
  
  init();
  int N = x.size();
  int cluster_cnt = N;
  int cnt =0 ;
  for(int i=0;i<N;++i)
  {
    for(int j=i+1;j<N;++j)
    {
      Array[cnt].dist_ = dist(x[i],y[i],x[j],y[j]);
      Array[cnt].point_x = i;
      Array[cnt].point_y = j;
      cnt++;
    }
  }
  sort(Array,Array+cnt);
  for(int i=0;i<cnt;++i)
  {
    int x1 = Array[i].point_x;
    int y1 = Array[i].point_y;
    double son = Array[i].dist_;
    //cout<<son<<" "<<x1<<"  "<<y1<<endl;;
    if(cluster_cnt > k && Union(x1,y1)==true)
      cluster_cnt--;
   // cout<<result<<endl;
  }
  vector<int> predict_path(N,-1);
  vector<vector<int> > Graph_const(k,vector<int>());
  int tmp = -1;
  for(int i=0;i<N;++i)
  {
    int king = find(i);
      if(predict_path[king] == -1)
      {
          tmp++;
          predict_path[king] = tmp;
          
      }

      Graph_const[predict_path[king]].push_back(i);
  }/*
  for(int i=0;i<k;++i)
  {
    for(int j=0;j<Graph_const[i].size();++j)
      cout<<Graph_const[i][j]<<" ";
    cout<<endl;
  }*/
  //   graph of group is constructed now find maximum distance
  double an_s = 10000000.0;
  for(int i=0;i<k;++i)
  {
   // double temp = 10000000.0;
      for(int j=i+1;j<k;++j)
      {
          for( int a = 0;a<Graph_const[i].size();++a)
          {
            for(int z = 0;z<Graph_const[j].size();++z)
            {
              int x1 =Graph_const[i][a];
              int y1 = Graph_const[j][z];

              an_s = min(an_s,dist(x[x1],y[x1],x[y1],y[y1]));
            }
          }
      }
  }
  return an_s;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
  return 0;
}

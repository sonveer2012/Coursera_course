#include <bits/stdc++.h>
using namespace std;
typedef pair<double,pair<int,int> > piii;
int pare_nt[201];
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
    pare_nt[i] = i;
  }
}
int find(int x)
{
  if(x!=pare_nt[x])
  {
    x = pare_nt[x];
  }
  return x;
}
bool Union(int x,int y)
{
    x = find(pare_nt[x]);
    y = find(pare_nt[y]);
   // cout<<x<<" union  "<<y<<"  ";
    if(x==y)
      return false;

    if(ra__nk[x] < ra__nk[y])
      pare_nt[x]  = y;
    else if(ra__nk[x] > ra__nk[y])
      pare_nt[y] = x;
    else
    {
      pare_nt[y] = x;
      ra__nk[x]++;
    }
    return true;

}
double dist(int x1,int y1,int x2,int y2)
{
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int N = x.size();
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
    if(Union(x1,y1)==true)
      result +=son;
   // cout<<result<<endl;
  }
 // cout<<endl;
  return result;
} 

int main() {
  init();
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) 
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  vector<int> p(N);
  for(int i=0;i<N;i++) cin >> p[i];
  sort(p.begin(),p.end());
  int sum=0, time=0;
  for(int i=0;i<N;i++){
    time+=p[i];
    sum+=time;
  } 
  cout << sum;
  return 0;
}
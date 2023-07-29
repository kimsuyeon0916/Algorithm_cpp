#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N; 
  vector<int> dist(N-1);
  vector<int> gas(N);
  for(int i=0;i<N-1;i++) cin >> dist[i];
  for(int i=0;i<N;i++) cin >> gas[i]; 
  unsigned long long oil=gas[0], cost=oil*dist[0];
  for(int i=1;i<N-1;i++){
    if(gas[i]<oil) oil=gas[i];
    cost+=oil*dist[i]; 
  } 
  cout << cost;
  return 0;
}
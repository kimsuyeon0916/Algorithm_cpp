#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  priority_queue<int, vector<int>, greater<>> pq; //Min Heap
  for(int i=1;i<=N;i++){
    int x; cin >> x;
    if(x) pq.emplace(x);
    else{
      if(pq.empty()) cout << 0 << '\n';
      else{
        cout << pq.top() << '\n';
        pq.pop();
      } 
    } 
  }
  return 0;
}
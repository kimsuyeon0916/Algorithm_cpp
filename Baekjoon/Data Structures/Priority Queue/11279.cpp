#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  priority_queue<int> pq; //Max Heap
  int x;
  for(int i=1;i<=N;i++){
    cin >> x;
    if(x==0){
      if(pq.empty()) cout << 0 << '\n';
      else{
        cout << pq.top() <<'\n';
        pq.pop(); //처음에 이걸 else 바깥에 놔서 출력이 안됐음
      }
    }     
    else pq.emplace(x);
  } 
  return 0;
}
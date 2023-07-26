#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

struct cmp //절댓값 내림차순 구현
{
  bool operator()(int &a, int &b){
    if(abs(a)==abs(b)) return a>b; //절댓값이 같은 경우 작은 숫자부터
    return abs(a)>abs(b); //오름차순 정렬
  }
};

int main()
{
  FASTIO;
  int N; cin >> N;
  priority_queue<int, vector<int>, cmp> pq; //절댓값 Heap
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
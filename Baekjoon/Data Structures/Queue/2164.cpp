#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  queue<int> q;
  int i=N;
  for(int i=1;i<=N;i++) q.emplace(i);

  while(q.size()>=2){ //카드의 위가, 큐의 맨 앞. 카드의 아래가, 큐의 맨 뒤
    q.pop();
    q.emplace(q.front());
    q.pop();
  }

  cout << q.front();
  return 0;
}

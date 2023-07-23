#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=0;i<T;i++){
    int N,M; cin >> N >> M;
    queue<pair<int,int>> q; //큐 내 순서, 중요도
    priority_queue<int> pq; //중요도
    for(int j=0;j<N;j++){
      int p; cin >> p;
      q.emplace(make_pair(j,p));
      pq.emplace(p); //중요도 내림차순으로 기본 자동 정렬
    }

    int order=1;
    while(!q.empty()){
      if(pq.top()!=q.front().second){ //큐가 중요도가 높은 순이 아니라면
        q.emplace(q.front()); //뒤로 보내기
        q.pop();
      }
      else{ //중요도 순이라면
        if(q.front().first==M){
          cout << order << '\n';
          break;
        }
        pq.pop(); 
        q.pop();
        order++; //슌서 체크
      }
    }
  }
  return 0;
}
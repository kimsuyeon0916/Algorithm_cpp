#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=1;i<=T;i++){
    int k; cin >> k;
    priority_queue<int> max_q; //Max Heap
    priority_queue<int, vector<int>, greater<>> min_q; //Min Heap
    map<int,int> repeat;
    int push_cnt=0, pop_cnt=0;
    for(int i=0;i<k;i++){
      char c; int x;
      cin >> c >> x;
      if(c=='I'){
        max_q.emplace(x);
        min_q.emplace(x);
        if(repeat.find(x)==repeat.end()) repeat.emplace(x,1);
        else ++repeat[x];
        ++push_cnt;
      }
      else{
        if(push_cnt<=pop_cnt) continue; //Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시
        if(x==-1){
          while(!repeat[min_q.top()]) min_q.pop(); //뽑기 전 동기화
          --repeat[min_q.top()];
          min_q.pop();
        } 
        else{
          while(!repeat[max_q.top()]) max_q.pop(); //뽑기 전 동기화
          --repeat[max_q.top()];
          max_q.pop();
        } 
        ++pop_cnt;
      }
    }
    if(push_cnt==pop_cnt){ //큐가 비어있는 경우
      cout << "EMPTY" << '\n';
      continue;
    }
    deque<int> intsec;
    while(!max_q.empty()){
      if(repeat[max_q.top()]>=1){
        intsec.emplace_back(max_q.top());
        --repeat[max_q.top()];
      } 
      max_q.pop();
    }
    sort(intsec.begin(),intsec.end());
    cout << intsec.back() << ' ' << intsec.front() << '\n';
  }
  return 0;
}
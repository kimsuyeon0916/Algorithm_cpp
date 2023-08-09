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
    for(int i=0;i<k;i++){
      char c; int x;
      cin >> c >> x;
      if(c=='I'){
        max_q.emplace(x);
        min_q.emplace(x);
        if(repeat.find(x)==repeat.end()) repeat.emplace(x,1);
        else ++repeat[x];
      }
      else{
        if(x==-1){
          while(!min_q.empty() && !repeat[min_q.top()]) min_q.pop(); //뽑기 전 동기화
          if(!min_q.empty()){
            --repeat[min_q.top()];
            min_q.pop();
          }
        } 
        else{
          while(!max_q.empty() && !repeat[max_q.top()]) max_q.pop(); //뽑기 전 동기화
          if(!max_q.empty()){
            --repeat[max_q.top()];
            max_q.pop();
          }
        } 
      }
    }
    while(!max_q.empty() && !repeat[max_q.top()]) max_q.pop(); //동기화
    while(!min_q.empty() && !repeat[min_q.top()]) min_q.pop(); //동기화
    if(max_q.empty()||min_q.empty()) cout<<"EMPTY\n";
    else cout << max_q.top() << ' ' << min_q.top() << '\n';
  }
  return 0;
}
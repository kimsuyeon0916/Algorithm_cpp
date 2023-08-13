#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

string dist[10000];
char c[4]={'D','S','L','R'};
int A, B; 

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  while(!q.empty()){
    int cur=q.front();
    if(cur==B) return; //이 조건 없으면 시간 초과!
    q.pop();
    int v[4]={(2*cur)%10000, (cur ? cur-1 : 9999), (cur%1000)*10+(cur/1000), (cur%10)*1000+cur/10}; //'S' 조건 빼먹어서 헤맴
    for(int i=0;i<4;i++){
      if(dist[v[i]]=="" && cur!=v[i]){ //cur!=dx[i] 조건 안들어가면 최소 명령어 X. ex) 0 9998
        q.emplace(v[i]);
        dist[v[i]]=dist[cur]+c[i];
      }
    }
  }
}

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=1;i<=T;i++){
    cin >> A >> B;
    fill_n(dist,10000,"");
    BFS(A);
    cout << dist[B] << '\n';
  }
  return 0;
}
#include <iostream>
#include <set>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int M; cin >> M;
  set<int> s; //처음에 for문 안에다가 선언해서 자꾸 0만 나오는 거였음ㅠㅠ
  set<int> all={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  for(int i=1;i<=M;i++){
    string com; cin >> com;
    int x;
    if(com=="add"){
      cin >> x;
      s.emplace(x); //s.insert(x);
    }
    else if(com=="remove"){
      cin >> x;
      s.erase(x);
    }
    else if(com=="check"){
      cin >> x;
      cout << (s.count(x) ? 1 : 0 ) << '\n';
    }
    else if(com=="toggle"){
      cin >> x;
      if(s.count(x)) s.erase(x);
      else s.emplace(x);
    }
    else if(com=="all") s=all;
    else s.clear();
  }
  return 0;
}
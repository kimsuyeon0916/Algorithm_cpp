#include <iostream>
#include <deque>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;
  for(int i=1;i<=T;i++){
    string func; int n;
    cin >> func >> n;
    deque<int> dq;
    int x; char c;
    cin >> c; //'[' 읽기
    for(int i=0;i<n;i++){
      cin >> x; //숫자 읽기
      dq.emplace_back(x);
      if(i<n-1) cin >> c; //',' 읽기
    }
    cin >> c; //']' 읽기

    bool flag=false, error=false;
    for(char ch:func){
      if(ch=='R') flag=!flag;
      else if(ch=='D'){
        if(dq.empty()){
          error=true;
          break;
        }
        else{
          if(flag) dq.pop_back();
          else dq.pop_front();
        }
      }
    }

    if(error) cout << "error" << '\n';
    else{
      cout << '[';
      int size=dq.size();
      for(int i=0;i<size;i++){
        if(flag){
          cout << dq.back();
          dq.pop_back();
        }
        else{
          cout << dq.front();
          dq.pop_front();
        }
        if(i<size-1) cout << ',';
      }
      cout << "]\n";
    }
  }
  return 0;
}
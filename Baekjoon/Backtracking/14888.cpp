#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> op(4); //+,-,*,/
int num[11];
int N, res;
int m=-1000000000, n=1000000000; //최대, 최소

void Backtracking(int seq){
  if(seq==N){
    m=max(m,res); n=min(n,res);
    return;
  }
  int prev = res; //백트래킹 했을 때 대비한 이전 계산 결과
  for(int i=0;i<4;i++){
    if(op[i]){
      if(i==0) res+=num[seq];
      else if(i==1) res-=num[seq];
      else if(i==2) res *= num[seq];
      else if(i==3){
        if(res<0) res=-(-res/num[seq]);
        else res/=num[seq];
      }
      --op[i];
      Backtracking(seq+1);
      res=prev;
      ++op[i];
    }
  }
}

int main()
{
  FASTIO;
  cin >> N;
  for(int i=0;i<N;i++ ) cin >> num[i];
  cin >> op[0] >> op[1] >> op[2] >> op[3];
  res=num[0];
  Backtracking(1);
  cout << m << '\n' << n;
  return 0;
}
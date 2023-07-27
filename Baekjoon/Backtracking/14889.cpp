#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N,diff=2000;
int board[21][21];
bool selected[21];
int t1[21];
int t2[21];

void Backtracking(int num, int seq){
  if(seq==N/2+1){
    int j=1;
    for(int i=1;i<=N;i++){
      if(!selected[i]) t2[j++]=i; //나머지 팀 구성
    }
    int sum1=0, sum2=0;
    for(int i=1;i<=N/2;i++){
      for(int j=1;j<=N/2;j++){
        sum1+=board[t1[i]][t1[j]];
        sum2+=board[t2[i]][t2[j]];
      } 
    }
    diff=min(diff,abs(sum1-sum2));
    return;
  }
  for(int i=num;i<=N;i++){ //i=num 으로 중복 팀 걸러줌.
    if(!selected[i]){
      selected[i]=true;
      t1[seq]=i;
      Backtracking(i+1, seq+1); //i+1 으로 중복 팀 걸러줌.
      selected[i]=false;
    }
  }
}

int main()
{
  FASTIO;
  cin >> N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++) cin >> board[i][j];
  }
  Backtracking(1,1); //숫자, 순서
  cout << diff;
  return 0;
}
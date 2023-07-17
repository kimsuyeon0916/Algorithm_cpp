#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int board[500][500];
int main()
{
  FASTIO;
  int N, M, B;
  cin >> N >> M >> B;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> board[i][j];
    }
  }

  int time = INT_MAX, height=0;
  int s1,s2;
  for(int k=0;k<=256;k++){ //브루트 포스라 모든 경우(0~256)를 확인해야함.
    s1=0; s2=0;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(board[i][j]>k) s1+=board[i][j]-k;
        else if(board[i][j]<k) s2+=k-board[i][j];
      }
    }

    if(k==0) time=2*s1+s2;

    if(B-s2+s1>=0){ //그러나 최대조건도 확인을 해야 함.
      if(2*s1+s2<time){
        time=2*s1+s2;
        height=k;
      } 
      else if(2*s1+s2==time){
        if(k>height) height=k;
      }
    }
  }
  cout << time << " " << height;
  return 0;
}
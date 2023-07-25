#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N;
int result=0;
int col[15];

void Backtraking(int row){
  if(row==N){
    result++;
    return;
  } 
  for(int i=0;i<N;i++){ //모든 열 검사
    col[row]=i; //row행의 열은 i열
    bool promising=true;
    for(int j=0;j<row;j++){ //이전 행들 검사
      if(col[row]==col[j]||abs(col[row]-col[j])==row-j){ //같은 열, 대각선에 있는지 검사
        promising=false;
        break; 
      } 
    }
    if(promising) Backtraking(row+1); //promising 한 경우, 다음 행 검사
  }
}

int main()
{
  FASTIO;
  cin >> N;
  Backtraking(0); //0행부터
  cout << result;
  return 0;
}
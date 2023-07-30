#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n1=0, n2=0, n3=0;
int paper[2187][2187];

bool divide(pair<int,int> v,int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(paper[v.first][v.second]!=paper[v.first+i][v.second+j]){
        return true;        
      }
    }
  }
  paper[v.first][v.second]==-1 ? ++n1 : (!paper[v.first][v.second] ? ++n2 : ++n3);
  return false;
}

void matrix(pair<int,int> v,int size){
  if(divide(v,size)){
    for(int i=0;i<9;i++){ //dx, dy없이 정사각형 시작 좌표 생성
      matrix({v.first+(i/3)*(size/3),v.second+(i%3)*(size/3)},size/3);
    }
  }
}

int main()
{
  FASTIO;
  int N; cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> paper[i][j];
    }
  }
  matrix({0,0},N);
  cout << n1 << '\n' << n2 << '\n' << n3;
  return 0;
}
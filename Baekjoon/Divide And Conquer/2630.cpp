#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int white=0, blue=0;
int paper[129][129];

bool diff_color(pair<int,int> v, int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(paper[v.first][v.second]!=paper[v.first+i][v.second+j]){
        return true;  
      }
    }
  }
  paper[v.first][v.second] ? ++blue : ++white;
  return false;
}

void divide(pair<int,int> v, int size){
  if(diff_color(v,size)){
    int dx[4]={0,0,size/2,size/2}; //좌표 계산 잘못해서 조금 시간 걸림
    int dy[4]={0,size/2,0,size/2};
    for(int i=0;i<4;i++){
      divide({v.first+dx[i],v.second+dy[i]},size/2);
    }
  }
}

int main()
{
  FASTIO;
  int N; cin >> N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> paper[i][j];
    }
  }
  divide({1,1},N);
  cout << white << '\n' << blue;
  return 0;
}
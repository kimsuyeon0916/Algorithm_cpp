#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int video[64][64];

bool divide(pair<int,int> v, int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(video[v.first][v.second]!=video[v.first+i][v.second+j]){
        return true;
      }
    }
  }
  cout << video[v.first][v.second];
  return false;
}

void quad_tree(pair<int,int> v, int size){
  if(divide(v,size)){
    cout << '(';
    int dx[4]={0,0,size/2,size/2};
    int dy[4]={0,size/2,0,size/2};
    for(int i=0;i<4;i++){
      quad_tree({v.first+dx[i],v.second+dy[i]},size/2);
    }
    cout << ')';
  }
}


int main()
{
  FASTIO;
  int N; cin >> N;
  for(int i=0;i<N;i++){
    string input; cin >> input;
    for(int j=0;j<N;j++){
      video[i][j] = input[j] -'0'; //처음에 숫자 변환 안해줘서 틀림ㅋ
    }
  }
  quad_tree({0,0},N);
  return 0;
}
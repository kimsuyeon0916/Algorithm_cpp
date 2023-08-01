#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//애초에 배열/벡터 필요 X => 메모리 초과 ->시간 엄청 걸림
int N, r, c, cnt=0;

bool divide(pair<int,int> v, int size){
  if(r>=v.first && c>=v.second && r<v.first+size && c<v.second+size) return true;
  return false;
}

void Z(pair<int,int> v, int size){
  if(divide(v,size)){  
    if(v.first==r && v.second==c){
      cout << cnt;
      exit(0); //바로 재귀 종료
    } 
    for(int i=0;i<4;i++) Z({v.first+(size/2)*(i/2),v.second+(size/2)*(i%2)},size/2); 
  }
  else cnt+=size*size;
}

int main()
{
  FASTIO;
  cin >> N >> r >> c;
  Z({0,0},pow(2,N));
  return 0;
}
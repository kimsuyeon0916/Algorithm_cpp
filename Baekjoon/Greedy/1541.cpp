#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int n;
  char c;
  cin >> n;
  int part=0, minus_cnt=0, sum=n; //part는 부분합을 의미하는 변수
  while(cin >> c >> n){ //EOI
    if(c=='-'){
      if(!minus_cnt) sum+=part; //-가 처음 나온 경우
      else sum-=part; //-가 2번 이상 나온 경우
      ++minus_cnt;
      part=0;
    } 
    part+=n;
  }
  cout << (minus_cnt ? sum-part : sum+part); //마지막 부분합을 처리
  return 0;
}
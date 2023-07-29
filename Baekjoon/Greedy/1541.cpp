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
  int part=0, minus_cnt=0, sum=n;
  while(cin >> c >> n){ //EOI
    if(c=='-'){
      if(minus_cnt) sum-=part;
      else sum+=part;
      ++minus_cnt;
      part=0;
    } 
    part+=n;
  }
  cout << (minus_cnt ? sum-part : sum+part);
  return 0;
}
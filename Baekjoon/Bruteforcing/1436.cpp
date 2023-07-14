#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;

  int count=0;
  int i=665;
  while(count!=N){
    i++;
    int j=i;
    while(j>=666){
      if(j%1000==666){
        count++; 
        break;
      } 
      j/=10;
    } 
  }
  cout << i;
  return 0;
}

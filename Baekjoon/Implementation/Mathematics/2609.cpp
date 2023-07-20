#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int n1, n2; cin >> n1 >> n2;

  int divisor=0, multiple=0;
  for(int i=max(n1,n2);i>=1;i--){
    if(n1%i==0 && n2%i==0){
      divisor=i;
      break;
    }
  }
  multiple=divisor*(n1/divisor)*(n2/divisor);
  
  cout << divisor << '\n' << multiple;
  return 0;
}
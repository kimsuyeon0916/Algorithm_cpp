#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int n=0,sum;
  char c;
  bool flag=true;
  cin >> sum;
  while(cin >> c >> n){ //EOI
    if(c=='-') flag=false;
    
    if(flag) sum+=n;
    else sum-=n;
  }
  cout << sum;
  return 0;
}
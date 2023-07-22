#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int A,B,V; cin >> A >> B >> V;
  int day=(V-A)/(A-B)+1;
  if((V-A)%(A-B)!=0) day++;
  cout << day;
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int a,b,c,d,e,f;
  int x, y;
  cin >> a >> b >> c >> d >> e >> f;

  x=(c*e-f*b)/(a*e-d*b);
  y=(c*d-f*a)/(b*d-e*a);
  
  cout << x << " " << y;
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  long long A, B, C;
  cin >> A >> B >> C;
  long long res = 1;
  while (B > 0)
  {
    if (B % 2 == 1)
        res = (res * A) % C;
    A = ((A % C) * (A % C)) % C;
    B /= 2;
  }
  cout << res;
}
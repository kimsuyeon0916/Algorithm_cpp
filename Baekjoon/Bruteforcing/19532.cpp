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

  /* 수식 전개 */
  x=(c*e-f*b)/(a*e-d*b);
  y=(c*d-f*a)/(b*d-e*a);

  /* 완전 탐색 */
  for (int i = -999; i < 1000; i++) {
		for (int j = -999; j < 1000; j++) {
			if (a * i + b * j == c) {
				if (d * i + e * j == f) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}

  cout << x << " " << y;
  return 0;
}

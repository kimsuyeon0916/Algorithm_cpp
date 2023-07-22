#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  int i=1, r=1;
  while(i<N){ //처음에 등호 들어가서 틀림
    i+=r*6;
    r++;
  }
  cout << r;
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  vector<int> v(N);
  for(int i=0;i<N;i++) cin >> v[i];
  sort(v.begin(),v.end());
  for(int i=0;i<N;i++) cout << v[i] << '\n';
  return 0;
}
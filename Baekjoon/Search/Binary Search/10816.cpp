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
  int M; cin >> M;
  for(int i=0;i<M;i++){
    int x;  cin >> x;
    int count=0;
    count=equal_range(v.begin(),v.end(),x).second-equal_range(v.begin(),v.end(),x).first;
    cout << count << " ";
  }
  return 0;
}
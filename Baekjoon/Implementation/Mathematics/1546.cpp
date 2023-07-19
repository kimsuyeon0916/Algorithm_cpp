#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  long double max_score=0,average=0,s;
  for(int i=0;i<N;i++){
    cin >> s;
    average+=s;
    max_score=max(s,max_score);
  }
  average=average/max_score*100/N;

  cout << average;
  return 0;
}
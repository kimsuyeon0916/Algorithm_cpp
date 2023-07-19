#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  long double max_score=0,s;
  vector<long double> score(N);
  for(int i=0;i<N;i++){
    cin >> s;
    score[i]=s;
    max_score=max(s,max_score);
  }
  long double average=0;
  for(long double n:score){
    n=n/max_score*100;
    average+=n;
  }
  average/=N;
  cout << average;
  return 0;
}
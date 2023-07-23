#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int K; cin >> K;
  vector<int> v;
  int input;
  for(int i=0;i<K;i++){
    cin >> input;
    if(input) v.emplace_back(input);
    else v.pop_back();
  }
  cout << accumulate(v.begin(),v.end(), 0);
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  vector<int> v(5);
  int mean=0;
  for(int i=0;i<5;i++){
    cin >> v[i];
    mean+=v[i];
  } 
  sort(v.begin(),v.end());
  cout << mean/5 << '\n' << v[2];
  return 0;
}
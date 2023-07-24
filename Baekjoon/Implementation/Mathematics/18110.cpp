#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int n; cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];
  
  sort(v.begin(),v.end());
  double diff=0, count=0;
  for(int j=round(n*0.15);j<n-round(n*0.15);j++){
    diff+=v[j];
    count++;
  }
  if(count) diff=round(diff/count); //0으로 나눌 수 X

  cout << diff;
  return 0;
}
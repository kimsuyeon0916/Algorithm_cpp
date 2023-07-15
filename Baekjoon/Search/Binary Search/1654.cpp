#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

long long K, N, low, high, mid, ans=0;
int main()
{
  FASTIO;
  cin >> K >> N;
  vector<int> lan(K);
  for(int i=0;i<K;i++) cin >> lan[i];
  sort(lan.begin(),lan.end());
  low = 1, high = lan[K-1];
  while(low <= high){
    mid = (low+high)/ 2;
    int count=0;
    for(int i=0;i<K;i++){
      count+=(lan[i]/mid);
    }
    if(count>=N){
      low=mid+1;
      ans=max(ans,mid);
    } 
    else high=mid-1;
  }
  cout << ans;
  return 0;
}

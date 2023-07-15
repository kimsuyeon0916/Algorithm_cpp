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
  vector<long long> lan(K);
  for(int i=0;i<K;i++) cin >> lan[i];
  sort(lan.begin(),lan.end()); //정렬
  low = 1, high = lan[K-1];
  while(low <= high){ //이분 탐색의 조건문
    mid = (low+high)/ 2;
    int count=0;
    for(int i=0;i<K;i++){
      count+=(lan[i]/mid);
    }
    if(count>=N){
      low=mid+1;
      ans=max(ans,mid); //더 긴 길이로도 만들 수 있는지 검사
    } 
    else high=mid-1;
  }
  cout << ans;
  return 0;
}

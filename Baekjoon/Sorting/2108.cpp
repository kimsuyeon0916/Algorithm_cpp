#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int arr[500000];
vector<int> mode_arr; //최빈수들 담는 배열
int N, max_freq=1;
int mean,median,mode,range;
int main()
{
  FASTIO;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> arr[i];
    mean+=arr[i];
  }

  sort(arr,arr+N);
  mean=round((double)mean/N);
  median=arr[N/2];
  range=abs(arr[N-1]-arr[0]);

  int start_index=0;
  for(int i=0;i<N;i++){ //최대 빈도수 구하기
    if(arr[start_index]<arr[i]){
      max_freq=max(max_freq,i-start_index);
      start_index=i;
    } 
  }
  for(int i=0;i<N-(max_freq-1);i++){ //최빈수들 벡터에 담기
    if(arr[i+(max_freq-1)]==arr[i]) mode_arr.emplace_back(arr[i]);
  }
  sort(mode_arr.begin(),mode_arr.end());
  mode=(mode_arr.size()==1 ? mode_arr[0] : mode_arr[1]);
  
  cout << mean << '\n' << median << '\n'<< mode << '\n' << range;
  return 0;
}
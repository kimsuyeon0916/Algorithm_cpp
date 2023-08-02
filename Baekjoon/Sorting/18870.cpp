#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_INPUT 1000000000
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  vector<pair<int,int>> v(N+1); //입력순서, 크기별 인덱스
  for(int i=0;i<N;i++){
    cin >> v[i].first; //원소 크기
    v[i].second=i; //입력 순서
  }
  v[N].first=MAX_INPUT; v[N].second=v[N-1].second+1;
  
  sort(v.begin(),v.end()); //크기 순 정렬
  int rank=0; 
  for(int i=1;i<=N;i++){ //N번째 인덱스 포함
    bool flag=false;
    if(v[i-1].first<v[i].first) flag=true;
    v[i-1].first=v[i-1].second; //입력 순서
    v[i-1].second=(flag ? rank++ : rank); //크기 별 인덱스
  }
  sort(v.begin(),v.end()-1); //입력 순서 순 정렬
  
  for(int i=0;i<N;i++) cout << v[i].second << ' ';
  return 0;
}
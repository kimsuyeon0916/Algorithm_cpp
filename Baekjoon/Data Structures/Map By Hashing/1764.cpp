#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  map<string,int> m; //인덱스가 string이라 map 써야 함
  vector<string> v;
  for(int i=1;i<=N;i++){
    string input; cin >> input;
    m.emplace(input,i); //m.insert({input,0});
  }
  for(int i=1;i<=M;i++){
    string input; cin >> input;
    if(m.find(input)!=m.end()) v.emplace_back(m.find(input)->first);  
  }
  sort(v.begin(),v.end()); //결과 벡터는 자동 정렬이 아니라서 해줘야 함
  
  cout << v.size() <<'\n';
  for(string res:v) cout << res << '\n';
  return 0;
}
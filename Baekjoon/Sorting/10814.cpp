#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  vector<string> member[201]; //처음에 벡터배열 아니고 벡터로 선언해서 에러남ㅋㅋ
  string name;
  int age;
  for(int i=1;i<=N;i++){
    cin >> age >> name;
    member[age].emplace_back(name);
  }
  for(int i=1;i<=200;i++){
    for(string name:member[i]){
      cout<< i << " " << name << '\n';
    }
  }
  return 0;
}
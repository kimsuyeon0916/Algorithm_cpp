#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool comp(string s1, string s2){
  if(s1.length()==s2.length()) return s1<s2; //길이 같으면 오름차순(사전순)정렬
  return s1.length()<s2.length(); //기본은 길이 오름차순 정렬
}

vector<string> v;
int main()
{
  FASTIO;
  int N; cin >> N;
  string input;
  for(int i=0;i<N;i++){
    cin >> input;
    if(find(v.begin(), v.end(), input)==v.end()) v.emplace_back(input);
  }

  sort(v.begin(), v.end(),comp); 
  
  for(string str:v) cout << str << '\n';
  return 0;
}
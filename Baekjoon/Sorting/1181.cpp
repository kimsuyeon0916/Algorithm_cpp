#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool comp(string s1, string s2){
  if(s1.length()==s2.length()) return s1<s2; //길이 같으면 오름차순(사전순)정렬
  return s1.length()<s2.length(); //기본은 길이 오름차순 정렬
}

string str[20000];
int main()
{
  FASTIO;
  int N; cin >> N;
  string input;
  for(int i=0;i<N;i++){
    cin >> str[i];
  }

  sort(str, str+N, comp); 

  for(int i=0;i<N;i++){
    if(i>0 && str[i]==str[i-1]) continue;
    cout << str[i] << '\n';
  } 
  return 0;
}
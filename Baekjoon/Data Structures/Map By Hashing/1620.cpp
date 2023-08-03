#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  map<int,string> i_s; //int to string
  map<string,int> s_i; //string to int
  for(int i=1;i<=N;i++){
    string input; cin >> input;
    i_s.insert({i,input}); //emplace(i,input)
    s_i.insert({input,i}); //emplace(input,i)
  } 
  for(int i=1;i<=M;i++){
    string input; cin >> input;
    if(isdigit(input[0])) cout << i_s[stoi(input)] << '\n';
    else cout << s_i[input] << '\n';
  }
  return 0;
}
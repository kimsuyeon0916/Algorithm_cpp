#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<char> result;
int main()
{
  FASTIO;
  int n; cin >> n;
  vector<int> s(n);
  stack<int> st;
  for(int i=0;i<n;i++) cin >> s[i];
  vector<int> input(s); 
  sort(input.begin(),input.end());
  for(int i=0;i<n;i++){
    if(!st.empty()){
      if(st.top()>s[i]){
        cout << "NO";
        return 0;
      }
      else if(st.top()<s[i]){
        while(!input.empty() && input[0]<=s[i]){
          st.emplace(input[0]);
          result.emplace_back('+');
          input.erase(input.begin());
        }
        st.pop();
        result.emplace_back('-');
      }
      else{ //st.top()==s[i]
        st.pop();
        result.emplace_back('-');
      }
    }
    else {
      while(!input.empty() && input[0]<=s[i]){
        st.emplace(input[0]);
        result.emplace_back('+');
        input.erase(input.begin());
      }
      st.pop();
      result.emplace_back('-');
    }
  }
  for(char c:result) cout << c << '\n';
  return 0;
}
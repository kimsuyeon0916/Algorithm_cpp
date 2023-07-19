#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  while(true){
    int n; cin >> n;
    if(n==0) break;

    int palindrome=0, i=n;
    while(i>0){
      palindrome*=10; 
      palindrome+=i%10;
      i/=10;
    }
    
    cout << (palindrome==n?"yes":"no") << '\n';
  }
  return 0;
}
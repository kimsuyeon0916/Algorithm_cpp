#include <iostream>
#include <algorithm>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define M 1234567891
using namespace std;

long long value=0;
int main()
{
  FASTIO;
  int L; cin >> L;
  string input; cin >> input;
  long long r=1;
  for(int i=0;i<input.length();i++){
    value+=((input[i]-96)*r)%M;
    r=(r*31)%M;
  }
  cout << value % M;
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;



int main()
{
  FASTIO;
  int n, res=4;
  cin >> n;
  for(int a=sqrt(n);a>=1;a--){
    int i=n-a*a;
    if(i==0) res=min(res,1);
    for(int b=sqrt(i);b>=1 && a>=b ;b--){ //a>=b 추가하니 시간 감소
      int j=i-b*b;
      if(j==0) res=min(res,2);
      for(int c=sqrt(j);c>=1 && b>=c;c--){ //b>=c 추가하니 시간 감소
        int k=j-c*c;
        if(k==0) res=min(res,3);
        for(int d=sqrt(k);d>=1 && c>=d;d--){ //c>=d 추가하니 시간 감소
          int l=k-d*d;
          if(k==0) res=min(res,4);
        }
      }
    }
  }
  cout << res;
  return 0;
}
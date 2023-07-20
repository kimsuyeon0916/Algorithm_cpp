#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int n1, n2; cin >> n1 >> n2;

  int divisor=0, multiple=0;
  for(int i=max(n1,n2);i>=1;i--){ 
    if(n1%i==0 && n2%i==0){
      divisor=i;
      break;
    }
  }
  multiple=divisor*(n1/divisor)*(n2/divisor); //=(n1*n1)/divisor

  cout << divisor << '\n' << multiple;
  return 0;
}

//유클리드 호제법
/*
int gcd(int a, int b) { //최대 공약수
	int r = a % b; //a가 큰 수, b가 작은 수
	while (r != 0) {
		a = b; 
		b = r; 
		r = a % b; 
	}
	return b;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) { //최소 공배수
	return (a * b) / gcd(a, b);
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MOD 1000000007
using namespace std;

long long fact(int n,int k) { //재귀는 호출 너무많이 해서 메모리 및 시간 초과
  long long result = 1;
  for (int i = n; i >= k; i--) {
      result = (result * i) % MOD;
  }
  return result;
}

long long power(long long a, int b){
    if(b==1) return a % MOD;
    long long half = power(a,b/2);
    if(b%2==1) return half*half%MOD * a%MOD; //홀수 제곱수
    else return half*half%MOD; //짝수 제곱수
}

int main()
{
  FASTIO;
  long long N,K;
  cin >> N >> K;
  cout << (fact(N,N-K+1)*power(fact(K,1),MOD-2))%MOD; //페르마 소정리
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  long long A, B, C;
  cin >> A >> B >> C;
  long long res = 1; //제곱이라 무조건 long long 으로
  while (B > 0)
  {
    if (B % 2 == 1) //제곱수가 홀수인 경우
        res = (res * A) % C; //한번 더 곱해줌
    A = ((A % C) * (A % C)) % C; 
    B /= 2; //log B번 하기 위해서 B를 줄여나간다는 개념 -> 시간 복잡도 : log B
  }
  cout << res;
}
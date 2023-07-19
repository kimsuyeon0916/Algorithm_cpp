#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  vector<int> tri(3);
  vector<int> end(3); //EOI
  while(true){
    cin >> tri[0] >> tri[1] >> tri[2];
    if(tri==end) return 0; //종료 조건

    sort(tri.begin(),tri.end());

    if(pow(tri[2],2)==pow(tri[0],2)+ pow(tri[1],2)) cout << "right" << '\n';
    else cout << "wrong" << '\n';
  }
  return 0;
}
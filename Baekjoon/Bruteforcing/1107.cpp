#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  bool btn[10]={0,};
  for(int i=1;i<=M;i++){
    int x; cin >> x;
    btn[x]=true; //고장난 버튼 표시
  }
  if(M==10){ //안걸러주면 밑의 while에서 무한루프
    cout << abs(N-100);
    return 0;
  } 
  
  int inc=N, des=N, cnt=0;
  bool inc_flag=true, des_flag=true;
  while(inc_flag && des_flag){ //증가, 감소 둘 다 불가능한 경우
    inc_flag=false, des_flag=false; 
    int inc_cnt=0, des_cnt=0; 
    int i=inc, j=des;
    if(inc==0){
      if(btn[inc]) inc_flag=true;
      ++inc_cnt;
    } 
    if(des==0){
      if(btn[des]) des_flag=true;
      ++des_cnt;
    } 
    if(des<0) des_flag=true;

    while(i>0 || j>0){ //i와 j의 자릿수가 다를 수 있음
      if(i>0 && btn[i%10]) inc_flag=true; //증가 숫자 안되는 경우(증/감 자릿수 다른 경우를 위해 i>0)
      if(j>0 && btn[j%10]) des_flag=true; //감소 숫자 안되는 경우(증/감 자릿수 다른 경우를 위해 j>0)
      if(i>0) ++inc_cnt; //증가수 자릿수
      if(j>0) ++des_cnt; //감소수 자릿수
      i/=10; j/=10;
    }
    if(!inc_flag && !des_flag) cnt=min(inc_cnt,des_cnt);
    else{
      if(!inc_flag) cnt=inc_cnt;
      else cnt=des_cnt;
    }
    cnt+=inc-N;
    ++inc; --des;
  }

  cout << min(cnt,abs(N-100)); //원래 채널에서 +,-만 눌렀을 때의 길이
  return 0;
}
#include <iostream>
#include <string>
#include <queue>
using namespace std;

void init(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

string input[2000001];
queue<string> Queue;

int main(){
  init();
  int n; cin >> n;
  cin.ignore();
  for(int i=1;i<=n;i++) getline(cin,input[i]);

  for(int i=1;i<=n;i++){
    if(input[i].substr(0,4)=="push") Queue.push(input[i].substr(5));
    else if(input[i]=="pop"){
      if(Queue.empty()) cout << "-1\n";
      else{
        cout << Queue.front() << '\n';
        Queue.pop();
      }
    }
    else if(input[i]=="size"){
      cout << Queue.size() << '\n';
    }
    else if(input[i]=="empty"){
      cout << Queue.empty() << '\n';
    }
    else if(input[i]=="front"){
      if(Queue.empty()) cout << "-1\n";
      else cout << Queue.front() << '\n';
    }
    else if(input[i]=="back"){
      if(Queue.empty()) cout << "-1\n";
      else cout << Queue.back() << '\n';
    }
  }

  return 0;
}
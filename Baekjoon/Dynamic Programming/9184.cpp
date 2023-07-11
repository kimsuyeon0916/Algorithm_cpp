#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
vector<vector<vector<int>>> w(21,vector<vector<int>>(21,vector<int>(21)));


int main(){
    FASTIO;

    int a,b,c;
    int res;
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            for(int k=0;k<21;k++){
                if(i==0||j==0||k==0){
                    w[i][j][k]=1;
                }
                else if(i<j&&j<k){
                    w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                }else{
                    w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
                }
            }
        }
    }

    while(true){
        
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
        
        if(a<=0||b<=0||c<=0){
            cout<<w[0][0][0]<<'\n';
        }
        else if(a>20||b>20||c>20){
            cout<<w[20][20][20]<<'\n';
        }else{
            cout<<w[a][b][c]<<'\n';
        }
    }
    return 0;
}
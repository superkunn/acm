#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PB push_back
#define ALL(X) (X).begin(),(X).end()
typedef vector<int> vi;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,sum;
    cin>>n>>sum;
    vi v(n);
    vi t(n);
    REP(i,1,n)v[i-1]=i;
    do{
        
        REP(i,0,n-1)t[i]=v[i];
        REP(i,1,n-1){
            REP(j,0,n-1-i){
                t[j]+=t[j+1];
            }
        }
        if(sum==t[0]){
            REP(i,0,n-1)cout<<v[i]<<" ";
            break;
        }
    }while(next_permutation(ALL(v)));
    return 0;
}

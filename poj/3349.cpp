#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=100000+10;
const int MOD=49999;
vector<int> v[50000];
int a[MAXN][6];
bool same(int x,int y){
    for(int i=0;i<6;i++){
        bool f=true;
        for(int j=0;j<6;j++){
            if(a[x][j]!=a[y][(j+i)%6]){
                f=false;
                break;
            }
        }
        if(f)return true;
    }
    for(int i=0;i<6;i++){
        bool f=true;
        for(int j=0;j<6;j++){
            if(a[x][j]!=a[y][(i-j+6)%6]){
                f=false;
                break;
            }
        }
        if(f)return true;
    }
    return false;
}
int fun(int x){
    if(x<0)x=-x;
    return x;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll now=0;
        ll w1=1;
        ll w2=0;
        for(int j=0;j<6;j++){
            scanf("%d",&a[i][j]);
            now+=a[i][j];
            w1=(w1*a[i][j])%MOD;
        }
        for(int j=0;j<6;j++){
            w2+=fun(a[i][j]-a[i][(j+1)%6]);
        }
        now%=MOD;
        now+=w1+w2;
        now%=MOD;
        for(int j=0;j<v[now].size();j++){
            if(same(v[now][j],i)){
                puts("Twin snowflakes found.");
                return 0;
            }
        }
        v[now].push_back(i);
    }
    puts("No two snowflakes are alike.");
    return 0;
}

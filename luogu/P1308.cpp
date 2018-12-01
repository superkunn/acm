#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=1e6+10;
char a[MAXN];
char s[MAXN];
int main(){
    scanf("%s",a+1);
    getchar();
    int len1=strlen(a+1);
    len1++;
    auto fun = [&](char &c){
        if('A'<=c&&c<='Z'){
            c=c-'A'+'a';
        }
    };
    rep(i,0,len1-1){
        fun(a[i]);
    }
    a[0]=a[len1]=' ';
    len1++;
    scanf("%[^\n]",s+1);
    int len2=strlen(s+1);
    len2++;
    rep(i,0,len2-1){
        fun(s[i]);
    }
    s[0]=s[len2]=' ';
    len2++;
    vi ans;
    auto check = [&](int x){
        rep(i,0,len1-1){
            if(a[i]!=s[x+i]){
                return false;
            }
        }
        return true;
    };
    rep(i,0,len2-1-len1+1){
        if(check(i)){
            ans.pb(i);
        }
    }
    if(ans.size()==0){
        puts("-1");
    }else{
        printf("%d %d\n",(int)ans.size(),ans[0]);
    }
    return 0;
}


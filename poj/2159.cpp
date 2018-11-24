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
int cnt1[30],cnt2[30];
int main(){
    string a;
    string b;
    cin>>a>>b;
    if(a.length()!=b.length()){
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<a.length();i++){
        cnt1[a[i]-'A']++;
        cnt2[b[i]-'A']++;
    }
    sort(cnt1,cnt1+26);
    sort(cnt2,cnt2+26);
    for(int i=0;i<26;i++){
        if(cnt1[i]!=cnt2[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}

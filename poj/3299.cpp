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
int main(){
    char a[5];
    char b[5];
    while(scanf("%s",a),a[0]!='E'){
        float x,y;
        scanf("%f%s%f",&x,b,&y);
        if(a[0]=='T'&&b[0]=='D'){
            float e=6.11*exp(5417.753*(1.0/273.16-1.0/(y+273.16)));
            float h=0.5555*(e-10.0);
            printf("T %.1f D %.1f H %.1f\n",x,y,x+h);
        }else if(a[0]=='D'&&b[0]=='T'){
            swap(x,y);
            float e=6.11*exp(5417.753*(1.0/273.16-1.0/(y+273.16)));
            float h=0.5555*(e-10.0);
            printf("T %.1f D %.1f H %.1f\n",x,y,x+h);
        }else if(a[0]=='T'&&b[0]=='H'){
            float h=y-x;
            float e=h/0.5555+10.0;
            float w=1.0/273.16-log(e/6.11)/5417.753;
            printf("T %.1f D %.1f H %.1f\n",x,1/w-273.16,y);
        }else if(a[0]=='H'&&b[0]=='T'){
            swap(x,y);
            float h=y-x;
            float e=h/0.5555+10.0;
            float w=1.0/273.16-log(e/6.11)/5417.753;
            printf("T %.1f D %.1f H %.1f\n",x,1/w-273.16,y);
        }else if(a[0]=='D'&&b[0]=='H'){
            float e=6.11*exp(5417.753*(1.0/273.16-1.0/(x+273.16)));
            float h=0.5555*(e-10.0);
            printf("T %.1f D %.1f H %.1f\n",y-h,x,y);
        }else{
            swap(x,y);
            float e=6.11*exp(5417.753*(1.0/273.16-1.0/(x+273.16)));
            float h=0.5555*(e-10.0);
            printf("T %.1f D %.1f H %.1f\n",y-h,x,y);
        }
    }
    return 0;
}

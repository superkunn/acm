#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef double ld;
const int MAXN=5e5+233;
const ld PI=-acos(-1.0);
struct cp{
    ld x,y;
    cp(ld _x=0.0,ld _y=0.0){
        x=_x;
        y=_y;
    }
    cp operator+(const cp &b)const{
        return cp(x+b.x,y+b.y);
    }
    cp operator-(const cp &b)const{
        return cp(x-b.x,y-b.y);
    }
    cp operator*(const cp &b)const{
        return cp(x*b.x-y*b.y,x*b.y+y*b.x);
    }
};
void change(cp y[],int len){
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++){
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k){
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void fft(cp y[],int len,int on){
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        cp wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h){
            cp w(1,0);
            for(int k=j;k<j+h/2;k++){
                cp u=y[k];
                cp t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1){
        rep(i,0,len-1){
            y[i].x/=len;
        }
    }
}
int a[MAXN];
ll cnt[MAXN];
cp x[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    rep(kase,1,T){
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        rep(i,1,n){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        sort(a+1,a+1+n);
        int m=2*a[n];
        int len=1;
        for(;len<m+2;len<<=1);
        rep(i,0,m){
            x[i]=cp(cnt[i],0);
        }
        rep(i,m+1,len-1){
            x[i]=cp(0,0);
        }
        fft(x,len,1);
        rep(i,0,len-1){
            x[i]=x[i]*x[i];
        }
        fft(x,len,-1);
        //
        rep(i,0,m){
            cnt[i]=(ll)(x[i].x+0.5);
        }
        rep(i,1,n){
            cnt[a[i]+a[i]]--;
        }
        rep(i,1,m){
            cnt[i]/=2;
            cnt[i]+=cnt[i-1];
        }
        //
        ll w=0;
        rep(i,1,n){
            w+=cnt[m]-cnt[a[i]];
            //一小一大
            w-=1LL*(i-1)*(n-i);
            //两大
            w-=1LL*(n-i)*(n-i-1)/2;
            //一本身一其他
            w-=n-1;
        }
        ll tot=1LL*n*(n-1)*(n-2)/6;
        printf("%.7lf\n",(ld)(w)/tot);
    }
    return 0;
}

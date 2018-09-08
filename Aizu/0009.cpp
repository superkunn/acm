#include<cstdio>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(a,x) memset(a,x,sizeof(a))
const int MAXN=1e7+5;
int prime[MAXN];//1 base
bool is_prime[MAXN];
int sum[MAXN];
int sieve(int n){
    int cnt=0;
    rep(i,0,n)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    rep(i,2,n){
        if(is_prime[i]){
            prime[++cnt]=i;
            for(int j=i*2;j<=n;j+=i)is_prime[j]=false;
        }
        sum[i]=sum[i-1]+is_prime[i];
    }
    return cnt;
}
int main(){
    sieve(10000000);
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",sum[n]);
    }
    return 0;
}

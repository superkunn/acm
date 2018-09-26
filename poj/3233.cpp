#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=63;
int n,k,m;
struct Matrix{
    long long a[MAXN][MAXN];
    void init(){
        memset(a,0,sizeof(a));
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%lld ",a[i][j]);
            }
            puts("");
        }
    }
};
Matrix operator*(const Matrix& lhs,const Matrix& rhs){
    Matrix res;
    res.init();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                res.a[i][j]+=lhs.a[i][k]*rhs.a[k][j]%m;
                if(res.a[i][j]>m)res.a[i][j]-=m;
            }
        }
    }
    return res;
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    int nn=n;
    n*=2;
    Matrix base,ans;
    base.init();
    ans.init();
    for(int i=0;i<nn;i++){
        for(int j=0;j<nn;j++){
            scanf("%lld",&base.a[i][j]);
            base.a[i][j]%=m;
            ans.a[i][j]=base.a[i][j];
        }
    }
    for(int i=0;i<nn;i++){
        base.a[i+nn][i]=base.a[i+nn][i+nn]=1;
    }
    while(k){
        if(k&1)ans=base*ans;
        base=base*base;
        k>>=1;
    }
    for(int i=0;i<nn;i++){
        for(int j=0;j<nn;j++){
            printf("%lld ",ans.a[i+nn][j]%m);
        }
        puts("");
    }
    return 0;
}

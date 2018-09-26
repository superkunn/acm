#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
struct Matrix{
    long long a[5][5];
    void init(){
        memset(a,0,sizeof(a));
    }
    void print(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                printf("%lld%c",a[i][j]," \n"[j==4]);
            }
        }
    }
};
Matrix operator*(const Matrix& lhs,const Matrix& rhs){
    Matrix res;
    res.init();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                res.a[i][j]+=lhs.a[i][k]*rhs.a[k][j]%MOD;
            }
            res.a[i][j]%=MOD;
        }
    }
    return res;
}
int main(){
    long long n;
    while(~scanf("%lld",&n)){
        Matrix base;
        base.init();
        long long aa,ax,ay,bb,bx,by;
        scanf("%lld%lld%lld%lld%lld%lld",&aa,&ax,&ay,&bb,&bx,&by);
        base.a[0][0]=ax*bx%MOD;
        base.a[0][1]=ay*bx%MOD;
        base.a[0][2]=ax*by%MOD;
        base.a[0][3]=ay*by%MOD;

        base.a[1][1]=bx%MOD;
        base.a[1][3]=by%MOD;

        base.a[2][2]=ax%MOD;
        base.a[2][3]=ay%MOD;

        base.a[3][3]=1;

        base.a[4][0]=1;
        base.a[4][4]=1;

        Matrix ans;
        ans.init();
        ans.a[0][0]=aa*bb%MOD;
        ans.a[1][0]=bb%MOD;
        ans.a[2][0]=aa%MOD;
        ans.a[3][0]=1;
        ans.a[4][0]=0;

        while(n){
            if(n&1)ans=base*ans;
            base=base*base;
            n>>=1;
        }
        printf("%lld\n",ans.a[4][0]);
    }
    return 0;
}

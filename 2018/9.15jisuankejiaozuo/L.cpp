#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
struct Matrix {
    long long a[9][9];
};
Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix ret;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ret.a[i][j] = 0;
            for (int k = 0; k < 9; ++k) {
                ret.a[i][j] += lhs.a[i][k] * rhs.a[k][j];
            }
            ret.a[i][j] %= MOD;
        }
    }
    return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    Matrix base;
    Matrix x;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            base.a[i][j]=0;
            x.a[i][j]=0;
        }
    }
    base.a[3][0]=1;
    base.a[6][0]=1;

    base.a[0][1]=1;
    base.a[3][1]=1;
    base.a[6][1]=1;

    base.a[0][2]=1;
    base.a[3][2]=1;

    base.a[1][3]=1;
    base.a[4][3]=1;
    base.a[7][3]=1;

    base.a[1][4]=1;
    base.a[7][4]=1;

    base.a[1][5]=1;
    base.a[4][5]=1;

    base.a[2][6]=1;
    base.a[8][6]=1;

    base.a[5][7]=1;
    base.a[8][7]=1;

    base.a[2][8]=1;
    base.a[5][8]=1;

    for(int i=0;i<9;i++){
        x.a[0][i]=1;
    }

    while(T--){
        long long n;
        scanf("%lld",&n);
        if(n==1){
            puts("3");
        }else if(n==2){
            puts("9");
        }else{
            n-=2;
            Matrix b=x;
            Matrix c=base;
            while(n){
                if(n&1)b=b*c;
                c=c*c;
                n>>=1;
            }
            long long ans=0;
            for(int i=0;i<9;i++){
                ans=(ans+b.a[0][i])%MOD;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

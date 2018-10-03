#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int MOD=10000;
struct Matrix{
    ll a[2][2];
    void init(){
        memset(a,0,sizeof(a));
    }
};
Matrix operator*(const Matrix& lhs,const Matrix& rhs){
    Matrix res;
    res.init();
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                res.a[i][j]+=lhs.a[i][k]*rhs.a[k][j];
            }
            res.a[i][j]%=MOD;
        }
    }
    return res;
}
int main(){
    Matrix b;
    b.init();
    b.a[0][0]=b.a[1][0]=1;
    int x;
    while(scanf("%d",&x),x!=-1){
        if(x<=1){
            printf("%d\n",x);
            continue;
        }
        Matrix base;
        base.init();
        base.a[0][1]=base.a[1][0]=base.a[1][1]=1;
        x--;
        Matrix ans=b;
        while(x){
            if(x&1)ans=base*ans;
            base=base*base;
            x>>=1;
        }
        printf("%d\n",ans.a[0][0]);
    }
    return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=10007;
struct Matrix{
    long long a[3][3];
    void init(){
        memset(a,0,sizeof(a));
    }
};
Matrix operator*(const Matrix& lhs,const Matrix& rhs){
    Matrix res;
    res.init();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                res.a[i][j]=(res.a[i][j]+lhs.a[i][k]*rhs.a[k][j])%MOD;
            }
        }
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        Matrix base;
        base.init();
        base.a[0][0]=2;base.a[0][1]=1;
        base.a[1][0]=2;base.a[1][1]=2;base.a[1][2]=2;
                       base.a[2][1]=1;base.a[2][2]=2;
        Matrix ans;
        ans.init();
        ans.a[0][0]=2;
        ans.a[1][0]=2;
        ans.a[2][0]=0;
        x--;
        while(x){
            if(x&1)ans=base*ans;
            base=base*base;
            x>>=1;
        }
        printf("%lld\n",ans.a[0][0]%MOD);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int p[10];
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    rep(i,1,9){
        p[i]=i;
    }
    bool f=false;
    do{
        int x=p[1]*100+p[2]*10+p[3];
        int y=p[4]*100+p[5]*10+p[6];
        int z=p[7]*100+p[8]*10+p[9];
        if(x*b==a*y&&b*z==c*y){
            f=true;
            printf("%d %d %d\n",x,y,z);
        }
    }while(next_permutation(p+1,p+1+9));
    if(!f)puts("No!!!");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int MAXN=233;
char s[MAXN];
int cnt[30];
char mmp[1000][30];
int main(){
    int T=4;
    int mx=0;
    while(T--){
        scanf("%[^\n]",s);
        getchar();
        int len=strlen(s);
        rep(i,0,len-1){
            if('A'<=s[i]&&s[i]<='Z'){
                cnt[s[i]-'A']++;
                mx=max(mx,cnt[s[i]-'A']);
            }
        }
    }
    //cout<<mx<<endl;
    rep(i,0,25){
        per(j,mx,mx-cnt[i]+1){
            mmp[j][i]='*';
        }
        rep(j,1,mx-cnt[i]){
            mmp[j][i]=' ';
        }
    }
    rep(i,1,mx){
        rep(j,0,26){
            if(j==0){
                printf("%c",mmp[i][j]);
            }else{
                printf(" %c",mmp[i][j]);
            }
        }
        puts("");
    }
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    return 0;
}

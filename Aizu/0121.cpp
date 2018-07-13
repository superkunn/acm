#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
using namespace std;
struct node{
    string s;
    int t;
};
int FAC[10]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(string s,int n){
    int x=0;
    for(int i=0;i<n;i++){
        int smaller=0; // 在当前位之后小于其的个数
        for(int j=i+1;j<n;j++){
            if(s[j]<s[i])smaller++;// 康托展开累加
        }
        x+=FAC[n-i-1]*smaller;
    }
    return x;// 康托展开值
}
int v[50000];
queue<node> que;
void bfs(string s){
    while(!que.empty())que.pop();
    node tem;
    tem.s=s;
    tem.t=0;
    v[cantor(s,8)]=1;
    que.push(tem);
    while(!que.empty()){
        tem=que.front();
        que.pop();
        for(int i=0;i<8;i++){
            if(tem.s[i]=='0'){
                if(i!=0&&i!=4){
                    string ss=tem.s;
                    swap(ss[i],ss[i-1]);
                    if(v[cantor(ss,8)]==0){
                        v[cantor(ss,8)]=tem.t+1;
                        node ttt;
                        ttt.s=ss;
                        ttt.t=tem.t+1;
                        que.push(ttt);
                    }
                }
                if(i!=3&&i!=7){
                    string ss=tem.s;
                    swap(ss[i],ss[i+1]);
                    if(v[cantor(ss,8)]==0){
                        v[cantor(ss,8)]=tem.t+1;
                        node ttt;
                        ttt.s=ss;
                        ttt.t=tem.t+1;
                        que.push(ttt);
                    }
                }
                if(i<4){
                    string ss=tem.s;
                    swap(ss[i],ss[i+4]);
                    if(v[cantor(ss,8)]==0){
                        v[cantor(ss,8)]=tem.t+1;
                        node ttt;
                        ttt.s=ss;
                        ttt.t=tem.t+1;
                        que.push(ttt);
                    }
                }
                else{
                    string ss=tem.s;
                    swap(ss[i],ss[i-4]);
                    if(v[cantor(ss,8)]==0){
                        v[cantor(ss,8)]=tem.t+1;
                        node ttt;
                        ttt.s=ss;
                        ttt.t=tem.t+1;
                        que.push(ttt);
                    }
                }
                break;
            }
        }
    }
}
int main(){
    string ss="01234567";
    bfs(ss);
    int x;
    while(~scanf("%d",&x)){
        string s;
        s+=char('0'+x);
        for(int i=1;i<=7;i++){
            scanf("%d",&x);
            s+=char('0'+x);
        }
        printf("%d\n",s==ss?0:v[cantor(s,8)]);
    }
    return 0; 
}

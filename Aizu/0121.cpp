#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
using namespace std;
map<string,int> mymap;
struct node{
    string s;
    int t;
};
queue<node> que;
void bfs(string s){
    while(!que.empty())que.pop();
    node tem;
    tem.s=s;
    tem.t=0;
    mymap[s]=1;
    que.push(tem);
    while(!que.empty()){
        tem=que.front();
        que.pop();
        for(int i=0;i<8;i++){
            if(tem.s[i]=='0'){
                if(i!=0&&i!=4){
                    string ss=tem.s;
                    swap(ss[i],ss[i-1]);
                    if(mymap[ss]==0){
                        mymap[ss]=tem.t+1;
                        node ttt;
                        ttt.s=ss;
                        ttt.t=tem.t+1;
                        que.push(ttt);
                    }
                }
                if(i!=3&&i!=7){
                    string ss=tem.s;
                    swap(ss[i],ss[i+1]);
                    if(mymap[ss]==0){
                        mymap[ss]=tem.t+1;
                        node ttt;
                        ttt.s=ss;
                        ttt.t=tem.t+1;
                        que.push(ttt);
                    }
                }
                if(i<4){
                    string ss=tem.s;
                    swap(ss[i],ss[i+4]);
                    if(mymap[ss]==0){
                        mymap[ss]=tem.t+1;
                        node ttt;
                        ttt.s=ss;
                        ttt.t=tem.t+1;
                        que.push(ttt);
                    }
                }
                else{
                    string ss=tem.s;
                    swap(ss[i],ss[i-4]);
                    if(mymap[ss]==0){
                        mymap[ss]=tem.t+1;
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
        printf("%d\n",s==ss?0:mymap[s]);
    }
    return 0; 
}

# 14th浙江省赛 6A 金牌区

## A. Cooking Competition(hanxukun)

```c++
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int a=0,b=0;
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            if(x==1){
                a++;
            }else if(x==2){
                b++;
            }
        }
        if(a==b){
            puts("Draw");
        }else if(a>b){
            puts("Kobayashi");
        }else{
            puts("Tohru");
        }
    }
    return 0;
}
```

## B.Problem Preparation(changzhiming)

```c++
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)

int a[1000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x,one=0;
        bool flag=true;
        scanf("%d",&n);
        if(n<10||n>13)flag=false;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]==1)one++;
        }
        sort(a,a+n);
        if(one<2)flag=false;
        if(a[0]<1)flag=false;
        if(flag){
            for(int i=0;i<n-2;i++){
                if(a[i+1]-a[i]>2)flag=false;
            }
        }
        if(flag)printf("Yes\n");
            else printf("No\n");
    }
    return 0;
}

```

## C.What Kind of Friends Are You?(qianyi)

```c++
#include<bits/stdc++.h>
using namespace std;
int t,n,m,p,x;
string a;
map<string,int>mp;
map<int,string>ans;
map<string,int>::iterator q;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        ans.clear();
        scanf("%d%d",&n,&p);
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            cin>>a;
            mp.insert(make_pair(a,0));
        }
        for(int i=0;i<p;++i)
        {
            scanf("%d",&x);
            for(int j=0;j<x;++j)
            {
                cin>>a;
                mp[a]+=(1<<i);
            }
        }
        for(q=mp.begin();q!=mp.end();++q)
        {
            pair<string,int> b=*q;
            if(ans.find(b.second)!=ans.end())
            {
                ans[b.second]="Let's go to the library!!";
            }
            else
            {
                ans[b.second]=b.first;
            }
        }
        for(int i=0;i<n;++i)
        {
            int tmp=0;
            for(int j=0;j<p;++j)
            {
                scanf("%d",&x);
                tmp+=x*(1<<j);
            }
            if(ans.find(tmp)!=ans.end())
            {
                cout<<ans[tmp]<<endl;
            }
            else
            {
                cout<<"Let's go to the library!!"<<endl;
            }
        }
    }
    return 0;
}

```

## D.Let's Chat(changzhiming)

```c++
#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,y,t1,t2;
map<int,int>mp;
set<int>st;
struct no{
    int l,r;
}nodea[1000],nodeb[1000];
int a[1000],b[1000],hs[1000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        st.clear();mp.clear();
        memset(hs,0,sizeof(hs));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        scanf("%d%d%d%d",&n,&m,&x,&y);
        for(int i=0;i<x;i++){
            scanf("%d%d",&nodea[i].l,&nodea[i].r);
            st.insert(nodea[i].l);st.insert(nodea[i].r);
            st.insert(nodea[i].l-1);st.insert(nodea[i].r+1);
        }
        for(int i=0;i<y;i++){
            scanf("%d%d",&nodeb[i].l,&nodeb[i].r);
            st.insert(nodeb[i].l);st.insert(nodeb[i].r);
            st.insert(nodeb[i].l-1);st.insert(nodeb[i].r+1);
        }
        int id=1,p;
        for(set<int>::iterator it=st.begin();it!=st.end();it++){
            mp[*it]=id;
            hs[id]=*it;
            p=*it;
            id++;
        }
        for(int i=0;i<x;i++){
            int t1=mp[nodea[i].l],t2=mp[nodea[i].r];
            for(int i=t1;i<=t2;i++)
                a[i]=1;
        }
        for(int i=0;i<y;i++){
            int t1=mp[nodeb[i].l],t2=mp[nodeb[i].r];
            for(int i=t1;i<=t2;i++)
                b[i]=1;
        }
        bool f=false;
        int l,r;
        long long ans=0;
        id+=2;
        for(int i=0;i<=id;i++){
            if(a[i]==1&&b[i]==1){
                if(!f){
                    l=i;f=true;
                }
            }
            else{
                r=i-1;
                if(f){
                    int temp=hs[r]-hs[l]+1-m+1;
                    if(temp>0&&(hs[r]-hs[l]+1)>=m)
                    ans+=temp;
                }
                f=false;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
```

## E.Seven Segment Display(hanxukun)

```c++
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
map<char,int> ctoi;
map<char,int> itoc;
ll cnt[10];
ll vv[10];
int val[16]={6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4};
int sum[16];
ll str_to_ll(string s){
    ll res=0;
    rep(i,0,(int)s.length()-1){
        res*=16;
        res+=ctoi[s[i]];
    }
    return res;
}
string ll_to_str(ll now){
    string res="";
    rep(i,1,8){
        res+=itoc[(now%16)];
        now/=16;
    }
    reverse(res.begin(),res.end());
    return res;
}
char buf[15];
/*
100
1 00000000

*/
ll dfs(ll pre,string str,int len){
    //cout<<pre<<" "<<str<<" "<<len<<endl;
    if(len==1)return pre*(ctoi[str[0]]+1)+sum[ctoi[str[0]]];
    ll res=0;
    if(ctoi[str[0]]>0){
        res+=pre*ctoi[str[0]]*cnt[len-1];
        res+=sum[ctoi[str[0]]-1]*cnt[len-1];
        res+=ctoi[str[0]]*vv[len-1];
    }
    res+=dfs(pre+val[ctoi[str[0]]],string(str.begin()+1,str.end()),len-1);
    return res;
}
ll fun(ll now){
    //cout<<now<<endl;
    if(now<0)return 0;
    string str=ll_to_str(now);
    //cout<<str<<endl;
    return dfs(0,str,8);
}
int main(){
    rep(i,0,9){
        itoc[i]='0'+i;
        ctoi['0'+i]=i;
    }
    rep(i,10,15){
        itoc[i]='A'-10+i;
        ctoi['A'-10+i]=i;
    }
//    ll ww=str_to_ll("FFFFFFFF");
//    cout<<ww<<endl;
//    cout<<ll_to_str(ww)<<endl;
    int T;
    scanf("%d",&T);

    sum[0]=val[0];
    rep(i,1,15){
        sum[i]=sum[i-1]+val[i];
    }
    cnt[0]=1;
    rep(i,1,7){
        cnt[i]=cnt[i-1]*16;
        vv[i]=cnt[i]/16*sum[15]*i;
        //cout<<i<<" "<<cnt[i]<<endl;
        //cout<<vv[i]<<endl;
    }
    while(T--){
        int ad;
        scanf("%d",&ad);
        scanf("%s",buf);
        string ss=buf;
        ll a=str_to_ll(ss);
        //cout<<a<<endl;
        ll b=(a+ad-1)%(str_to_ll("FFFFFFFF")+1);
        //cout<<b<<endl;
        //cout<<fun(0)<<endl;
        if(b>=a){
            printf("%lld\n",fun(b)-fun(a-1));
        }else{
            printf("%lld\n",fun(b)+fun(str_to_ll("FFFFFFFF"))-fun(a-1));
        }
    }
    return 0;
}

```

## F.Heap Partition(changzhiming)
```c++
#include<bits/stdc++.h>
#define maxn 200005
#define pa make_pair
using namespace std;
int t,n;
int a[maxn];
set<pair<int,int>>st;
map<pair<int,int>,int>mp;
vector<int>ans[maxn];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        st.clear();
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ans[i].clear();
            ans[i].clear();
        }
        int rootcnt=1,now;
        st.insert(pa(a[1],1));
        mp[pa(a[1],1)]=2;
        ans[1].push_back(1);
        bool f=false;
        for(int i=2;i<=n;i++){
            set<pair<int,int>>::iterator it=st.lower_bound(pa(a[i],1000));
            if(it==st.begin())
                f=true;
            else
                f=false;
            if(!f){
                it--;
                mp[pa(a[i],it->second)]+=2;
                st.insert(pa(a[i],it->second));
                ans[it->second].push_back(i);
                mp[pa(it->first,it->second)]--;
                if(mp[pa(it->first,it->second)]==0){
                    st.erase(pa(it->first,it->second));
                }
            }
            if(f){
                rootcnt++;
                st.insert(pa(a[i],rootcnt));
                mp[pa(a[i],rootcnt)]=2;
                ans[rootcnt].push_back(i);
            }
        }
        printf("%d\n",rootcnt);
        for(int i=1;i<=rootcnt;i++){
            printf("%d ",ans[i].size());
            for(int j=0;j<ans[i].size();j++){
                 printf("%d",ans[i][j]);
                 if(j!=ans[i].size()-1)printf(" ");
                 else printf("\n");
            }
        }
    }
    return 0;
}

```

# 补题
## G

## H

## I

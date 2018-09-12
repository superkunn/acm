import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class Main{
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int n=getInt();
        node no[]=new node[n+1];
        for(int i=1;i<=n;i++){
            no[i]=new node();
            no[i].v=getInt();
            no[i].id=i;
        }
        Arrays.sort(no,1,1+n,new cmp1());
        int x[]=new int[n+1];
        int index=1;
        x[no[1].id]=index;
        for(int i=2;i<=n;i++){
            if(no[i].v!=no[i-1].v){
                index++;
            }
            x[no[i].id]=index;
        }
        BIT bit=new BIT(index);
        long ans=0;
        for(int i=1;i<=n;i++){
            ans+=i-1-bit.sum(x[i]);
            bit.add(x[i],1);
        }
        out.println(ans);
        out.flush();
    }
    static int getInt()throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
    static String getString()throws IOException{
        in.nextToken();
        return in.sval;
    }
}
class BIT{
    int c[];
    int n;
    BIT(int _n){
        n=_n;
        c=new int[n+2];
    }
    void add(int i,int v){
        for(;i<=n;i+=i&-i){
            c[i]+=v;
        }
    }
    int sum(int i){
        int res=0;
        for(;i>0;i-=i&-i){
            res+=c[i];
        }
        return res;
    }
}
class node{
    int id,v;
}
class cmp1 implements Comparator<node>{
    public int compare(node a,node b){
        return a.v-b.v;
    }
}

import java.io.*;
class BIT{
    long[] vs;
    long[] a;
    int n;
    BIT(int _n){
        n = _n;
        vs = new long[n+5];
        a = new long[n+5];
    }
    void add(int i,long v){
        long d = v - a[i];
        a[i] = v;
        for(; i <= n; i += i&-i){
            vs[i] += d;
        }
    }
    long sum(int i){
        long res = 0;
        for(; i>0; i -= i&-i){
            res += vs[i];
        }
        return res;
    }
    long query(int l, int r){
        return sum(r) - sum(l-1);
    }
}
public class Main {
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static  PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String args[]) throws Exception {
        int n=getInt();
        int q=getInt();
        BIT a1= new BIT(n);
        BIT a2= new BIT(n);
        for(int i = 1; i <= n; i++){
            int x=getInt();
            a1.add(i,x);
            a2.add(i,1L*x*(n-i+1));
        }
        while(q-- > 0){
            int op=getInt();
            int l=getInt();
            int r=getInt();
            if(op==1){
                long ans=0;
                ans+=a2.query(l,r);
                ans-=1L*(n-r)*a1.query(l,r);
                out.println(ans);
                out.flush();
            }else{
                a1.add(l,r);
                a2.add(l,1L*r*(n-l+1));
            }
        }
    }
    static int getInt() throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
}









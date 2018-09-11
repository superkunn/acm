import java.io.*;
import java.math.BigInteger;

public class Main{
    static StreamTokenizer in =  new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int k=getInt();
        int ans=k;
        int n=k;
        for(int i=2;i*i<=k;i++){
            if(n%i!=0)continue;
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
        if(n!=1)ans=ans/n*(n-1);
        out.println(ans);
        out.flush();
    }
    static int getInt()throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
}






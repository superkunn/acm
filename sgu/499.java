import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
public class Main{
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int MAXN=1000000;
        int n=getInt();
        int cnt[]=new int[MAXN+5];
        while(n-->0){
            int x=getInt();
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    cnt[i]++;
                    if(i*i<x)cnt[x/i]++;
                }
            }
        }
        for(int i=MAXN;i>=1;i--){
            if(cnt[i]>=2){
                out.println(i);
                out.flush();
                break;
            }
        }

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

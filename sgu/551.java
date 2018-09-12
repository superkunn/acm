import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

public class Main{
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int n=getInt();
        int t1=getInt();
        int t2=getInt();
        int l=0,r=Math.min(t1,t2)*n;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid/t1+mid/t2>=n){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int x=(ans+t1-1)/t1;
        int y=(ans+t2-1)/t2;
        out.println((x+y)+" "+Math.max(x*t1,y*t2));
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

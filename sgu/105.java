import java.io.*;

public class Main{
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int n=getInt();
        int ans=n/3*2;
        if(n%3!=0)ans+=n%3-1;
        out.println(ans);
        out.flush();
    }
    static int getInt()throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
}

import java.io.*;
import java.math.BigInteger;

public class Main{
    static StreamTokenizer in =  new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int k=getInt();
        out.println(2*k+1);
        out.flush();
    }
    static int getInt()throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
}






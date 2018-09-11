import java.io.*;
public class Main{
    static StreamTokenizer in =  new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int a=getInt();
        int b=getInt();
        out.println(a+b);
        out.flush();
    }
    static int getInt()throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
}






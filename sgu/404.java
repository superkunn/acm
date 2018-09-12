import java.io.*;

public class Main{
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int n=getInt();
        int m=getInt();
        int pos=(n-1)%m;
        for(int i=0;i<m;i++){
            String ans=getString();
            if(pos==i){
                out.println(ans);
                out.flush();
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

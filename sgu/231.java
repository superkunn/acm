import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

public class Main{
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int MAXN=1000000;
        boolean not_prime[] = new boolean[MAXN+5];
        not_prime[0]=not_prime[1]=true;
        int n=getInt();
        for(int i=2;i*i<=n;i++){
            if(!not_prime[i]){
                for(int j=2*i;j<=n;j+=i){
                    not_prime[j]=true;
                }
            }
        }
        Queue<Integer> que=new LinkedList<Integer>();
        for(int i=1;i+2<=n;i++){
            if(!not_prime[i]&&!not_prime[i+2]){
                que.offer(i);
            }
        }
        out.println(que.size());
        out.flush();
        while(!que.isEmpty()){
            out.println(2+" "+que.peek());
            out.flush();
            que.poll();
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

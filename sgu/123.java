
import java.io.*;
public class Main{
    static int a[] = new int[45];
    static StreamTokenizer in =  new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int k=getInt();
        if(k<=2){
            out.println(k);
            out.flush();
        }else{
            int sum=2;
            a[1]=a[2]=1;
            for(int i=3;i<=k;i++){
                a[i]=a[i-1]+a[i-2];
                sum+=a[i];
            }
            out.println(sum);
            out.flush();
        }
    }
    static int getInt()throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
}

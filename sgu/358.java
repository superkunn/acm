import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
public class Main{
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int a[]=new int[3];
        for(int i=0;i<3;i++){
            int x=getInt();
            int y=getInt();
            int z=getInt();
            a[i]=fun(x,y,z);
        }
        out.println(fun(a[0],a[1],a[2]));
        out.flush();
    }
    static int fun(int x,int y,int z){
        if((x<=y&&y<=z)||(z<=y&&y<=x)){
            return y;
        }else if((y<=x&&x<=z)||(z<=x&&x<=y)){
            return x;
        }else{
            return z;
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

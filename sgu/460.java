import java.io.*;
import java.math.BigInteger;

public class Main{
    static StreamTokenizer in =  new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int T=getInt();
        while(T-->0){
            String s=getString();
            int len=s.length();
            if((s.charAt(len-2)=='c'&&s.charAt(len-1)=='h')||s.charAt(len-1)=='x'||s.charAt(len-1)=='s'||s.charAt(len-1)=='o'){
                out.println(s+"es");
                out.flush();
            }else if(s.charAt(len-1)=='y'){
                for(int i=0;i<len-1;i++){
                    out.print(s.charAt(i));
                    out.flush();
                }
                out.println("ies");
                out.flush();
            }else if(s.charAt(len-1)=='f'){
                for(int i=0;i<len-1;i++){
                    out.print(s.charAt(i));
                    out.flush();
                }
                out.println("ves");
                out.flush();
            }else if(s.charAt(len-2)=='f'&&s.charAt(len-1)=='e'){
                for(int i=0;i<len-2;i++){
                    out.print(s.charAt(i));
                    out.flush();
                }
                out.println("ves");
                out.flush();
            }else{
                out.println(s+"s");
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






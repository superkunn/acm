
import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
        InputStream inputStream = System.in;//new FileInputStream("C:\\Users\\xxx\\Downloads\\test.in");
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
    static class Task {

        public void solve(InputReader in, PrintWriter out) {
            int n=in.nextInt();
            int M=(int)(Math.log(1e18)/Math.log(2))+1;
            long a[]=new long[105];
            Arrays.fill(a,0);
            for(int i=1;i<=n;i++){
                long w=in.nextLong();
                for(int j=M;j>=0;j--){
                    if(((w>>j)&1)!=0){
                        if(a[j]!=0){
                            w^=a[j];
                        }else{
                            a[j]=w;
                            for(int k=j-1;k>=0;k--){
                                if((((a[j]>>k)&1)!=0)&&(a[k]!=0)){
                                    a[j]^=a[k];
                                }
                            }
                            for(int k=j+1;k<=M;k++){
                                if(((a[k]>>j)&1)!=0){
                                    a[k]^=a[j];
                                }
                            }
                            break;
                        }
                    }
                }
            }
            long ans=0;
            for(int i=0;i<=M;i++){
                ans^=a[i];
            }
            out.println(ans);
        }

    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char[] nextCharArray() {
            return next().toCharArray();
        }

        public boolean hasNext() {
            try {
                String string = reader.readLine();
                if (string == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(string);
                return tokenizer.hasMoreTokens();
            } catch(IOException e) {
                return false;
            }
        }
        public BigInteger nextBigInteger() {
            return new BigInteger(next());
        }

        public BigDecimal nextBigDecinal() {
            return new BigDecimal(next());
        }
    }
}

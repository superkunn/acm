import java.io.*;
import java.math.*;
import java.util.StringTokenizer;

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
        static boolean check(int x,int n){
            int cnt=0;
            while(x>0){
                cnt+=x/5;
                x/=5;
            }
            if(cnt>=n)return true;
            else return false;
        }
        public void solve(InputReader in, PrintWriter out) {
            int n=in.nextInt();
            int ans=-1;
            int l=1;
            int r=1000000000;
            while(l<=r){
                int mid=(l+r)/2;
                if(check(mid,n)){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            int cnt=0;
            int now=ans;
            while(now>0){
                cnt+=now/5;
                now/=5;
            }
            if(cnt==n){
                out.println(ans);
            }else{
                out.println("No solution");
            }
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

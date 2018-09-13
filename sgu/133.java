
import java.io.*;
import java.math.*;
import java.util.Arrays;
import java.util.Comparator;
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
    static class P{
        int l,r;
        P(){};
    }
    static class cmp1 implements Comparator<P>{
        public int compare(P a,P b){
            if(a.l==b.l)return b.r-a.r;
            return a.l-b.l;
        }
    }
    static class Task {
        public void solve(InputReader in, PrintWriter out) {
            int n=in.nextInt();
            P p[]=new P[n];
            for(int i=0;i<n;i++){
                p[i]=new P();
                p[i].l=in.nextInt();
                p[i].r=in.nextInt();
            }
            Arrays.sort(p,new cmp1());
            int r=p[0].r;
            int ans=0;
            for(int i=1;i<n;i++){
                if(p[i].r<=r)ans++;
                else r=p[i].r;
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

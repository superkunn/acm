import java.io.*;
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
        static boolean fun(BigInteger x){
            BigInteger ans=BigInteger.valueOf(-1);
            BigInteger l=BigInteger.ZERO;
            BigInteger r=x;
            while(l.compareTo(r)<=0){
                BigInteger mid=l.add(r).shiftRight(1);
                int now=mid.multiply(mid).compareTo(x);
                if(now==0){
                    ans=mid;
                    break;
                }else if(now<0){
                    l=mid.add(BigInteger.ONE);
                }else{
                    r=mid.subtract(BigInteger.ONE);
                }
            }
            if(ans.compareTo(BigInteger.valueOf(-1))==0)return false;
            else return true;
        }
        public void solve(InputReader in, PrintWriter out) {
            int T=in.nextInt();
            while(T-->0){
                BigInteger a=in.nextBigInteger();
                BigInteger b=a.multiply(a.subtract(BigInteger.ONE)).shiftRight(1);
                boolean f1=fun(a);
                boolean f2=fun(b);
                if(f1&&f2){
                    out.println("Arena of Valor");
                }else if(f1){
                    out.println("Hearth Stone");
                }else if(f2){
                    out.println("Clash Royale");
                }else{
                    out.println("League of Legends");
                }
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

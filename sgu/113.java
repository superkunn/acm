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
        static boolean not_prime[] = new boolean[100005];
        static boolean is_prime(int x){
            if(x<2)return false;
            for(int i=2;i*i<=x;i++){
                if(x%i==0)return false;
            }
            return true;
        }
        public void solve(InputReader in, PrintWriter out) {
            not_prime[0]=not_prime[1]=true;
            for(int i=2;i*i<=100000;i++){
                if(!not_prime[i]){
                    for(int j=2*i;j<=100000;j+=i){
                        not_prime[j]=true;
                    }
                }
            }
            int n=in.nextInt();
            while(n-->0){
                int x=in.nextInt();
                boolean f=false;
                for(int i=2;i*i<=x;i++){
                    if(x%i!=0)continue;;
                    if(!not_prime[i]&&is_prime(x/i)){
                        f=true;
                        break;
                    }
                }
                if(f){
                    out.println("Yes");
                }else{
                    out.println("No");
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

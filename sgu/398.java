
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
    static class Edge{
        int v,nxt;
        Edge(){}
        Edge(int v,int nxt){
            this.v=v;
            this.nxt=nxt;
        }
    }
    static class Task {
        static int MAXV=55;
        static int MAXE=5500;
        static int tot;
        static int head[] = new int[MAXV];
        Edge edge[] = new Edge[MAXE];
        void init(){
            tot=0;
            Arrays.fill(head,-1);
        }
        void add_edge(int u,int v){
            edge[tot]=new Edge(v,head[u]);
            head[u]=tot++;
        }
        public void solve(InputReader in, PrintWriter out) {
            int n=in.nextInt();
            int st=in.nextInt();
            init();
            for(int i=1;i<=n;i++){
                int m=in.nextInt();
                while(m-->0){
                    int w=in.nextInt();
                    add_edge(i,w);
                }
            }
            Queue<Integer> que =new LinkedList<Integer>();
            que.offer(st);
            int vis[] = new int[MAXV];
            Arrays.fill(vis,-1);
            int index=0;
            int ans[]=new int[MAXV];
            vis[st]=0;
            while (!que.isEmpty()){
                int u=que.peek();
                que.poll();
                if(vis[u]==2){
                    ans[index]=u;
                    index++;
                    continue;
                }
                for(int i=head[u];i!=-1;i=edge[i].nxt){
                    int v=edge[i].v;
                    if(vis[v]==-1){
                        vis[v]=vis[u]+1;
                        que.offer(v);
                    }
                }
            }
            Arrays.sort(ans,0,index);
            out.println(index);
            for(int i=0;i<index;i++){
                out.println(ans[i]);
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

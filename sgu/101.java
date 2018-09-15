
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
        static int MAXV=10;
        static int MAXE=205;
        static int tot;
        static int head[]=new int[MAXV];
        static class Edge{
            int v,nxt,id,vis;
            char tp;
            Edge(int v,int nxt,int id,char tp){
                this.v=v;
                this.nxt=nxt;
                this.id=id;
                this.vis=0;
                this.tp=tp;
            }
        }
        static void init(){
            tot=0;
            Arrays.fill(head,-1);
        }
        void add_edge(int u,int v,int id){
            edge[tot]=new Edge(v,head[u],id,'+');
            head[u]=tot++;
            edge[tot]=new Edge(u,head[v],id,'-');
            head[v]=tot++;
        }
        static Edge edge[]=new Edge[MAXE];
        static int nn;
        static Queue<Integer> que=new LinkedList<Integer>();
        static void dfs(int u){
            for(int i=head[u];i!=-1;i=edge[i].nxt){
                if(edge[i].vis==0){
                    nn--;
                    edge[i].vis=1;
                    edge[i^1].vis=1;
                    dfs(edge[i].v);
                    que.offer(i^1);
                }
            }
        }
        public void solve(InputReader in, PrintWriter out) {
            int n=in.nextInt();
            int indec[]=new int[10];
            Arrays.fill(indec,0);
            init();
            for(int i=1;i<=n;i++){
                int u=in.nextInt();
                int v=in.nextInt();
                add_edge(u,v,i);
                indec[u]++;
                indec[v]++;
            }
            int cnt=0;
            for(int i=0;i<=6;i++){
                if(indec[i]%2==1){
                    cnt++;
                }
            }
            if(cnt!=0&&cnt!=2){
                out.println("No solution");
                return;
            }
            nn=n;
            int st=0;
            for(int i=0;i<=6;i++){
                if(indec[i]!=0){
                    st=i;
                }
                if(indec[i]%2==1){
                    break;
                }
            }
            dfs(st);
            if(nn!=0){
                out.println("No solution");
                return;
            }
            while (!que.isEmpty()){
                int w=que.peek();
                que.poll();
                out.println(edge[w].id+" "+edge[w].tp);
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

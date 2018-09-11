import java.io.*;
import java.lang.reflect.Array;
import java.util.Arrays;

public class Main{
    static int MAXN=1000+10;
    static int a[]=new int[MAXN];
    static int b[]=new int[MAXN];
    static int c[]=new int[MAXN];
    static boolean dp[][] = new boolean[MAXN][220];
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception{
        int n=getInt();
        int m=getInt();
        int k=getInt();
        int l=getInt();
        for(int i=1;i<=n;i++){
            a[i]=getInt();
            b[i]=getInt();
            c[i]=getInt();
        }
        for(int i=1;i<=n+1;i++){
            for(int j=0;j<=200;j++){
                dp[i][j]=false;
            }
        }
        for(int i=k+100;i<=200;i++){
            dp[n+1][i]=true;
        }
        for(int i=n;i>=1;i--){
            if(i%2==1){
                for(int j=0;j<=200;j++){
                    boolean f=false;
                    if(a[i]>0){
                        int w=j+a[i];
                        if(w>200)w=200;
                        if(dp[i+1][w])f=true;
                    }
                    if(b[i]>0){
                        int w=j-b[i];
                        if(w<0)w=0;
                        if(dp[i+1][w])f=true;
                    }
                    if(c[i]==1){
                        int w=j-100;
                        w=-w;
                        w+=100;
                        if(dp[i+1][w])f=true;
                    }
                    if(f)dp[i][j]=true;
                }
            }else{
                for(int j=0;j<=200;j++){
                    boolean f=false;
                    boolean fz=true;
                    if(a[i]>0){
                        int w=j+a[i];
                        if(w>200)w=200;
                        if(dp[i+1][w])f=true;
                        else fz=false;
                    }
                    if(b[i]>0){
                        int w=j-b[i];
                        if(w<0)w=0;
                        if(dp[i+1][w])f=true;
                        else fz=false;
                    }
                    if(c[i]==1){
                        int w=j-100;
                        w=-w;
                        w+=100;
                        if(dp[i+1][w])f=true;
                        else fz=false;
                    }
                    if(f&&fz)dp[i][j]=true;
                }
            }
        }
        if(dp[1][m+100]){
            out.println("Good Ending");
            out.flush();
            return;
        }
        for(int i=1;i<=n+1;i++){
            for(int j=0;j<=200;j++){
                dp[i][j]=false;
            }
        }
        for(int i=0;i<=l+100;i++){
            dp[n+1][i]=true;
        }
        for(int i=n;i>=1;i--){
            if(i%2==0){
                for(int j=0;j<=200;j++){
                    boolean f=false;
                    if(a[i]>0){
                        int w=j+a[i];
                        if(w>200)w=200;
                        if(dp[i+1][w])f=true;
                    }
                    if(b[i]>0){
                        int w=j-b[i];
                        if(w<0)w=0;
                        if(dp[i+1][w])f=true;
                    }
                    if(c[i]==1){
                        int w=j-100;
                        w=-w;
                        w+=100;
                        if(dp[i+1][w])f=true;
                    }
                    if(f)dp[i][j]=true;
                }
            }else{
                for(int j=0;j<=200;j++){
                    boolean f=false;
                    boolean fz=true;
                    if(a[i]>0){
                        int w=j+a[i];
                        if(w>200)w=200;
                        if(dp[i+1][w])f=true;
                        else fz=false;
                    }
                    if(b[i]>0){
                        int w=j-b[i];
                        if(w<0)w=0;
                        if(dp[i+1][w])f=true;
                        else fz=false;
                    }
                    if(c[i]==1){
                        int w=j-100;
                        w=-w;
                        w+=100;
                        if(dp[i+1][w])f=true;
                        else fz=false;
                    }
                    if(f&&fz)dp[i][j]=true;
                }
            }
        }
        if(dp[1][m+100]){
            out.println("Bad Ending");
            out.flush();
            return;
        }
        out.println("Normal Ending");
        out.flush();
    }
    static int getInt()throws IOException{
        in.nextToken();
        return (int) in.nval;
    }
}







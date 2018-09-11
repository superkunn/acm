import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args)throws Exception{
        Scanner in = new Scanner(System.in);
        int c[]=new int[10];
        for(int i=0;i<10;i++)c[i]=0;
        String s1=in.next();
        String s2=in.next();
        for(int i=0;i<4;i++){
            c[s1.charAt(i)-'0']=1;
        }
        int ans1=0;
        int ans2=0;
        for(int i=0;i<4;i++){
            if(s1.charAt(i)==s2.charAt(i))ans1++;
            else if(c[s2.charAt(i)-'0']==1)ans2++;
        }
        System.out.println(ans1+" "+ans2);
    }
}

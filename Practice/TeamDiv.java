import java.lang.*;
import java.util.*;
public class TeamDiv {
    public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);
		String s[]= scanner.nextLine().split(",");
		int n=s.length;
        scanner.close();
		int[] a=new int[n];
        float sumhal,minhal;
        int sum=0,minn=Integer.MAX_VALUE,ans1,ans2;
        
		for(int i =0 ;i < n;i++){  
		    a[i]= Integer.parseInt(s[i]);
            sum+=a[i];
            minn=Math.min(minn,a[i]);
		}
        sumhal=sum/2.0f;
        minhal=minn/2.0f;
        float x =sumhal-minhal;//System.out.println(sumhal+minhal+" "+minn);
        ans1=(int) (sumhal+minhal);   
        ans2= (int) (x);
        System.out.println(ans2+" "+ans1);
	}
    //87,100,28,67,68,41,67,1
}

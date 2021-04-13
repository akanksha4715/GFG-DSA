import java.lang.*;
import java.util.*;
import java.io.*;
class Solution {
    public static int lengthOfLongestSubstring(String s) {
        //ArrayList<Integer> arr =new ArrayList<Integer>();
        
        int[] arr = new int[260];
        int n=s.length();
        if(n==0)
            return 0;
        for(int i=0;i<260;i++)
            arr[i]=0;
        arr[s.charAt(0)]++;
        int i,j,ans;
        i=0;j=0;ans=1;
        while(j<n-1){
            if(arr[s.charAt(j+1)]==0){
                j++;
                arr[s.charAt(j)]=1;
                ans=Math.max(ans,j-i+1);
            }
            else{
                arr[s.charAt(i)]--;
                i++;
            }
        }
        return ans;
    }
    public static void main(String[] arg){
        int a=lengthOfLongestSubstring("abcdgfab");
        System.out.println(a);
    }
}

import java.util.*;
public class StrRevSplChr {
    public static int findans(String str){
        HashMap<Integer,Character> mp = new HashMap<Integer,Character>();
        //HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        ArrayList<Character> arr= new ArrayList<Character>();
        int n;
        n=str.length();
        for(int i=0;i<n;i++){
            char x=str.charAt(i);
            if(x=='#' || x=='@')
            mp.put(i,x);
            else
            arr.add(x);
        }
        Collections.reverse(arr);
        mp.forEach((k,v) -> arr.add(k,v));
        System.out.println(arr);
        return 0;
    }
    public static void main(String[] args){
        Scanner sc=  new Scanner(System.in);
        String str;
        str=sc.nextLine();
        sc.close();
        findans(str);
    }
}

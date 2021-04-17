import java.util.*;
public class validpara{
    public static int validate(String str){
        Stack<Character> st= new Stack<Character>();
        int n=str.length(),c=0;
        for(int i=0;i<n;i++){
            char x=str.charAt(i);
            if(x=='(' || x=='{' || x=='['){
                st.push(x);
                c++;
            }
            if(x==')' || x=='}' || x==']'){
                if(st.empty())
                return i+1;
                else{
                st.pop();
                c++;
                }
            }
        }
        if(st.empty())
        return -1;
        char x=st.peek();
        if(x=='(' || x=='{' || x=='[')
        return c+1;
        if(x==')' || x=='}' || x==']')
        return c;
        
        return 0;
    }
    public static void main(String[] args){  
        Scanner sc = new Scanner(System.in);
        String str;
        str = sc.nextLine();
        sc.close();
        int ans= validate(str);
        System.out.println(ans);
    }
}
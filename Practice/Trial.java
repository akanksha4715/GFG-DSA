import java.util.*;
public class Trial {
     public static void main(String[] args) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0;i<4;i++)
        map.put(i, i+i);
        map.forEach((k,v) -> System.out.println(k+" "+v));
    }
}


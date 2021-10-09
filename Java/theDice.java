import java.util.*;
public class theDice {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int l = s.length();
        int count = 0;
        for(int i=0;i<l;++i)
        {
            if(s.charAt(i)<='6')
            count++;
            else if(s.charAt(i)>'6')
            {
                System.out.println("-1");
                return;
            }

        }
        System.out.println(count);
    }
}

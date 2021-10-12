import java.util.Random;
import java.util.Scanner;

public class Guessnumber {
    int userinput;
    int fixnum;
    int count=0;    
    Guessnumber(){
        Random ram = new Random();
        fixnum = ram.nextInt(101);


    }
    public void takeuserinput(){
        Scanner sc = new Scanner(System.in);
    System.out.println("ENTER YOUR GUESS NUMBER : -");
    userinput = sc.nextInt();

    }
    public void correctnumber(){
           count++;
           System.out.println("CONGRATULATIONS!! YOU HAVE WON ");
           System.out.println("YOUR TAKE " + count + "TIMES ");

      
    }
    public int wrongnumber(){
        if(userinput>fixnum)
        { count ++;
          System.out.println(" YOUR NUMBER IS BIGGER THAN FIX NUMBER: ");
          takeuserinput();
          return wrongnumber(); 
        }
        else if(userinput<fixnum){
            count++;
            System.out.println(" YOUR NUMBER IS LESSER THAN FIX NUMBER: ");
            takeuserinput(); 
            return wrongnumber(); 
        }
        return 0;

    } 
    public int check(){
        if(userinput==fixnum){
             correctnumber(); 
                    
        }
        else 
        {
              wrongnumber();

           return check();
        }
        return 0;
    }
   
    public static void main(String[] args) {
        
        Guessnumber obj = new Guessnumber();
        obj.takeuserinput();
        obj.check();


    }
}

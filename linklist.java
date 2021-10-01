import java.util.*;
 class node{
    int data;
    node next;

    node(int d){
        data = d;
        next=null;
    }
} 
class linklist{
    
    node head = null;
   static linklist  insertbegining(linklist list,int data){
         node newnode=new node(data);
         if(list.head==null){
             list.head=newnode;
         }
         else{
             newnode.next=list.head;
             list.head=newnode;
         }
         return list;
   }
   static void printinglist(linklist list){
       node temp;
       temp=list.head;
       while(temp!=null){
           System.out.print(temp.data+" ");
           temp=temp.next;
       }
   }
   public static void main(String[] args) {
       int d;
       Scanner sc=new Scanner(System.in);
       linklist list=new linklist();
       System.out.println("enter element data *******enter 0 to exit ");
       while(true){
          System.out.println("enter the element");
          d=sc.nextInt();
          if(d==0){
              break;
          }
          else{
          insertbegining(list,d);
          }
       }
       printinglist(list);
       sc.close();
   }
}

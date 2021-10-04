import java.util.ArrayList;

class Test{

    public static void main(String[] args) {
        ArrayList<String> name=new ArrayList<>();
        name.add("Sahil");
        name.add("Sunil");
        name.add("Potdukhe");
        System.out.println("Name is:"+name);
        name.add(1,"Hero");
        System.out.println("Name is:"+name);
        name.remove(2);
        System.out.println("Name is:"+name);
        name.set(2,"Indian");
        System.out.println("Name is:"+name);
        System.out.println(name.get(1));
        
        //print all the elements
        for(String str: name){
            System.out.println(str);
        }

        //Convert arraylist to array
        String[] arr=new String[name.size()];
        name.toArray(arr);

        System.out.print("Array: ");
        for(String item: arr){
            System.out.print(item+" ");
        }

    }
}
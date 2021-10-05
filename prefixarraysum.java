class prefixarraysum{
    public static void main(String[] args) {
        int[] arr={2,8,6,9,1};
        System.out.println(arr.length);
        int[] prefsum=new int[arr.length];
        prefsum[0]=arr[0];
        //orefsum array is array made by adding the index element of original array
        // plus the sum of elements of previous indexes
        for(int i=1;i<arr.length;i++){
            prefsum[i]=arr[i]+prefsum[i-1];
        }
        for(int i=0;i<arr.length;i++){
           System.out.print(prefsum[i]+" ");
        }
        System.out.println();
        int i=0,j=2;
        if(i==0){
            System.out.println("Sum is:"+prefsum[j]);
        }else{
            int sumrange =prefsum[j]-prefsum[i-1];
            System.out.println("Sum is:"+sumrange);
        }
      
    }
}
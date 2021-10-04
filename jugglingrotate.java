class jugglingrotate{
   
    static int gcd(int n,int d){
        if(n==0){
            return d;
        }
        return gcd(d%n,n);
    }
    public static void main(String[] args) {
        int arr[]={1,2,3,4,5,6,7};
        int n=arr.length;
        System.out.println("The old array is:");
        for(int l=0;l<n;l++){
            System.out.print(" "+arr[l]);
        }
        System.out.println();
        int d=2;
        int temp=0;
        int j=0,k=0;
        for(int i=0;i<(gcd(n,d));i++){
            temp=arr[i];
            j=i;
            while(true){
                k=j+d;
                if(k>=n){
                    k=k-n;
                }
                if(k==i){
                    break;
                }
                arr[j]=arr[k];
                j=k;
            }
            arr[j]=temp;
        }
        System.out.println("The new array is:");
        for(int l=0;l<n;l++){
            System.out.print(" "+arr[l]);
        }
    }
    
}
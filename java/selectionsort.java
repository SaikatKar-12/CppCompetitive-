public class selectionsort {
    public static void main(String[] args) {
        int [] arr = {64, 34, 25, 12, 22, 11, 90};
        int n = arr.length;
        for(int i=0;i<n-1;i++){
            int min=Integer.MAX_VALUE;
            int minIndex=i;
            for(int j=i;j<n;j++){
                if(arr[j]<min){
                    min=arr[j];
                    minIndex=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[minIndex];       
            arr[minIndex]=temp;
        }
        for(int i=0;i<n;i++){
            System.out.print(arr[i] + " ");
        }
    }
}

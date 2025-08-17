import java.util.*;
public class countDate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the date (dd-mm-yyyy): ");
        String date = sc.nextLine();
        
        String[] parts = date.split("-");
        int day = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int year = Integer.parseInt(parts[2]);
        
        if(month==2){
            System.out.println("28 days");
        }else if(month==4 || month==6 || month==9 || month==11){
            System.out.println("30 days");
        }else if(month>=1 && month<=12){
            System.out.println("31 days");
        };
    }
}
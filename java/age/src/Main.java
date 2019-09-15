import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        System.out.println(" Print age here: ");
        Scanner in = new Scanner(System.in);

        int age = in.nextInt();

        if (age >= 0 && age <= 5){
            System.out.println("baby");
        }else if (age >= 6 && age <= 11){
            System.out.println("kid");
        }else if (age >= 12 && age <= 17){
            System.out.println("teen");
        }else if (age > 17) {
            System.out.println("adult");
        }else{
            System.out.println("wrong age");
        }
    System.out.println("This is the end!");

    }


}

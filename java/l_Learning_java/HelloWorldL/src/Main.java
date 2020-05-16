import java.awt.*;
import java.util.concurrent.atomic.AtomicReferenceFieldUpdater;
import java.util.Scanner;

public class Main {
public static void main(String[] args){

    Scanner sc = new Scanner(System.in);

    System.out.println("Hello world!");
    System.out.println("Pilot Babak is speaking!");

    Car myCar = new Car(25.5, "1BC32E", Color.BLUE, true);
    Car ShivaCar = new Car( 35.5,  "Shiva", Color.BLACK ,  false);

    System.out.println(" My car license plate: " + myCar.licensePlate);
    System.out.println(" My car license plate: " + ShivaCar.licensePlate);

    myCar.chagnePaintColor(Color.RED);

    System.out.println(" My new car color is: " + myCar.paintColor.toString());


    //String userInput = "entertainment";  // Strings are immutable
    System.out.println(" Press your fingers on the keyboard please: ");
    String userInput = sc.next();  // Strings are immutable
    String upperCased = userInput.toUpperCase();
    System.out.println(" This is the lower cased of the variable: " + userInput +  " and the upper cased: " + upperCased );

    char firstChar = userInput.charAt(0);
    char secondChar = userInput.charAt(1);

    System.out.println(" first char: " + firstChar + " and the second char: "  + secondChar);

    System.out.println(" contains enter? " + userInput.contains("enter"));
    System.out.println(" contains Enter? " + userInput.contains("Enter"));
    System.out.println(" contains Enter? " + userInput.contains("Enter".toLowerCase()));

    System.out.println(" Print an interger: ");
    int userInt = sc.nextInt();
    System.out.println(" Interger: " + userInt);

    System.out.println(" Print a double: ");
    double userDbl = sc.nextDouble();
    System.out.println(" double: " + userDbl);


    double myCarSpeed = 50;
    myCarSpeed = myCar.speedingUp(myCarSpeed);
    System.out.println(" This is the speed of my car: " + myCarSpeed);

}
}


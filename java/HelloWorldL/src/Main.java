import java.awt.*;
import java.util.concurrent.atomic.AtomicReferenceFieldUpdater;

public class Main {
public static void main(String[] args){
    System.out.println("Hello world!");
    System.out.println("Pilot Babak is speaking!");

    Car myCar = new Car(25.5, "1BC32E", Color.BLUE, true);
    Car ShivaCar = new Car( 35.5,  "Shiva", Color.BLACK ,  false);

    System.out.println(" My car license plate: " + myCar.licensePlate);
    System.out.println(" My car license plate: " + ShivaCar.licensePlate);

    myCar.chagnePaintColor(Color.RED);

    System.out.println(" My new car color is: " + myCar.paintColor.toString());

}
}


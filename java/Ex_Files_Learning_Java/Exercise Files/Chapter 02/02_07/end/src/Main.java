import java.awt.*;

public class Main {

    public static void main(String[] args) {
        Car myCar = new Car(25.5,
                "1BC32E",
                Color.BLUE,
                true);

        Car sallyCar = new Car(13.9,
                "3D2OBN",
                Color.BLACK,
                false);

        double myCarSpeed = 50;
        myCarSpeed = myCar.speedingUp(myCarSpeed);
        System.out.println(myCarSpeed);
    }
}

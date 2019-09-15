import java.awt.*;
import java.lang.reflect.Array;
import java.util.concurrent.Future;
import java.util.Scanner;
import java.util.Arrays;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
        double power = Math.pow(5, 3);
        System.out.println(power);

        double squareRoot = Math.sqrt(64);
        System.out.println(squareRoot);

        Random rand = new Random();
        int randomNumber = rand.nextInt();
        int randomNumberWithBound = rand.nextInt(10);
        System.out.println(randomNumber);
        System.out.println(randomNumberWithBound);
    }

}

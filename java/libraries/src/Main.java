import java.util.Random;

public class Main {

    public static void main(String[] args){
        double power = Math.pow(5,3);
        System.out.println(" 5 topower 3 is "+ power);

        double square_root = Math.sqrt(64);
        System.out.println(square_root);

        Random rand = new Random();
        int randomNumber = rand.nextInt();
        int randomNumberWithBound = rand.nextInt(10);

        System.out.println(" Random numbers: " + randomNumber + " and " + randomNumberWithBound);
    }

}

import java.util.Random;

public class Dice {
    Random rand;
    int previousRoll = -1;

    public Dice() {
        this.rand = new Random();
    }

    public int roll() {
        int currentRoll = this.rand.nextInt(6) + 1;
        this.previousRoll = currentRoll;
        return currentRoll;
    }
}

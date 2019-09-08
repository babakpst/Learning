import java.util.Random;

public class Dice {
    Random rand;

    public Dice() {
        this.rand = new Random();
    }

    public int roll() {
        int currentRoll = this.rand.nextInt(6) + 1;
        return currentRoll;
    }
}

public class Dog {

    String name;
    int age;
    String[] fetchedItems = {"bone", "stick", "ball"};
    private int fetchCounter = 0;

    public Dog(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void bark() {
        System.out.println("Bark!");
    }

    public int getDogYears() {
        // Assume 1 dog year is 7 human years
        return this.age * 7;
    }

    public void fetch() {
        this.fetchCounter = (this.fetchCounter + 1) % 3;
        String item = this.fetchedItems[this.fetchCounter];
        System.out.println(name + " fetched a " + item + ".");
    }

}
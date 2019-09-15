import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {

public static void main(String[] args){

  int[] numbers = new int[5];

  numbers[0] = 31;
  numbers[1] = 45;
  numbers[2] = 22;
  numbers[3] = 98;
  numbers[4] = 10;

  int[] numbers2={78,13,48,15,24,86};
  System.out.println(" This is the number array: " + numbers[0]);
  System.out.println(" This is the number array: " + numbers[2]);

  String[] Names = {"Babak", "Shiva", "Arash", "Reza"};

  System.out.println(" Names: "    +    Names[0]);
  Names[0] = "Babak Poursartip";

  System.out.println(" Names: "    +    Names[0]);
  System.out.println(Names.length);

  System.out.println(Array.get(Names, 2));

  Arrays.sort(numbers);
  System.out.println(" This is the number array: " + numbers[0]);
  System.out.println(" This is the number array: " + numbers[2]);
  System.out.println(Arrays.toString(numbers));


}

}

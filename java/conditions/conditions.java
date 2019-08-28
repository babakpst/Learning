
/*

Babak Poursartip
27 Austin 2019

Conditions: from https://www.learnjavaonline.org/en/Conditionals

 */


public class conditions{

    public static void main(String []args){
	System.out.println(" the condition code: ");

	int a = 4;

	boolean b = a==4;

	if (b){
	    System.out.println("This is a true statement.");
	}

	int c;
	c = 12;

	if (c==12){
	    System.out.println("Yes, the value of c is 12.");
	}else System.out.println("No, this is not true.");


	int result = a == 5 ? 1 : 8;
	System.out.print("result is: ");
	System.out.println(result);

	
    }

}

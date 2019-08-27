
/*

Babak Poursartip
26 August 2019

variables

 */

// The name of this public class should be the same as the file
public class Variable_class {


    // there should be a main class in the code.
    public static void main(String []args){

	byte zero = 0;
	System.out.println(zero);

	int AnIntNumber;
	AnIntNumber = 8;
	System.out.println("this is an integer number:"); // prints the content and returns to the next line.
	System.out.print("this is an integer number: "); // prints and stays in the same line.
	System.out.println(AnIntNumber);	


	double dbl = 12.1234567890123456789;
	System.out.print(" A double number: ");
	System.out.println(dbl);


	float flt = 4.1234567890123456789f;
	// this should be " and NOT '
	System.out.print(" This is a floating point number: ");
	System.out.println(flt);

        // this should be ' and NOT "
	char char_var ='d';
	System.out.println(char_var);


	String str  = "This is babak. ";
	String str2 = "Babak is great.";
	String str3 = str + str2;

	System.out.println(str);
	System.out.println(str2);
	System.out.println(str3);
		
	boolean bln = false;
	    bln = true;
	  
	boolean toBe = false;
	
	bln = toBe || !toBe;
          if (bln) {
	      System.out.println(toBe);
	   }
	  
    }
   
}

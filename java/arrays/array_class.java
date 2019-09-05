
/*
Babak Poursartip
04 September 2019

*/

public class array_class{

public static void main(String []arg){

    int[] arr1;

    arr1 = new int[10];

    arr1[0] = 0;
    arr1[1] = 1;

    System.out.println("Here is the array: ");
    System.out.println(arr1[0]);
    System.out.println(arr1[1]);


    System.out.println("This is the array:");
    for (int i = 0; i<10; i++){
	arr1[i] = 2*i+3;
	System.out.println(arr1[i]);
    }




    
    }

}

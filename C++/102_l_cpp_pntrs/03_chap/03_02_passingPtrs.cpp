// 03_02_passingPtrs.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

double averageCost(double* priceArray, int *count)
{
	double sum = 0;
	for(int i = 0; i < *count; i++)
	{
		sum += *(priceArray + i);
	}
  double avg=(sum/ *count);
  *count += 5;
  cout<< "in the func " << *count << endl;
	return avg;

}
int main()
{
	double prices[5]{ 5.00, 4.50, 3.75, 3.10, 6.75 };
	//double average = averageCost(prices,5);
	int quant = 5;
  double average = averageCost(prices,&quant);
	cout << "$" << average << endl;
  cout<< "in the mian " << quant << endl;
    return 0;
}

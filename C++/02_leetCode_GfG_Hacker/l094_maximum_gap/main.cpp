
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
      int size = nums.size();
      if (size<2) return 0;

      int digit = 1; // digit to re-oder in the Radix algo
      bool con = true;

      vector<int> temp = nums;

      while (con)
      {
        con = false;
        vector<int> counter(11,0);
        vector<int> startInd(11,0);
        
        // find number of indecis
        for (int i = 0; i<size; i++)
        {
          

          // int ind = (nums[i] % ((int)pow(10,digit)))/ ( pow(10,(digit-1)));
          int ind =digit<=9? (nums[i] % ((int)pow(10,digit)))/ ( pow(10,(digit-1))):0;
          cout << " digit: " << digit << " ind: " << ind << endl;
          
          
          cout << " now: " << (nums[i] % ((int)pow(10,digit)))/ (int)( pow(10,(digit-1))) << endl;
          if ( nums[i] >= ((int)pow(10,digit-1)) ) con = true;
          counter[ind]++;
        }

        if (!con) break;

        cout << " counter: === \n";
        for_each(counter.begin(), counter.end(), [](auto x){cout << x << " ";});
        cout << endl;
        
        // find starting index
        for (int i = 1; i<counter.size(); i++ )  // update startInd
          startInd[i] = counter[i-1] + startInd[i-1];        

        cout << " startInd: === \n";
        for_each(startInd.begin(), startInd.end(), [](auto x){cout << x << " ";});
        cout << endl;

        // cout << "====\n";
        // reorder
        for (int i = 0; i<size; i++)
        {
          // cout << " here: " << (nums[i] % ((int)pow(10,digit)))/ (int)( pow(10,(digit-1))) << endl;
          int ind = startInd[  (nums[i] % ((int)pow(10,digit)))/ (int)( pow(10,(digit-1))) ]++;
          
          // cout<< " sorting "  << ind << "  " << nums[i] << endl;
          temp[ind] = nums[i];
        }
        nums = temp;
        digit++;
        cout << " sorted: === \n";
        for_each(nums.begin(), nums.end(), [](auto x){cout << x << " ";});
        cout << endl;
        cout << endl;
        // cout << endl;

      }


      int out = 0;
      for (int i = 0; i<size-1; i++)
        out = (nums[i+1]-nums[i])>out?nums[i+1]-nums[i]:out;

      return out;
    }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{3,6,9,1};
  // vector<int> nums{1,100};


  vector<int> nums{494767408,862126209,213511142,768240025,631263193,839199222,990848796,214568815,540853864,760724418,980162605,976743981,168965760,680875496,256709197,970953816,948680062,347254784,732201399,786249847,782805044,40906641,674241381,784330934,175502610,731105392,424650824,549764101,986090032,710542549,249208107,448419816,527708664,158499246,223421723,114552457,466978424,821491411,19614107,115389497,902211438,2644108,744489871,897895073,372311214,551142753,933294894,426217662,217504874,983488406,516890023,426853110,971124103};


  Solution t;

  int out = t.maximumGap(nums);
  
  cout << " answer: " << out << endl;
  
 
  
  std::cout << " done \n";
  return 0;
}
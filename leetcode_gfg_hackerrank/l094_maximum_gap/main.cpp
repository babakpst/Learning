
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
 public:
  int maximumGap(vector<int>& nums)
  {
    int size = nums.size();
    if (size < 2) return 0;
    cout << " size: " << size << endl;

    int digit = 1;  // digit to re-oder in the Radix algo
    bool con = true;

    vector<int> temp = nums;
    while (con)
    {
      con = false;
      vector<int> counter(11, 0);

      // find number of indecis
      for (int i = 0; i < size; i++)
      {
        int ind = ((nums[i] / digit) % 10);

        if (nums[i] >= digit) con = true;
        counter[ind + 1]++;
      }

      if (!con) break;

      // find starting index
      for (int i = 1; i < counter.size(); i++)  // update startInd
        counter[i] += counter[i - 1];

      // reorder
      for (int i = 0; i < size; i++)
      {
        int ind = counter[((nums[i] / digit) % 10)]++;
        temp[ind] = nums[i];
      }
      nums = temp;
      digit *= 10;
    }
    int out = 0;
    for (int i = 0; i < size - 1; i++) out = (nums[i + 1] - nums[i]) > out ? nums[i + 1] - nums[i] : out;

    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<int> nums{3,6,9,1};
  // vector<int> nums{1,100};

  vector<int> nums{494767408, 862126209, 213511142, 768240025, 631263193, 839199222, 990848796, 214568815, 540853864,
                   760724418, 980162605, 976743981, 168965760, 680875496, 256709197, 970953816, 948680062, 347254784,
                   732201399, 786249847, 782805044, 40906641,  674241381, 784330934, 175502610, 731105392, 424650824,
                   549764101, 986090032, 710542549, 249208107, 448419816, 527708664, 158499246, 223421723, 114552457,
                   466978424, 821491411, 19614107,  115389497, 902211438, 2644108,   744489871, 897895073, 372311214,
                   551142753, 933294894, 426217662, 217504874, 983488406, 516890023, 426853110, 971124103};

  Solution t;

  int out = t.maximumGap(nums);

  cout << " answer: " << out << endl;

  std::cout << " done \n";
  return 0;
}

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>



int delete_item(std::vector<int> &nums){
    int i = 0;
    printf("%ld\n",nums.size());
    if (nums.size() == 1) return 1;
    if (nums.size() == 0) return 0;

    for (int j = 0; j < (nums.size()-1); j++) {
        if (nums[j] != nums[j+1] ) {
            nums[i] = nums[j];
            i++;
        }
    }
    printf("%ld\n",nums.size());  
    if ((i>0 && nums[nums.size()-1]!=nums[i-1] ) || (i==0 && nums.size() != 0))  {nums[i]=nums[nums.size()-1]; ++i;}

    return i;
 
};


int main(){

printf(" subs ..\n");
std::vector<int> nums;
nums.resize(0);
//nums[0] = 1;

/*
nums[1] = 1;
nums[2] = 1;
nums[3] = 1;
nums[4] = 1;
nums[5] = 2;
nums[6] = 2;
nums[7] = 3;
nums[8] = 3;
nums[9] = 4;
*/

for (std::vector<int>::iterator it = nums.begin(); it !=nums.end(); ++it){
  printf(" %d \n", *it);
}

int len = delete_item(nums);

printf(" after %d \n",len);
for (std::vector<int>::iterator it = nums.begin(); it !=nums.end(); ++it){
  printf(" %d \n", *it);
}

printf(" output len: %d \n", len);

return 0;
}

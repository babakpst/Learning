
int binarySearch(vector<int>& nums, int target)
{
  if (nums.size() == 0) return -1;

  int left = 0, right = nums.size() - 1;
  while (left <= right)
  {
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  // End Condition: left > right
  return -1;
}

int binarySearch(vector<int>& nums, int target)
{
  if (nums.size() == 0) return -1;

  int left = 0, right = nums.size() - 1;
  while (left < right)
  {
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid;
    }
  }

  // Post-processing:
  // End Condition: left == right
  if (nums[left] == target) return left;
  return -1;
}

int binarySearch(vector<int>& nums, int target)
{
  if (nums.size() == 0) return -1;

  int left = 0, right = nums.size() - 1;
  while (left + 1 < right)
  {
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid;
    }
    else
    {
      right = mid;
    }
  }

  // Post-processing:
  // End Condition: left + 1 == right
  if (nums[left] == target) return left;
  if (nums[right] == target) return right;
  return -1;
}

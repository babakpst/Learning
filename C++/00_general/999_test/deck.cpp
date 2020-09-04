
#include <deque>
#include <fstream>
#include <iostream>

using namespace std;

void printKMax(int arr[], int n, int k) {
  // Write your code here.
  deque<int> tst;
  int max = 0;
  int old;
  for (int i = 0; i < n; ++i) {
    tst.push_front(arr[i]);
    if (arr[i] > max)
      max = arr[i];
    if (tst.size() == k) {
      if (max != arr[i] && old == max) {
        max = 0;
        for (int j = 0; j < k; ++j) {

          if (tst[j] > max)
            max = tst[j];
        }
      }
      cout << max << " ";
      old = tst.back();
      tst.pop_back();
    }
  }
  cout << endl;
}

int main() {
  fstream input("deque.txt");
  int t;
  input >> t;
  while (t > 0) {
    int n, k;
    input >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
      input >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}
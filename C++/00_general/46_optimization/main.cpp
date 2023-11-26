
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

// to build: g++ -O3 main.cpp -o main
// cacheline size is 64 Byte (16 int).
// It is expected that the timing of step 2 is half of step 1, the same for other smaller step sizes.
// There is not a big diff between step 1~16, bcs the data is already in the 64 byte cache, and reading/writing to
// cache is almost free.

int main(int argc, char* argv[])
{
  std::chrono::steady_clock::time_point start, end;
  std::chrono::steady_clock::duration elapsed;

  // cache line size ==========================
  constexpr size_t size = 1 << 30;
  // constexpr size_t size = 1 << 20;
  // constexpr size_t size = 1 << 5;

  std::cout << (size / 1024 / 1024) << " " << std::boolalpha << (2 << 26 == 1 << 27) << std::endl;

  int* arr = new int[size];

  for (int j = 0; j < size; ++j) arr[j] = 1;

  for (int i = 0; i < 12; ++i)
  {
    int step = 1 << i;
    // std::cout << " working on step: " << step << std::endl;

    start = std::chrono::steady_clock::now();

    for (int j = 0; j < size; j += step) arr[j]++;

    end = std::chrono::steady_clock::now();
    elapsed = end - start;

    std::cout << step << ": " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " (us) \n";
  }

  // L1/L2 cache size =============================
  std::cout << "\n\n";
  int steps = 64 * 1024 * 1024;  // Arbitrary number of steps
  int inc = 256;
  for (int arraysize = inc; arraysize <= 268435456; arraysize *= 2)
  {
    std::vector<int> myArr(arraysize);
    int lengthMod = myArr.size() - 1;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < steps; i++)
    {
      myArr[(i * 16) & lengthMod]++;  // (x & lengthMod) is equal to (x % arr.Length)
    }
    end = std::chrono::steady_clock::now();
    elapsed = end - start;

    std::cout << arraysize * 4 << ": " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
              << " (us) \n";
  }

  // row major/col major ==========================
  constexpr size_t nn = 1 << 10;
  // constexpr size_t nn = 1024*1024*1024;
  // constexpr size_t nn = 16;

  int arr1[nn][nn];

  for (int i = 0; i < nn; ++i)
    for (int j = 0; j < nn; ++j) arr1[i][j] = i + j;

  start = std::chrono::steady_clock::now();

  for (int i = 0; i < nn; ++i)
    for (int j = 0; j < nn; ++j)
    {
      int temp = arr1[i][j];
      temp += 1;
      arr1[i][j] = temp;
      // std::cout << i << ", " << j << ": " << arr1[i][j] << std::endl;
    }

  end = std::chrono::steady_clock::now();
  elapsed = end - start;

  std::cout << "row major: " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() << " (ns) \n";

  for (int i = 0; i < nn; ++i)
    for (int j = 0; j < nn; ++j) arr1[i][j] = i + j;

  start = std::chrono::steady_clock::now();

  for (int i = 0; i < nn; ++i)
    for (int j = 0; j < nn; ++j)
    {
      // arr1[j][i] += 1;
      int temp = arr1[j][i];
      temp += 1;
      arr1[j][i] = temp;
      // std::cout << i << ", " << j << ": " << arr1[j][i] << std::endl;
    }

  end = std::chrono::steady_clock::now();
  elapsed = end - start;

  std::cout << "col major: " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() << " (ns) \n";

  // row major/col major ==========================
  // constexpr size_t s2 = 1 << 15;
  std::cout << "row-col hash \n";
  size_t s2;

  inc = 50;
  std::chrono::steady_clock::duration row_elapsed, col_elapsed;
  for (int arraysize = inc; arraysize <= 1400; arraysize += inc)
  {
    s2 = arraysize;

    // std::cout << "checkpoint 0 \n";
    int arr2[s2][s2];
    // std::cout << "checkpoint 01 \n";

    // for (int i = 0; i<s2; ++i)
    //   for (int j = 0; j<s2; ++j)
    //     arr2[i][j] = i+j;

    start = std::chrono::steady_clock::now();

    for (int i = 0; i < s2; ++i)
      for (int j = 0; j < s2; ++j)
      {
        arr2[j][i] = std::sqrt(std::hash<int>()(i * s2 + j));
      }

    end = std::chrono::steady_clock::now();
    col_elapsed = end - start;

    start = std::chrono::steady_clock::now();

    for (int i = 0; i < s2; ++i)
      for (int j = 0; j < s2; ++j)
      {
        arr2[i][j] = std::sqrt(std::hash<int>()(j * s2 + i));
        // std::cout << i << ", " << j << ": " << arr1[i][j] << std::endl;
      }

    end = std::chrono::steady_clock::now();
    row_elapsed = end - start;
    // std::cout << "checkpoint 1 \n";
    // std::cout << "row major: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " (ns)
    // \n";

    // for (int i = 0; i<s2; ++i)
    //   for (int j = 0; j<s2; ++j)
    //     arr2[i][j] = i+j;

    // std::cout << "col major: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " (ns)
    // \n";
    std::cout << s2 << ": " << std::chrono::duration_cast<std::chrono::microseconds>(row_elapsed).count() << " "
              << std::chrono::duration_cast<std::chrono::microseconds>(col_elapsed).count() << " \n";
    // std::cout << "checkpoint 2 \n";
  }

  // row major/col major ==========================
  // inc = 4*1024*1024;
  inc = 0.1 * 1024 * 1024;
  std::cout << "\n\n";
  // for (int arraysize = 4*1024*1024; arraysize<=24*1024*1024; arraysize+=inc)
  for (int arraysize = inc; arraysize <= 6 * 1024 * 1024; arraysize += inc)
  {
    // std::cout << "checkpoint 0 \n";
    int arr3[arraysize];

    for (int step = 64; step <= 1024; step += 64)
    {
      start = std::chrono::steady_clock::now();
      const int rep = 1024 * 1024;  // Number of iterations – arbitrary

      int p = 0;
      for (int i = 0; i < rep; i++)
      {
        arr3[p]++;
        p += step;
        if (p >= arraysize) p = 0;
      }

      end = std::chrono::steady_clock::now();
      elapsed = end - start;
      std::cout << arraysize / 1024. / 1024. << "- " << step << ": "
                << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() << " \n";
    }
  }

  std::cout << " end of the code\n";
  return 0;
}

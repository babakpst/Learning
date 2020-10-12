

/**
 * Threads that waste CPU cycles
 * Babak Poursartip
 * 07/21/2020
 * compile:
 * g++ -pthread main.cpp -o main
 */

#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>

// a simple function that wastes CPU cycles "forever"
void cpu_waster() {
  printf("CPU Waster Process ID: %d\n", getpid());
  // printf("CPU Waster Thread ID %d\n", std::this_thread::get_id());
  std::cout << "CPU Waster Thread ID " << std::this_thread::get_id() << "\n";
  while (true)
    continue;
}

int main() {
  printf("Main Process ID: %d\n", getpid());
  // printf("Main Thread ID: %d\n", std::this_thread::get_id());
  std::cout << "CPU Waster Thread ID " << std::this_thread::get_id() << "\n";

  std::thread thread1(cpu_waster);
  std::thread thread2(cpu_waster);
  std::thread thread3(cpu_waster);
  std::thread thread4(cpu_waster);
  std::thread thread5(cpu_waster);
  std::thread thread6(cpu_waster);
  std::thread thread7(cpu_waster);
  std::thread thread8(cpu_waster);

  while (true) { // keep the main thread alive "forever"
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

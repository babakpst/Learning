
/**
 * Two threads chopping vegetables
 */
#include <chrono>
#include <thread>

bool chopping = true;

void vegetable_chopper(const char *name) {
  unsigned int vegetable_count = 0;
  while (chopping) {
    // printf("%s is chopping \n", name);
    vegetable_count++;
  }
  printf("%s chopped %u vegetables.\n", name, vegetable_count);
}

int main() {
  std::thread olivia(vegetable_chopper, "Olivia");
  std::thread barron(vegetable_chopper, "Barron");

  printf("Barron and Olivia are chopping vegetables...\n");
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  //std::this_thread::sleep_for(std::chrono::seconds(10));
  chopping = false;
  barron.join(); // master thread waits until barron joins. Sync.
  olivia.join();
}

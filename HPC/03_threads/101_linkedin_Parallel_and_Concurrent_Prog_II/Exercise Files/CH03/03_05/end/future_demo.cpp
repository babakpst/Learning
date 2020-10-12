/**
 * Check how many vegetables are in the pantry
 */
#include <future>

int how_many_vegetables() {
    printf("Olivia is counting vegetables...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 42;
}

int main() {
    printf("Barron asks Olivia how many vegetables are in the pantry.\n");
    std::future<int> result = std::async(std::launch::async, how_many_vegetables);
    printf("Barron can do others things while he waits for the result...\n");
    printf("Olivia responded with %d.\n", result.get());
}
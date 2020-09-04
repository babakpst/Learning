#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Server {
private:
  static int load;

public:
  static int compute(long long A, long long B) {
    load += 1;
    if (A < 0) {
      throw std::invalid_argument("A is negative");
    }
    vector<int> v(A, 0);
    int real = -1, cmplx = sqrt(-1);
    if (B == 0)
      throw 0;
    real = (A / B) * real;
    int ans = v.at(B);
    return real + A - B * ans;
  }
  static int getLoad() { return load; }
};
int Server::load = 0;

int main() {

  fstream input("test5.txt");
  int T;
  input >> T;

  while (T--) {
    long long A, B;
    input >> A >> B;
    try {
      cout << Server::compute(A, B) << endl;
    } catch (std::invalid_argument e) {
      cout << "Exception: " << e.what() << endl;
    } catch (bad_alloc e) {
      cout << "Not enough memory" << endl;
      //}catch(int b){
      //    cout << "denominator is zero"
    } catch (std::out_of_range exc) {
      std::cout << "Exception: " << exc.what() << std::endl;
    } catch (exception e) {
      cout << "Exception: " << e.what() << endl;
    } catch (...) {
      cout << "Other Exception\n";
    }
  }
  cout << Server::getLoad(); // << endl;
  return 0;
}
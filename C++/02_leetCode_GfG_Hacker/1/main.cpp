
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

///*
int main() {
    int m,n;
    int p1, p2;
    int minp, count, maxp;

    ifstream input("file.txt");
    ofstream output("out.txt");
    input >> n >>m;
    cout << " n: " << n <<  " m: " << m << endl;
    vector<int> pp(n), cpp(n);
    for (int i = 0; i<n; ++i) pp[i] = i+1;
    for (int i = 0; i<m; ++i){
        input >> p1 >> p2;
        minp = (pp[p1-1]<pp[p2-1])? pp[p1-1]:pp[p2-1];
        maxp = (pp[p1-1]>pp[p2-1])? pp[p1-1]:pp[p2-1];
        cout << " p1: " << p1 <<  " p2: " << p2 << " min:" << minp << endl;
        for (int ii = 0; ii<n; ++ii) {
          if (pp[ii] == maxp) pp[ii] =minp;
        }
        pp[p1-1]=minp;
        pp[p2-1]=minp;

        for (auto c :pp) cout << c << " ";
        cout << endl;

          if (p1>p2) {
            count = 0;
            cpp =pp;
            sort(cpp.begin(),cpp.end());
            for (int ii = 0; ii < n; ii++){
              while (ii < n - 1 && cpp[ii] == cpp[ii + 1]){
                ii++;
                cout << ii << " "<< count << " here\n";
              }
            count++;
            }
          cout << " answer: " <<count << endl;
          output <<count << endl;
        }
            

    }
    return 0;
}
//*/

/*
int main() {
    int m,n;
    int p1, p2;
    int minp, count, maxp;
    cin >> n >>m;
    vector<int> pp(n), cpp(n);
    for (int i = 0; i<n; ++i) pp[i] = i+1;
    for (int i = 0; i<m; ++i){
        cin >> p1 >> p2;
        minp = (pp[p1-1]<pp[p2-1])? pp[p1-1]:pp[p2-1];
        maxp = (pp[p1-1]>pp[p2-1])? pp[p1-1]:pp[p2-1];

        for (int ii = 0; ii<n; ++ii) {
          if (pp[ii] == maxp) pp[ii] =minp;
        }
        pp[p1-1]=minp;
        pp[p2-1]=minp;

          if (p1>p2) {
            count = 0;
            cpp =pp;
            sort(cpp.begin(),cpp.end());
            for (int ii = 0; ii < n; ii++){
              while (ii < n - 1 && cpp[ii] == cpp[ii + 1]){
                ii++;
              }
            count++;
            }
          cout <<count << endl;
        }
    }
    return 0;
}
*/

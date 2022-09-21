
// babak poursartip
// Aug 28, 2022

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
  
  int index(string &target)
  {
    int ret = 0;
    for (int i = 0; i<target.size(); i++)
      ret+= (target[i]-'0') *pow(10,target.size()-1-i);
    return ret;
  }

  string nextPass(string &old, int loc, bool sign) // sing true means +1
  {
    string out = old;
    
    sign ? 
    (out[loc]= (out[loc]=='9'?'0':out[loc]+1))
    :
    (out[loc]= (out[loc]=='0'?'9':out[loc]-1));
    return out;
  }
  
  
  int openLock(vector<string>& deadends, string target) {

    if (target=="0000") return 0;
    vector<bool> visitied(pow(10,target.size()),false);
    
    for (int i = 0; i<deadends.size(); i++)
    {
      if (deadends[i]=="0000") return -1;
      visitied[index(deadends[i])] = true;
    }

    queue<pair<string,int>> myq;
    
    myq.push({target,0});
    visitied[index(target)] = true;
    
    while (!myq.empty())
    {
      pair<string, int> tmp = myq.front();
      myq.pop();
      
      for (int i = 0; i<target.size(); i++)
        for (auto sign: {false,true} ) // here check
          {
            // string newPass = nextPass(tmp.first, i, sign);
            // /*
            string newPass=tmp.first;
            // cout << "1:  " << newPass << endl;
            (sign ? 
            (newPass[i]= (newPass[i]=='9'?'0':newPass[i]+1))
            :
            (newPass[i]= (newPass[i]=='0'?'9':newPass[i]-1))
            );
            // */
            // cout << "2:  " << newPass << endl;
            if (newPass == "0000") return tmp.second+1;
            else if (!visitied[index(newPass)]) 
            {
              myq.push({newPass,tmp.second+1});
              visitied[index(newPass)] = true;
            }
          }
    }
    return -1;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<string> deadends{"0201","0101","0102","1212","2002"};
  // string target = "0202";
 
  // vector<string> deadends{"8888"};
  // string target = "0009";

  //  vector<string> deadends{"0000"};
  //  string target = "8888";

  // vector<string> deadends{"8887","8889","8878","8898","8788","8988","7888","9888"};
  // string target = "8888";

  // vector<string> deadends{"1131","1303","3113","0132","1301","1303","2200","0232","0020","2223"};
  // string target = "3312";

  vector<string> deadends{"1131","1303","3113","0132","1301","1303","2200","0232","0020","2223"};
  string target = "0000";


  Solution t;

  int out = t.openLock(deadends, target);
  cout << " answer: " << out << endl;
  std::cout << " done \n";
  return 0;
}
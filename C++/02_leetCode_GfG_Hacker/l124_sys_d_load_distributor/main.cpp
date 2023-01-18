
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

struct compare
{
  bool operator()(pair<int, int> a, pair<int, int> b) const
  {
    if (a.first != b.first)
      return a.first < b.first;
    else
      return a.second > b.second;
  }
};

class DCLoadBalancer
{
 public:
  unordered_map<int, int> AppMachines;  // holds the machine each app is running - appId, machineId
  unordered_map<int, int> AppLoad;      // holds the size of each application- app, capacity
  vector<pair<int, int>>
    machineCap;  // This is the heap that holds the available machine capacity- capacity, machineId
  unordered_map<int, list<pair<int, int>>>
    AppsOnMachine;  // holds the list of applications and its load running on this machine- appId ,
                    // loadUse

  DCLoadBalancer()
  {
    // cout << " ctor is called \n";
  }

  void addMachine(int machineId, int capacity)
  {
    // if (mym.find(machineId) == end(mym) )
    // {
    // mym.insert({machineId, capacity});
    machineCap.push_back({capacity, machineId});
    push_heap(begin(machineCap), end(machineCap), compare());
    // list<int,int> applist;
    // if (machineId>AppsOnMachine.size()) AppsOnMachine.push_back(list<int,int>());
    // }
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++
  void removeMachine(int machineId)
  {
    // debugging
    // cout << " list of application on this machine: ";
    // for_each(AppsOnMachine[machineId].begin(), AppsOnMachine[machineId].end(), [](pair<int,int>
    // x){ cout << "(" <<x.first << ", "<<x.second << ") ";} ); cout << endl;

    // remove the machine
    // remove from the hash
    // mym.erase(machineId);

    // reomve from the capacity list
    // auto lm = [&](auto x)
    // {
    //   if (x.second == machineId)
    //     x.first = INT_MAX;
    // };

    // for_each(machineCap.begin(), machineCap.end(), lm);

    // remove machineCap
    for (auto it = machineCap.begin(); it != machineCap.end(); it++)
    {
      if (it->second == machineId)
      {
        it->first = INT_MAX;
        break;
      }
    }

    make_heap(begin(machineCap), end(machineCap), compare());
    pop_heap(begin(machineCap), end(machineCap), compare());
    machineCap.pop_back();

    // cout << " machineCap after removing: ";
    // printMachineCap();

    // pass the applications on this machine to other machines
    auto lm2 = [&](auto app) {
      int out = addApplication(app.first, app.second);
      // cout << app.first << " - " << app.second << " added to machine: " << out << endl;
    };
    for_each(AppsOnMachine[machineId].begin(), AppsOnMachine[machineId].end(), lm2);

    // nullify the list of application on this machine
    AppsOnMachine.erase(machineId);
  }

  //++++++++++++++++++++++++++++++++
  int addApplication(int appId, int loadUse)
  {
    AppLoad.insert({appId, loadUse});

    if (loadUse > machineCap[0].first) return -1;

    pop_heap(begin(machineCap), end(machineCap), compare());

    // printMachineCap();

    machineCap[machineCap.size() - 1].first -= loadUse;
    // printMachineCap();

    int ret = machineCap[machineCap.size() - 1].second;
    push_heap(begin(machineCap), end(machineCap), compare());
    // printMachineCap();

    // add application Id to the list of applications running on Id
    if (AppsOnMachine.find(ret) == AppsOnMachine.end())
    {
      list<pair<int, int>> tmp;

      tmp.push_back({appId, loadUse});

      AppsOnMachine.insert({ret, tmp});
    }
    else
      AppsOnMachine[ret].push_back({appId, loadUse});

    AppMachines.insert({appId, ret});

    return ret;
  }

  void stopApplication(int appId)
  {
    if (AppMachines.find(appId) != AppMachines.end())
    {
      int mch = AppMachines[appId];
      int cap = AppLoad[appId];

      // cout << " app is running on: " << mch << " with cap: " << cap << endl;
      AppLoad.erase(appId);

      for (auto it = machineCap.begin(); it != machineCap.end(); it++)
      {
        if (it->second == mch)
        {
          it->first += cap;
          break;
        }
      }
      make_heap(begin(machineCap), end(machineCap), compare());

      // remove from hash
      AppMachines.erase(appId);
      // cout << "delete on machine \n";
      AppsOnMachine[mch].remove({appId, cap});
    }
  }

  vector<int> getApplications(int machineId)
  {
    vector<int> ret(min(AppsOnMachine[machineId].size(), (unsigned long)10), 0);

    // cout << " size of getApp: " << ret.size();

    auto it = AppsOnMachine[machineId].begin();
    for (int count = 0; count < ret.size(); count++)
    {
      ret[count] = it->first;
      it++;
    }

    return ret;
  }

  void printMachineCap()
  {
    cout << " machine Cap: " << endl;
    for_each(machineCap.begin(), machineCap.end(),
             [](auto x) { cout << "(" << x.first << ", " << x.second << ")"; });
    cout << endl;
  }

  void printAppsOnMachine()
  {
    cout << " printing apps on machine: \n";
    for (auto it = AppsOnMachine.begin(); it != AppsOnMachine.end(); it++)
    {
      cout << " apps on machine: " << it->first << endl;
      for_each(it->second.begin(), it->second.end(),
               [](auto x) { cout << "(" << x.first << ", " << x.second << ")"; });
      cout << endl;
    }
  }

  void printAppload()
  {
    cout << " printing apps load: \n";
    for (auto it = AppLoad.begin(); it != AppLoad.end(); it++)
    {
      cout << "(" << it->first << ", " << it->second << ") ";
    }
    cout << endl;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  DCLoadBalancer* obj = new DCLoadBalancer();
  // cout << " checkpoint 0\n";

  obj->addMachine(1, 1);
  obj->addMachine(2, 10);
  obj->addMachine(3, 10);
  obj->addMachine(4, 15);

  // obj->printMachineCap();
  // cout << " checkpoint 1\n";

  cout << " added to: " << obj->addApplication(1, 3) << endl;
  // cout << " checkpoint 11\n";
  cout << " added to: " << obj->addApplication(2, 11) << endl;
  // cout << " checkpoint 12\n";
  cout << " added to: " << obj->addApplication(3, 6) << endl;
  // cout << " checkpoint 13\n";
  cout << " added to: " << obj->addApplication(4, 5) << endl;
  // cout << " checkpoint 2\n";

  vector<int> out = obj->getApplications(2);
  cout << " apps on " << 2 << ":" << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  obj->addMachine(5, 10);
  cout << " added to: " << obj->addApplication(5, 5) << endl;

  cout << endl << endl;
  // obj->printAppsOnMachine();
  // obj->printMachineCap();
  // obj->printAppload();

  obj->stopApplication(3);

  // obj->printAppsOnMachine();
  // obj->printMachineCap();
  // obj->printAppload();

  cout << endl << endl;

  cout << " added to: " << obj->addApplication(6, 5) << endl;
  out = obj->getApplications(4);
  cout << " apps on 2 :" << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  obj->removeMachine(4);

  out = obj->getApplications(2);
  cout << " apps on " << 2 << ":" << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  // Input
  // ["DCLoadBalancer", "addMachine", "addMachine", "addMachine", "addMachine", "addApplication",
  // "addApplication", "addApplication", "addApplication", "getApplications", "addMachine",
  // "addApplication", "stopApplication", "addApplication", "getApplications", "removeMachine",
  // "getApplications"]
  //               [[],       [1, 1],      [2, 10],      [3, 10],      [4, 15],           [1, 3],
  //               [2, 11],           [3, 6],           [4, 5],               [2],      [5, 10], [5,
  //               5],               [3],           [6, 5],               [4],             [4], [2]]
  // [            null,         null,         null,         null,         null,                4, 4,
  // 2,                3,               [3],         null,                5,              null, 2,
  // [1, 2],            null,            [6, 1]]

  std::cout << " done \n";
  return 0;
}

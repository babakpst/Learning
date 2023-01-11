// babak poursartip
// Jan 11, 2023

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class LogAggregator
{
 public:
  vector<list<pair<int, string>>> machine, service;

  LogAggregator(int machines, int services)
  {
    machine.resize(machines);
    service.resize(services);
  }

  void pushLog(int logId, int machineId, int serviceId, string message)
  {
    machine[machineId].push_back({logId, message});
    service[serviceId].push_back({logId, message});
  }

  vector<int> getLogsFromMachine(int machineId)
  {
    vector<int> out(machine[machineId].size(), 0);

    int count = 0;
    for (auto it = begin(machine[machineId]); it != end(machine[machineId]); it++)
      out[count++] = it->first;

    return out;
  }

  vector<int> getLogsOfService(int serviceId)
  {
    vector<int> out(service[serviceId].size(), 0);

    int count = 0;
    for (auto it = begin(service[serviceId]); it != end(service[serviceId]); it++)
      out[count++] = it->first;

    return out;
  }

  vector<string> search(int serviceId, string searchString)
  {
    vector<string> out;

    for (auto it = begin(service[serviceId]); it != end(service[serviceId]); it++)
    {
      if (it->second.find(searchString) != string::npos) out.push_back(it->second);
    }
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  int machines = 3;
  int services = 3;

  LogAggregator* obj = new LogAggregator(machines, services);

  obj->pushLog(2322, 1, 1, "Machine 1 Service 1 Log 1");
  obj->pushLog(2312, 1, 1, "Machine 1 Service 1 Log 2");
  obj->pushLog(2352, 1, 1, "Machine 1 Service 1 Log 3");
  obj->pushLog(2298, 1, 1, "Machine 1 Service 1 Log 4");
  obj->pushLog(23221, 1, 2, "Machine 1 Service 2 Log 1");
  obj->pushLog(23121, 1, 2, "Machine 1 Service 2 Log 2");
  obj->pushLog(23222, 2, 2, "Machine 2 Service 2 Log 1");
  obj->pushLog(23122, 2, 2, "Machine 2 Service 2 Log 2");
  obj->pushLog(23521, 1, 2, "Machine 1 Service 2 Log 3");
  obj->pushLog(22981, 1, 2, "Machine 1 Service 2 Log 4");
  obj->pushLog(23522, 2, 2, "Machine 2 Service 2 Log 3");
  obj->pushLog(22982, 2, 2, "Machine 2 Service 2 Log 4");

  vector<int> param_2 = obj->getLogsFromMachine(2);
  cout << " answer: ";
  for_each(param_2.begin(), param_2.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  vector<int> param_3 = obj->getLogsOfService(2);
  cout << " answer: ";
  for_each(param_3.begin(), param_3.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  vector<string> param_4 = obj->search(1, "Log 1");
  cout << " answer: ";
  for_each(param_4.begin(), param_4.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  vector<string> param_5 = obj->search(2, "Log 3");
  cout << " answer: ";
  for_each(param_5.begin(), param_5.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}

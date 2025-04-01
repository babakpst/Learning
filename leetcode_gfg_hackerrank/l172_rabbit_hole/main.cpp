

/*
You're having a grand old time clicking through the rabbit hole that is your favorite online encyclopedia.
The encyclopedia consists of N different web pages, numbered from 1 to N. Each page i contains nothing but a single link
to a different page Li. A session spent on this website involves beginning on one of the N pages, and then navigating
around using the links until you decide to stop. That is, while on page i, you may either move to page Li, or stop your
browsing session. Assuming you can choose which page you begin the session on, what's the maximum number of different
pages you can visit in a single session? Note that a page only counts once even if visited multiple times during the
session.

Constraints
2≤N≤500,000
1≤ Li ≤N
Li≠i

Sample test case #1
N = 4
L = [4, 1, 2, 1]
Expected Return Value = 4

Sample test case #2
N = 5
L = [4, 3, 5, 1, 2]
Expected Return Value = 3

Sample test case #3
N = 5
L = [2, 4, 2, 2, 3]
Expected Return Value = 4

Sample Explanation
In the first case, you can visit all 4 pages in a single browsing session if you begin on page 3. For example, you can
visit the sequence of pages 3→2→1→4.

In the second case, you can only visit at most 3 different pages − for example, the sequence of pages
3→5→2.

In the third case, you can only visit at most 4 different pages − for example, the sequence of pages
5→3→2→4.

*/

#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// working but slow.
int getMaxVisitableWebpages2(int N, vector<int> L)
{
  int maxp = 0;
  vector<bool> visited(N, false);
  vector<bool> visited2(N, false);

  for (int i = 0; i < N; i++) L[i] = L[i] - 1;

  for (int i = 0; i < N; i++)
  {
    if (visited2[i] == false)
      visited2[i] == true;
    else
      continue;
    visited[i] = true;
    int num = 1;
    int cur = i;
    cout << " i: " << i << endl;
    while (visited[L[cur]] == false)
    {
      num++;
      cur = L[cur];
      visited[cur] = true;
      cout << " cur: " << cur << endl;
    }
    cout << "num: " << num << endl;
    maxp = max(num, maxp);
    // fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < N; i++) visited[i] = false;
  }

  return maxp;
}

int getMaxVisitableWebpages3(int N, vector<int> L)
{
  for (int i = 0; i < N; i++) L[i] = L[i] - 1;
  vector<int> max_page(N, 0);

  for (int i = 0; i < N; i++)
  {
    if (max_page[i] != 0) continue;
    cout << " i: " << i << endl;
    list<int> pages;
    int cur = i;
    pages.push_back(cur);
    int numPages = 1;

    while (L[cur] != i or max_pages[L[cur]] != 0)
    {
      cout << " cur: " << cur << " " << L[cur] << " " << i << endl;
      numPages++;
      cur = L[cur];
      pages.push_back(cur);
    }

    for (auto page : pages) max_page[page] = numPages;
  }
  auto it = max_element(max_page.begin(), max_page.end());
  return *it;
}

int getMaxVisitableWebpages(int N, vector<int> L)
{
  /*
  max_pages[i]: the max pages you can visit starting from L[i].
  depth[i]:

  For each index i, we will begin search between going to the next positions next_pos= L[i]. if depth[next_pos] != 0,
  then depth[i] = (length it took to get to next_pos) + depth[next_pos, otherwise, continue to search.]

  */

  // convert to 0 index
  for (int i = 0; i < N; i++) L[i] = L[i] - 1;

  vector<int> max_pages(N, 0);

  // traverse all pages
  for (int start = 0; start < N; start++)
  {
    if (max_pages[start] != 0) continue;  // already traversed.

    int cur = start;
    vector<int> path;
    set<int> visited;

    while ((visited.empty() or visited.end == visited.find(cur)) and max_pages[cur] == 0)
    {
      visited.insert(cur);
      path.append(cur);
      cur = L[cur];
    }

    if (max_pages[cur] != 0)
    {
      ----
    }

    // a cycle is detected
  }
  * /
}

int main()
{
  cout << " starts: " << endl;

  vector<int> L = {4, 1, 2, 1};  // 3,0,1,0
  // vector<int> L = {4,3,5,1,2};
  // vector<int> L = {2,4,2,2,3};
  int out = getMaxVisitableWebpages3(L.size(), L);
  cout << out << endl;

  return 0;
}

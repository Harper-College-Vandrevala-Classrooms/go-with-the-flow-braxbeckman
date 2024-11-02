#include "heatflow.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  int ticks{};
  int segments{};
  vector<int> sources{};
  double k{};

  cout << "Welcome to my heatpipe simulation!\n(Disclaimer: I am NOT a physicist)\n"
       << "How many segments would you like the heatpipe to have? ";
  cin >> segments;
  cout << "How many ticks would you like the simulation to run for? ";
  cin >> ticks;
  cout << "What would you like the constant K to be? (0 - 1)";
  cin >> k;

  HeatFlow h(segments, k);

  bool breakout{};
  while (!breakout)
  {
    std::string input{};
    cout << "What position would you like to place a sink? (input \'d\' when done)";
    cin >> input;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(1000000000, '\n');
      cout << "Please enter a valid number (1 - " << segments << ") or d\n";
    }
    else if (input.length() == 1 && input == "d")
    {
      breakout = true;
    }
    else if (all_of(input.begin(), input.end(), ::isdigit))
    {
      if (stoi(input) > segments || stoi(input) < 1)
      {
        cout << "Please enter a valid number in the range of 1 - " << segments << "\n";
      }
      else
      {
        h.addSource(stoi(input) - 1);
      }
    }
    else
    {
      cout << "Please enter a valid number 1 - " << segments << "\n";
    }
  }

  for (int i = 0; i < ticks + 1; i++)
  {
    cout << "Tick #" << i << ": \n";
    h.tick();
    cout << h.prettyPrint() << endl;
    sleep(3);
  }
}

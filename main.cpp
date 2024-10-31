#include "heatflow.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  // cout << "test program\n\n";
  HeatFlow h;
  h.displayPipe();
  sleep(3);
  h.tick();
  h.displayPipe();
  sleep(3);
  h.tick();
  h.displayPipe();
  sleep(3);
  h.tick();
  h.displayPipe();
  sleep(3);
  h.tick();
  h.displayPipe();
  sleep(3);
  h.tick();
  h.displayPipe();
  sleep(3);
}

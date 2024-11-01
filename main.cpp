#include "heatflow.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
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

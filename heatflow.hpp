#pragma once
#include <string>

class HeatFlow
{
public:
  HeatFlow(int desiredSize = 5);
  void displayPipe();
  // int &setArrSize(int *arrPtr, int currentSize, int desiredSize);
  void tick();
  std::string prettyPrint();

private:
  double k{0.2};
  double heatPipe[6]{100, 10, 10, 10, 10};
  double *pipePtr;
  int currentSize{5};
};

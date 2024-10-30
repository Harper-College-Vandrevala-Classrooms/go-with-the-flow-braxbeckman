#pragma once

class HeatFlow
{
public:
  // HeatFlow(int desiredSize = 5);
  void displayPipe();
  // int &setArrSize(int *arrPtr, int currentSize, int desiredSize);

private:
  int heatPipe[5]{10, 10, 10, 10, 10};
  int currentSize{5};
};

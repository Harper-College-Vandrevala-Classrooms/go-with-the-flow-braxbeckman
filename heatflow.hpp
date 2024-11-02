#pragma once
#include <string>
#include <vector>

class HeatFlow
{
public:
  HeatFlow(int desiredSize = 5, double k = 0.1);
  void displayPipe();
  // int &setArrSize(int *arrPtr, int currentSize, int desiredSize);
  void tick();
  std::string prettyPrint();
  void addSource(int);

private:
  double k{0.1};
  double *pipePtr;
  int currentSize{5};
  std::string verticalSpacer{"|"};
  std::string horizontalSpacer{"+-------"};
  std::vector<int> sources{};
};

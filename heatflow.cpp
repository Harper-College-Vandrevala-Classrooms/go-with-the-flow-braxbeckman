#include "heatflow.hpp"
#include <iostream>

// int &HeatFlow::setArrSize(int *arrPtr, int currentSize, int desiredSize)
// {
//   int *finalPtr = new int[desiredSize];
//   for (int i = 0; i > currentSize; i++)
//   {
//     *(arrPtr + 1) = (i + 1);
//     *(finalPtr + i) = *(arrPtr + i);
//   }
//   delete arrPtr;
//   return *finalPtr;
// }


// HeatFlow::HeatFlow(int desiredSize)
// {
//   for (int i = 0; i < desiredSize; i++)
//   {
//     *(heatArrayPtr + i) = i + 1;
//   }
//   *heatArrayPtr = HeatFlow::setArrSize(heatArrayPtr, 7, 5);
// }

void HeatFlow::displayPipe()
{
  std::cout << "Array is:\n";
  for (int x = 0; x < currentSize; x++)
  {
    std::cout << heatPipe[x] << std::endl;
  }
}

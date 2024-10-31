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

void HeatFlow::tick()
{
  double newPipe[6]{100, 0, 0, 0, 0, 0};
  for (int i = 0; i < currentSize; i++)
  {
    int currentCell{}, prevCell{}, nextCell{};
    // loops temp to check the final cell rather than the
    if (i == 0)
    {
      currentCell = i;
      prevCell = (currentSize - 1);
      nextCell = i + 1;
    }


    // vv sinks/sources
    if (i == 0)
    {
      newPipe[0] = 100;
    }
    else
    {
      newPipe[currentCell] =
          (heatPipe[currentCell] + (k * (heatPipe[nextCell] - (2 * heatPipe[currentCell]) +
                                         heatPipe[prevCell]))); // this needs to incorprate //n//, or time, but
    }
    std::cout << "newPipe[" << i << "] = " << newPipe[i] << std::endl;
  } // idk how cause it is 2 am. tommorrow me issue

  for (int i = 0; i < currentSize; i++)
  {
    heatPipe[i] = newPipe[i];
  }
}

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
    
    // loops temp to check the final cell rather than the previous one; simulating a looped heat pipe
    if (i == 0)
    {
      currentCell = i;
      prevCell = (currentSize - 1);
      nextCell = i + 1;
    }
    else if (i == currentSize)
    {
      currentCell = i;
      prevCell = (i - 1);
      nextCell = 0;
    }
    else
    {
      currentCell = i;
      prevCell = (i - 1);
      nextCell = (i + 1);
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
                                         heatPipe[prevCell])));
    }
    std::cout << "newPipe[" << i << "] = " << newPipe[i] << std::endl;
    std::cout << "heatPipe[" << i << "] = " << heatPipe[i] << std::endl << std::endl;
  }

  for (int i = 0; i < currentSize; i++)
  {
    heatPipe[i] = newPipe[i];
  }
}

#include "heatflow.hpp"
#include <iostream>
#include <string>
#include <vector>

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

HeatFlow::HeatFlow(int desiredSize, double k)
{
  pipePtr = new double[desiredSize];
  currentSize = desiredSize;
  this->k = k;

  for (int i = 0; i < currentSize; i++)
  {
    *(pipePtr + i) = 10;
  }
}

void HeatFlow::addSource(int pos)
{
  sources.push_back(pos);
}

void HeatFlow::displayPipe()
{
  std::cout << "Array is:\n";
  for (int x = 0; x < currentSize; x++)
  {
    std::cout << *(pipePtr + x) << std::endl;
  }
}

void HeatFlow::tick()
{
  double *newPipePtr = new double[currentSize];
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
    else if (i == (currentSize - 1))
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
    if (count(sources.begin(), sources.end(), i) != 0)
    {
      *(newPipePtr + i) = 100;
    }
    else
    {
      *(newPipePtr + currentCell) =
        (*(pipePtr + currentCell) +
         (k * (*(pipePtr + nextCell) - (2 * *(pipePtr + currentCell)) + *(pipePtr + prevCell))));
    }
    // std::cout << "newPipe[" << i << "] = " << *(newPipePtr + i) << std::endl;
    // std::cout << "heatPipe[" << i << "] = " << *(heatPipe + i) << std::endl << std::endl;
  }

  for (int i = 0; i < currentSize; i++)
  {
    *(pipePtr + i) = *(newPipePtr + i);
  }
}

std::string HeatFlow::prettyPrint()
{
  std::string output{};
  for (int i = 0; i < currentSize; i++)
  {
    output += horizontalSpacer;
  }
  output += "+\n";

  for (int i = 0; i < currentSize; i++)
  {
    output += verticalSpacer;

    if (*(pipePtr + i) < 10)
    {
      output += "  ";
      output += std::to_string(*(pipePtr + i)).substr(0, 3);
      output += "  ";
    }
    else if (*(pipePtr + i) >= 10 && *(pipePtr + i) < 100)
    {
      output += " ";
      output += std::to_string(*(pipePtr + i)).substr(0, 4);
      output += "  ";
    }
    else
    {
      output += " ";
      output += std::to_string(*(pipePtr + i)).substr(0, 5);
      output += " ";
    }
  }
  output += verticalSpacer;
  output += "\n";

  for (int i = 0; i < currentSize; i++)
  {
    output += horizontalSpacer;
  }
  output += "+\n";
  return output;
}

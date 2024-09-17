#include <assert.h>
#include <iostream>
#include <sstream>

namespace TestPackage
{
  std::string generateColorPairNumberStringForTest(int i, int j);
  void testAlignment();
}

namespace 
{
  const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
  const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

  int numOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
  int numOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);
  int totalNumberOfPairs = numOfMajorColors * numOfMinorColors;

  std::string generateColorPairNumberString(int i, int j)
  {
    std::ostringstream str1;
    str1 << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
    return str1.str();
  }


  int printColorMap() {
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++) {
        std::cout << generateColorPairNumberString(i,j);
      }
    }
    return i * j;
  }
}



// The variables and methods used in this package would satify the test cases written in main().
namespace TestPackage
{

  int getMaxLengthOfMajorColor()
  {
    int max = INT_MIN;
    for (auto i = 0; i < numOfMajorColors; i++)
    {
      if (int(strlen(majorColor[i])) > max)
        max = strlen(majorColor[i]);
    }
    return max;
  }

  int maxlengthOfMajorColor = getMaxLengthOfMajorColor();

  int getNumberOfDigits(int n)
  {
    if (n == 0) return 1;
    int temp = n;
    int count = 0;
    while (temp > 0)
    {
      count++; temp = temp / 10;
    }
    return count;
  }

  std::string getSpacesToPrintAfterPairNumber(int i, int j)
  {
    int spaces = getNumberOfDigits(totalNumberOfPairs) - getNumberOfDigits((i * 5) + j) + 4;

    std::string spaceAfterPairNumber = "";
    for (auto k = 0; k < spaces; k++)
    {
      spaceAfterPairNumber += " ";
    }

    return spaceAfterPairNumber;
  }

  std::string getSpacesToPrintAfterMajorColor(int i)
  {
    int numOfSpacesAfterMajorColor = maxlengthOfMajorColor - int(strlen(majorColor[i])) + 4;
    std::string spaceAfterMajorNumber = "";
    for (auto p = 0; p < numOfSpacesAfterMajorColor; p++)
    {
      spaceAfterMajorNumber += " ";
    }
    return spaceAfterMajorNumber;
  }


  std::string generateColorPairNumberStringForTest(int i, int j)
  {
    std::ostringstream str1;
    str1 << i * 5 + j << getSpacesToPrintAfterPairNumber(i, j) + "| " << majorColor[i] << getSpacesToPrintAfterMajorColor(i) + "| " << minorColor[i] << "\n";
    return str1.str();
  }

  // This method would satisfy the test case implemented below in main().
  int testPrintColorMap() {
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++) {
        std::cout << generateColorPairNumberStringForTest(i, j);
      }
    }
    return i * j;
  }

  void testAlignment()
  {
    std::string tempStr = "";
    bool pos_matches = true;
    int pos_of_pipe = -1;

    for (auto i = 0; i < 5; i++) {
      if (pos_matches)
      {
        for (auto j = 0; j < 5; j++) {
          if (pos_matches)
          {
            tempStr = generateColorPairNumberString(i, j);
            if ((i * 5 + j) == 0)
            {
              pos_of_pipe = tempStr.find("|");
            }
            else
            {
              int curr_pos = tempStr.find("|");
              pos_matches = (curr_pos == pos_of_pipe);
            }
          }
        }
      }
    }
    assert(true == pos_matches);
  }
}



int main() {
  int result = printColorMap(); 
  TestPackage::testAlignment();
  std::cout << "All is well (maybe!)\n";
  return 0;
}

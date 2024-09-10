#pragma once
#include "TelCoColorCoder.h"

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {
            "White", "Red", "Black", "Yellow", "Violet"
    };

    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };

    int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);


    void PrintReferenceManual()
    {
        int totalpairs = numberOfMajorColors * numberOfMinorColors;
        for (int PairNumber = 1; PairNumber <= totalpairs; PairNumber++)
        {
            ColorPair colorPair = ColorPair::GetColorFromPairNumber(PairNumber);
            std::cout << "Pair Number: " << PairNumber << "  Colors: " << colorPair.ToString() << "\n";
        }
    }

    std::string ColorPair::ToString()
    {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }


    ColorPair ColorPair::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int ColorPair::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
}

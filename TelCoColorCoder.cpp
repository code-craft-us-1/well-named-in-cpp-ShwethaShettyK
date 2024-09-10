#pragma once
#include "TelCoColorCoder.h"

const char* TelCoColorCoder::MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
};

int numberOfMajorColors =
sizeof(TelCoColorCoder::MajorColorNames) / sizeof(TelCoColorCoder::MajorColorNames[0]);

const char* TelCoColorCoder::MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int TelCoColorCoder::numberOfMinorColors =
sizeof(TelCoColorCoder::MinorColorNames) / sizeof(TelCoColorCoder::MinorColorNames[0]);


void TelCoColorCoder::PrintReferenceManual()
{
     int totalPairs = numberOfMajorColors*numberOfMinorColors;
    for (int PairNumber = 1; PairNumber <= totalPairs; PairNumber++)
    {
        ColorPair colorPair = ColorPair::GetColorFromPairNumber(PairNumber);
        std::cout << "Pair Number: " << PairNumber << "  Colors: " << colorPair.ToString() << "\n";
    }
}

std::string TelCoColorCoder::ColorPair::ToString()
{
    std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
}


TelCoColorCoder::ColorPair TelCoColorCoder::ColorPair::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor =
        (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor =
        (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
}
int TelCoColorCoder::ColorPair::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}

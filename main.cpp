#pragma once
#include "TelCoColorCoder.h"
using namespace TelCoColorCoder;
void testNumberToPair(int pairNumber,
    MajorColor expectedMajor,
    MinorColor expectedMinor)
{
    ColorPair colorPair =
        ColorPair::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    MajorColor major,
    MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = ColorPair::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void PrintReferenceManual()
{

    for (int PairNumber = 0; PairNumber <= 25; PairNumber++)
    {
        ColorPair colorPair =ColorPair::GetColorFromPairNumber(PairNumber);
        std::cout << "Pair Number: " << PairNumber << "  Colors: " << colorPair.ToString() << "\n";
    }
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    PrintReferenceManual();
    return 0;
}

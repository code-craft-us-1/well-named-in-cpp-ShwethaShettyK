#pragma once
#include <iostream>
#include <assert.h>

namespace TelCoColorCoder
{
    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    extern const char* MajorColorNames[];

    extern int numberOfMajorColors;
    extern const char* MinorColorNames[];
    extern int numberOfMinorColors;
    void PrintReferenceManual();

    class ColorPair {
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor) :
            majorColor(major), minorColor(minor)
        {}
        inline MajorColor getMajor() {
            return majorColor;
        }
        inline MinorColor getMinor() {
            return minorColor;
        }
        std::string ToString();
        static  ColorPair GetColorFromPairNumber(int pairNumber);
        static int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    };
}


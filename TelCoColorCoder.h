#pragma once
#include <iostream>
#include <assert.h>
#include "common.h"

namespace TelCoColorCoder
{
    class ColorPair {
        private:
            MajorColor majorColor;
            MinorColor minorColor;
        public:
            ColorPair(MajorColor major, MinorColor minor):
                majorColor(major), minorColor(minor)
            {}
            inline MajorColor getMajor() { return majorColor;
            }
            inline MinorColor getMinor() { return minorColor;
            }
            std::string ToString(); 
            ColorPair GetColorFromPairNumber(int pairNumber)const;         
            int GetPairNumberFromColor(MajorColor major, MinorColor minor)const; 
    };
}

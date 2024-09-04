
#include "telcocolorcoder.h"

std::string TelCoColorCoder::ColorPair::ColorPair::ToString()
{
   std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
}

ColorPair TelCoColorCoder::ColorPair::GetColorFromPairNumber(int pairNumber)const
{
int zeroBasedPairNumber = pairNumber - 1;
MajorColor majorColor = 
    (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
MinorColor minorColor =
    (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
return ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::ColorPair::GetPairNumberFromColor(MajorColor major, MinorColor minor)const {
    return major * numberOfMinorColors + minor + 1;
}
            

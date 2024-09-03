#include <TelCoColorCoder.h>

std::string TelCoColorCoder::ColorPair::ToString()
{
   std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
}
            

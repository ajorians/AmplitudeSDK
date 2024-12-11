#include "Amplitude.h"

using namespace AmplitudeSDK;

constexpr int StartingValue = 0;

Amplitude::Amplitude()
   : _currentValue( StartingValue )
{
}

int Amplitude::GetValue() const
{
   return _currentValue;
}

void Amplitude::IncrementValue()
{
   _currentValue++;
}

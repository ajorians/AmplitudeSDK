#include "Interop.h"

#include <AmplitudeSDK/Amplitude.h>

using namespace AmplitudeInterop;

Interop::Interop()
{
   _amplitude = new AmplitudeSDK::Amplitude();
}

Interop::~Interop()
{
   delete _amplitude;
}

int Interop::GetValue() /*const*/
{
   return _amplitude->GetValue();
}

void Interop::IncrementValue()
{
   _amplitude->IncrementValue();

   OnValueChanged(this, gcnew System::EventArgs());
}

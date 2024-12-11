#pragma once

#include "IAmplitude.h"

namespace AmplitudeSDK
{
   class Amplitude : public IAmplitude
   {
   public:
      Amplitude();

      int GetValue() const override;
      void IncrementValue() override;

   private:
      int _currentValue;
   };
}
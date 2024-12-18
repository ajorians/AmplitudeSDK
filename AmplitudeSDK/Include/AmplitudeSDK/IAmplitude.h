#pragma once

namespace AmplitudeSDK
{
   class IAmplitude
   {
   public:
      virtual ~IAmplitude() = default;

      virtual int GetValue() const = 0;
      virtual void IncrementValue() = 0;
   };
}
#pragma once

namespace AmplitudeSDK
{
   class IAmplitude;
}

namespace AmplitudeInterop
{
   public ref class Interop
   {
   public:
      Interop();
      ~Interop();

      int GetValue() /*const*/;
      void IncrementValue();

      event System::EventHandler^ OnValueChanged;

   private:
      AmplitudeSDK::IAmplitude* _amplitude;
   };
}
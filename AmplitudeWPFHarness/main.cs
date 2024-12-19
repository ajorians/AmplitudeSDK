using System;

namespace AmplitudeWPFHarness
{
   public static class MainClass
   {
      [STAThread]
      public static void Main()
      {
         App app = new();

         app.InitializeComponent();
         app.Run();
         app.Shutdown();
      }
   }
}

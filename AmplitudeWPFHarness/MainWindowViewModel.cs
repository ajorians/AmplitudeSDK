using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Input;

namespace AmplitudeWPFHarness
{
    public class MainWindowViewModel : INotifyPropertyChanged
    {
        //private readonly AmplitudeInterop.Interop _interop;
        public MainWindowViewModel()
        {
            //_interop = new AmplitudeInterop.Interop();

            //_interop.OnValueChanged += ( s, e ) =>
            //{
            NotifyPropertyChanged(nameof(CurrentValue));
            //};

            //_incrementCommand = new RelayCommand( () => _interop.IncrementValue() );
        }

        static public int CurrentValue => 0; // _interop.GetValue();

        //private ICommand _incrementCommand;
        //public ICommand IncrementCommand
        //{
        //   get => _incrementCommand;
        //}

        private void NotifyPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
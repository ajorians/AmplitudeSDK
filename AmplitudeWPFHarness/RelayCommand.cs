using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Windows.Input;

namespace AmplitudeWPFHarness
{
    /// <summary>
    /// Creates a new command.
    /// </summary>
    /// <param name="execute">The execution logic.</param>
    /// <param name="canExecute">The execution status logic.</param>
    /// <exception cref="ArgumentNullException"><c>execute</c> is null.</exception>
    public class RelayCommand(Action execute, Func<bool> canExecute) : ICommand
    {
        #region Fields

        internal readonly Action _execute = execute ?? throw new ArgumentNullException(nameof(execute));
        internal readonly Func<bool> _canExecute = canExecute;

        #endregion // Fields

        #region Constructors

        /// <summary>
        /// Creates a new command that can always execute.
        /// </summary>
        /// <param name="execute">The execution logic.</param>
        public RelayCommand(Action execute)
           : this(execute, null)
        {
        }

        #endregion // Constructors

        #region ICommand Members

        [DebuggerStepThrough]
        public bool CanExecute(object parameter)
        {
            return _canExecute?.Invoke() ?? true;
        }

        public event EventHandler CanExecuteChanged
        {
            add
            {
                if (_canExecute != null)
                {
                    CommandManager.RequerySuggested += value;
                }
            }
            remove
            {
                if (_canExecute != null)
                {
                    CommandManager.RequerySuggested -= value;
                }
            }
        }

        public void Execute(object parameter)
        {
            _execute();
        }

        #endregion // ICommand Members
    }
}
# Specify the WPF app source files (C# and XAML)
set(SOURCE_FILES
    App.xaml
    App.xaml.cs
    MainWindow.xaml
    MainWindow.xaml.cs
    MainWindowViewModel.cs
    RelayCommand.cs
)

# Create an executable target for the WPF app
add_executable(AmplitudeWPFHarness ${SOURCE_FILES})

# Set .NET target framework (e.g., .NET Core or .NET Framework)
set_target_properties(AmplitudeWPFHarness PROPERTIES
    VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2"  # Or .NET Core version, e.g., "netcoreapp3.1"
    VS_GLOBAL_KEYWORD "WPF"                     # Mark the project as a WPF app
)


# Add references to the required WPF assemblies
set_property(TARGET AmplitudeWPFHarness PROPERTY VS_DOTNET_REFERENCES
    "PresentationCore"
    "PresentationFramework"
    "WindowsBase"
    "System"
    "System.Xaml"
    "SampleInterop.dll"
)

# Mark XAML files to be recognized as ApplicationDefinition and Page
set_source_files_properties(App.xaml PROPERTIES
    VS_XAML_TYPE "ApplicationDefinition"
)

set_source_files_properties(MainWindow.xaml PROPERTIES
    VS_XAML_TYPE "Page"
)

add_dependencies(AmplitudeWPFHarness AmplitudeInterop)

# Check if the 'build' directory exists
if (Test-Path -Path "build") {
    Write-Output "Removing existing 'build' directory..."
    Remove-Item -Path "build" -Recurse -Force
}

# Create the 'build' directory
New-Item -Path "build" -ItemType Directory

# Change to the 'build' directory
Set-Location -Path "build"

# Run cmake and make commands
cmake -G "MinGW Makefiles" ..
mingw32-make
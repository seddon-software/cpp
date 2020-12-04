REM -- takeown /f Composite.exe
icacls Composite.exe /setowner chris 
REM -- icacls /help
icacls Composite.exe /grant chris:F


@echo off
SET VC_DIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build


SET QT5_14=C:\Qt\Qt5.14.2\5.14.2\msvc2017_64\bin


SET "PATH=%QT5_14%;%PATH%"
call "%VC_DIR%\vcvars64.bat"
qmake  -r -tp vc  ClientUtility.pro

pause
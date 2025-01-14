
set MATLAB=D:\MATLABR2022b

cd .

if "%1"=="" ("D:\MATLABR2022b\bin\win64\gmake"  -f TemperatureControlSystemModel.mk all) else ("D:\MATLABR2022b\bin\win64\gmake"  -f TemperatureControlSystemModel.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1
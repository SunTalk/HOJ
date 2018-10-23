@echo off

pushd hoj%1

cls
echo COMPILING...
g++ hoj%1.cpp -o hoj%1.exe -DDBG

echo FINISH
if %ERRORLEVEL% EQU 0 (
	hoj%1.exe
)

popd

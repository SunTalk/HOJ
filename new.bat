@echo off

cls
mkdir hoj%1

type template > hoj%1\hoj%1.cpp
echo.>hoj%1\hoj%1.in
echo.>hoj%1\hoj%1.out

echo hoj%1 Created
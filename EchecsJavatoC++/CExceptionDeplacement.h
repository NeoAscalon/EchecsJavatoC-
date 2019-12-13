#pragma once
#include <iostream>

using namespace std;

class CExceptionDeplacement : public exception
{
public:
	CExceptionDeplacement(string ex);
	CExceptionDeplacement(int x, int y, string message);

private:

};

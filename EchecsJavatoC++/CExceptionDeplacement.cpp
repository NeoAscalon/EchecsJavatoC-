#include "CExceptionDeplacement.h"

CExceptionDeplacement::CExceptionDeplacement(string ex)
{
	cout << "Exception " << ex.c_str() << endl;
}

CExceptionDeplacement::CExceptionDeplacement(int x, int y, string message)
{
	cout << message.c_str() << " Position :" << (char)('A' + x) << (char)('1' + y) << endl;
}
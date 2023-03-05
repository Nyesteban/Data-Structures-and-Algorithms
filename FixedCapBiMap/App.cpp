#include "ExtendedTest.h"
#include "ShortTest.h"

#include "FixedCapBiMap.h"


#include <iostream>
#include <crtdbg.h>
using namespace std;


int main() {
	testAll();
	testAllExtended();

	cout << "That's all!" << endl;
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}



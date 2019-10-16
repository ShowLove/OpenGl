#include "MainLoops.h"
#include "Utils.h"

int main(void)
{
	MainLoops loop;
	
	// myTODO add error handling to loop return value
	//loop.legacyTriangle();
	loop.modernOpenGLTriangle();
	
	return 0;
}


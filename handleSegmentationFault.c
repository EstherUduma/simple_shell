#include "shell.h"

/**
* handleSegmentationFault - handle segmentationn faults
* @signalNumber: the signal number
*/

void handleSegmentationFault(int signalNumber)
{
	exit(1);
}

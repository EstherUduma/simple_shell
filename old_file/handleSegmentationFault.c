#include "shell.h"

/**
* handleSegmentationFault - handle segmentationn faults
* @signalNumber: the signal number
*/

void handleSegmentationFault(int signalNumber __attribute__((unused)))
{
	exit(1);
}

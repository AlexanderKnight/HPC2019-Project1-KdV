#include "kdv.h"

struct Domain
{
	int cells;
	double values[cells];
	double coordinates[cells];
	double start;
	double end;
}

void updateDomainValues (struct Domain, oldDomain, struct Domain newDomain)
{
	for (int i=0; i<newDomain.cells;i++)
	{
		oldDomain.values[i] = newDomain.values[i];
	}
}


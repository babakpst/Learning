#include "stdafx.h"
#include "Resource.h"

int Resource::objectcount = 0;

Resource::Resource()
{
	objectcount++;
}

Resource::Resource(const Resource & r)
{
	i = r.i;
	objectcount++;
}

Resource & Resource::operator=(const Resource & r)
{
	i = r.i;
	return *this;
}


Resource::~Resource()
{
	objectcount--;
}


#include "stdafx.h"
#include "Dummy_Cls.h"


bool Dummy::isitme(Dummy& param)
{
	if (&param == this) return true;
	else return false;
}

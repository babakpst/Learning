
#pragma once
#include <iostream>
class Resource
{
private:
	int i=1;
	static int objectcount;
public:
	Resource();
	Resource(const Resource& r);
	Resource& operator=(const Resource&r);
	~Resource();
	void setValue(int ii) { i = ii; }
	int getValue() const { return i; }
  int get2() const { return objectcount; }
};


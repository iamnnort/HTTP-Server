#pragma once
#include "ServerLibrary.h"

#define STATUS "Status:"

class Support: public ServerLibrary
{
public:
	Support() {};
	~Support() {};
	void getStatus(int);
};


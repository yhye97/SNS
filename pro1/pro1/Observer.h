#pragma once
#include <string>
using namespace std;
class Observer
{
private:

public:
	Observer() {};
	~Observer() {};

	virtual void update(int userId, int itemId, string content) = 0;
};


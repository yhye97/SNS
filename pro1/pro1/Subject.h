#pragma once
#include "Observer.h"
#include "User.h"
#include <vector>
using namespace std;

class Subject
{
public:
	Subject() {};
	~Subject() {};

	void setOblist()
	{}

	vector <Observer*> &getoblist() { return oblist; }

private:
	vector<Observer*> oblist;

};


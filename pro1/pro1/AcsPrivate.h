#pragma once
#include "Accessibility.h"
class AcsPrivate :
	public Accessibility
{

public:
	AcsPrivate() {};
	~AcsPrivate() {};

	void update(vector<Observer*> oblist, int userid, int itemid, string content)
	{
		for (int i = 0; i < oblist.size(); i++)
		{
			oblist[i]->update(userid, itemid, content);
		}
	}
};


#pragma once
#include "Accessibility.h"
class AcsPublic :
	public Accessibility
{
private:

public:

	AcsPublic() {};
	~AcsPublic() {};
	void update(vector<Observer*> oblist, int userid, int itemid, string content)
	{
		for (int i = 0; i < oblist.size(); i++)
		{
			oblist[i]->update(userid, itemid, content);
		}
	}
};


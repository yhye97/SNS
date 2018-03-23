#pragma once
#include <string>
#include "Subject.h"
#include "AcsPrivate.h"
#include "AcsPublic.h"
using namespace std;

class Post
	: public Subject
{
public:
	Post()
	{
		userId = 0; itemId = 1; content = "";
	};
	Post(int p, vector <Observer*> f, int uid, int itemid, string con)
	{
		userId = uid;
		itemId = itemid;
		content = con;
	
		if (p == 1)
		{
			acs = new AcsPublic;
			acs->update(f, userId, itemId, content);
		}
		else
		{
			acs = new AcsPrivate;
			acs->update(f, userId, itemId, content);
		}
	}

	~Post() {};
	void setUserId(int uid) { userId = uid; }
	void setItemId(int iid) { itemId=iid; }
	void setContent(string c) { content = c; }

	int getuserid() { return userId; }
	int getitemid() { return itemId; }
	string getcontent() { return content; }

private:

	int userId;
	int itemId;
	string content;
	Accessibility* acs;
};


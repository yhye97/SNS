#pragma once
#include <string>
using namespace std;
class Message
{
public:
	Message() { userId = 0; itemId = 0; content = "";  toId = 0; };
	~Message() {};

	void setUserId(int uid) { userId = uid; }
	void setItemId(int iid) { itemId= iid; }
	void settoId(int tid) { toId = tid; }
	void setContent(string con) { content = con; }

	int getuserId() { return userId; }
	int gettoid() { return toId; }
	int getitemid() { return itemId; }
	string getcontent() { return content; }

private:
	int userId;
	int toId;
	int itemId;
	string content;
};


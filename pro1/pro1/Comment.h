#pragma once
#pragma once
#include <string>
using namespace std;
class Comment
{
public:
	Comment() { userId = 0; postId = 0; content = "";  toId = 0; }
	~Comment() {};

	void setUserId(int uid) { userId = uid; }
	void setpostId(int iid) { postId = iid; }
	void settoId(int tid) { toId = tid; }
	void setContent(string con) { content = con; }

	int getuserId() { return userId; }
	int gettoid() { return toId; }
	int getpostid() { return postId; }
	string getcontent() { return content; }

private:
	int userId; // ��� �� ����� ���̵�
	int toId; // ��� �޸� ����� ���̵�
	int postId; // ��� �޸� �� postid
	string content; // ����
};


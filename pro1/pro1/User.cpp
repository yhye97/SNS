#include "User.h"

User::User()
{
}

User::~User()
{
}

void User::_writePost()
{
	cout << "�� ���� :" << endl;
	int command; string content;

	while (1)
	{
		cout << "\t�������� : " << endl;
		cout << "\t1. ����" << endl;
		cout << "\t2. �����" << endl;
		cout << "\t->";
		cin >> command;
		if (command == 1)
		{
			Subject *s;
			s = new Subject;
			for (int i = 0; i < friendList.size(); i++)
			{
				(s->getoblist()).push_back(friendList[i]);
			}

			cout << "\t���� : ";
			cin >> content;
			Post *pos;
			pos = new Post(command, s->getoblist(), id, myPosts.size(), content);
			addPostToMyPosts(pos);
			break;
		}
		else if (command == 2)
		{
			Subject *s;
			s = new Subject;
			s->getoblist().clear();
			cout << "\t���� : ";
			cin >> content;
			Post *pos;
			pos = new Post(command, s->getoblist(), id, myPosts.size(), content);
			addPostToMyPosts(pos);
			break;
		}
		else
		{
			cout << "�ٽ� �Է��Ͻÿ�" << endl;
		}
	}
}

void User::_acceptFriend(int num)
{
	if (num >= recievedFriendRequest.size())
	{
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
	}
	else
	{
		cout << "ģ�� �����ϼ̽��ϴ�!" << endl;
		addFriend(recievedFriendRequest[num]);
		recievedFriendRequest[num]->addFriend(me[0]);

		for (int i = num; i < recievedFriendRequest.size() - 1; i++)
		{
			recievedFriendRequest[i] = recievedFriendRequest[i + 1];
		}
		recievedFriendRequest.pop_back();
	}
}

void User::_requestFriend(User * toUser)
{
	int count = 0;
	for (int i = 0; i < friendList.size(); i++)
	{
		if (friendList[i] == toUser)
		{
			count++;
		}
	}

	if (count == 0)
	{
		cout << "ģ�� ��û�ϼ̽��ϴ�!" << endl;
		(toUser->getrecievedfriendrequest()).push_back(me[0]);
	}
	else
	{
		cout << "�̹� ģ���̽ʴϴ� " << endl;
	}
}

void User::update(int userId, int itemId, string content)
{
	Post *p;
	p = new Post;
	p->setUserId(userId);
	p->setItemId(itemId);
	p->setContent(content);
	timeline.push_back(p);
}

void User::addPostToMyPosts(Post * nPost)
{
	myPosts.push_back(nPost);
}

void User::addToSendedMessage(Message * sm)
{
	sentMessage.push_back(sm);
}

void User::addToRecievedMessage(Message * rm)
{
	recievedMessage.push_back(rm);
}

void User::setUserId(int uid)
{
	id = uid;
}

void User::setPW(string PW)
{
	pw = PW;
}

void User::setAttrToKeyValueMap(string con, string name)
{
	attrs[con] = name;
}


void User::addFriend(User * f)
{
	friendList.push_back(f);
}

void User::addRequest(User * r)
{
	recievedFriendRequest.push_back(r);
}

void User::addComment(Comment *p)
{
	recievedComment.push_back(p);
	unreadcomment.push_back(p);
}

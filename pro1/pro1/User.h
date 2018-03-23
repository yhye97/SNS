#pragma once
#include "Observer.h"
#include "Post.h"
#include "Subject.h"
#include "Message.h"
#include "Comment.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class User :
	public Observer
{
public:
	User();
	~User();

	void _writePost();
	void _acceptFriend(int num);
	void _requestFriend(User* toUser);
	void update(int userId, int itemId, string content);

	void addPostToMyPosts(Post* nPost);
	void addToSendedMessage(Message* sm);
	void addToRecievedMessage(Message* rm);

	void setUserId(int uid);
	void setPW(string PW);
	void setAttrToKeyValueMap(string con, string name);
	void setme(User* a) { me.push_back(a); }

	void addFriend(User* f);
	void addRequest(User* r);
	void addComment(Comment *p); // 댓글 쓰기
	
	int getid() { return id; }
	string getpw() { return pw; }

	vector <User*> &getfriendlist() { return friendList; }
	vector <Post*> &getmypost() { return myPosts; }
	vector <Post*> &gettimeline() { return timeline; }
	vector <User*> &getrecievedfriendrequest() { return recievedFriendRequest; }
	vector <User*> &getme() { return me; }
	vector<Message*> &getsentMessage() { return sentMessage; }
	vector <Message*> &getreceivedmessage() { return recievedMessage; }
	map <string, string> &getmap() { return attrs; }
	vector <Comment*> &getrecievedcomment() {return recievedComment;}
	vector<Comment*> &getunreadcomment() { return unreadcomment; }

private:

	vector<Post*> myPosts;
	vector<Post*> timeline;
	vector<Message*> sentMessage;
	vector<Message*> recievedMessage;
	vector<User*> friendList;
	vector<User*> recievedFriendRequest;
	vector <User*> me; // 로그인한 사용자 저장한 벡터
	vector<Comment*> recievedComment; // 내가 받은 댓글
	vector <Comment*> unreadcomment; // 내가 아직 안 읽은 댓글

	int id;
	string pw;

	map<string, string> attrs;

};


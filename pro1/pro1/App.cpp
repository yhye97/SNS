#include  "App.h"

App::App()
{
	curuser = new User;
	load_user();
	load_Relation();
	load_message();
	load_post();
	load_timeline();
	load_comment();
}

App::~App()
{
}

void App::run()
{
	while (1)
	{
		string command, id, pw;
		cout << "\t----------------- " << endl;
		cout << "\t   1 :로그인" << endl;
		cout << "\t   2 : 로그아웃" << endl;
		cout << "\t   3 : 종료" << endl;
		cout << "\t----------------- " << endl;
		cout << endl << "\t -> ";
		cin >> command;
		if (command == "1")
		{
			login();
		}
		else if (command == "2")
		{
			(curuser->getme()).clear();
			curuser = NULL;
			run();
		}
		else if (command == "3")
		{
			save_user();
			save_friends();
			save_post();
			save_message();
			save_requested();
			save_timeline();
			save_comment();
			exit(100);
		}
		else
		{
			cout << "\t없는 항목입니다\n";
			run();
		}
	}
}

void App::userrun()
{
	while (1)
	{
		system("pause");
		system("cls");
	cout << endl;
	cout << "\t" << findusername(curuser->getid()) << "님 " << endl;
	if (curuser->getunreadcomment().size() != 0)
	{
		cout << "\t----------------- " << endl;
		for (int i = 0; i < curuser->getunreadcomment().size(); i++)
			cout << findusername(curuser->getunreadcomment()[i]->getuserId()) << "님께서 댓글을 다셨습니다." << endl;
	}

	if (curuser->getrecievedfriendrequest().size() != 0)
	{
		cout << "\t----------------- " << endl;
		for (int i = 0; i < curuser->getrecievedfriendrequest().size(); i++)
			cout << findusername((curuser->getrecievedfriendrequest())[i]->getid()) << "님께서 친구 요청하셨습니다." << endl;
	}


	cout << "\t----------------- " << endl;
	cout << "\t   1 : 글쓰기" << endl;
	cout << "\t   2 : 메시지 쓰기" << endl;
	cout << "\t   3 : 받은 메시지" << endl;
	cout << "\t   4 : 친구 추천" << endl;
	cout << "\t   5 : 친구 요청" << endl;
	cout << "\t   6 : 친구 수락" << endl;
	cout << "\t   7 : 타임라인" << endl;
	cout << "\t   8 : 내 글 출력하기" << endl;
	cout << "\t   9 : 댓글 확인하기" << endl;
	cout << "\t   10 : 뒤로가기" << endl;
	cout << "\t----------------- " << endl;
	string command;
		cout << endl << "\t -> ";
		cin >> command;
		if (command == "1")
		{
			system("pause");
			system("cls");
			writePost();

		}
		else if (command == "2")
		{
			system("pause");
			system("cls");
			sendMessage();
			/*
			
			fdsjklfdklfdjkfjdkl


			
			*/

		}
		else if (command == "3")
		{
			system("pause");
			system("cls");
			cout << endl;
			cout << "\t메시지 출력하기 : " << endl;
			cout << "\t친구 이름을 입력하시오 : ";
			string name;
			cin >> name;
			User* a;
			a = new User;
			a = findUserByName(name);
			printMessages(a->getid());
		}
		else if (command == "4")
		{
			system("pause");
			system("cls");
			friendRecommendation();
		}
		else if (command == "5")
		{
			system("pause");
			system("cls");
			cout << "\t친구 요청하기 : " << endl;
			cout << "\t친구 이름을 입력하시오 : ";
			string name;
			cin >> name;
			User* a;
			a = new User;
			a = findUserByName(name);
			requestFriend(a->getid());
		}
		else if (command == "6")
		{
			system("pause");
			system("cls");
			acceptFriend();
		}
		else if (command == "7")
		{
			system("pause");
			system("cls");
			printTimeline();
		}
		else if (command == "8")
		{
			system("pause");
			system("cls");
			printMyPosting();
		}
		else if (command == "9")
		{
			system("pause");
			system("cls");
			printcomment();
		}
		else if (command == "10")
		{
			system("pause");
			system("cls");
			run();
		}
		else
		{
			cout << "없는 항목입니다 다시 입력해주세요" << endl;
		}
	}
}

void App::load_Relation()
{
		ifstream ifs("friends.txt");
		ifstream ifs2("requested.txt");
		string record;
		while (getline(ifs, record))
		{
			stringstream ifs(record);
			int userId, friendsCnt, friendId;
			ifs >> userId >> friendsCnt;
			User* curUser;
			curUser = new User;
			curUser = findUserById(userId);
			for (int i = 0; i < friendsCnt; i++) {
				ifs >> friendId;
				User* Friend;
				Friend = new User;
				Friend = findUserById(friendId);
				curUser->addFriend(Friend);
			}
		}

		while (getline(ifs2, record))
		{
			int userId, requestCnt, requestid;
			stringstream ifs2(record);
			ifs2 >> userId >> requestCnt;
			User* curUser;
			curUser = new User;
			curUser = findUserById(userId);
			for (int i = 0; i < requestCnt; i++)
			{
				ifs2 >> requestid;
				User* Request;
				Request = new User;
				Request = findUserById(requestid);
				curUser->addRequest(Request);
			}
		}
	
}

void App::load_user()
{
	int userId, postCount, postID;
	string pw, username, attr1, attr2, attr3, attr4;
	string record;
	ifstream ifs("user.txt");
	
	while (getline(ifs, record))
	{
		stringstream ifs(record);
		ifs >> userId >> pw >> username >> attr1 >> attr2 >> attr3 >> attr4;
		User* a;
		a = new User;
		a->setUserId(userId);
		a->setPW(pw);
		a->setAttrToKeyValueMap("이름", username);
		a->setAttrToKeyValueMap("나이", attr1);
		a->setAttrToKeyValueMap("성", attr2);
		a->setAttrToKeyValueMap("대학교", attr3);
		a->setAttrToKeyValueMap("지역", attr4);
		userList.push_back(a);
	}
}


void App::load_post()
{
	int userId;
	int itemId;
	string content, record;
	
	ifstream ifs("post.txt");
	while (getline(ifs, record))
	{
		stringstream ifs(record);
		ifs >> userId;	
		Post* newPost;
		newPost = new Post;
		newPost->setUserId(userId);
		ifs >> itemId;
		newPost->setItemId(itemId);
		ifs >> content;
		newPost->setContent(content);

		User* postedUser;
		postedUser= new User;
		postedUser= findUserById(userId);
		postedUser->addPostToMyPosts(newPost);
	}
}

void App::load_message()
{
	ifstream ifs("message.txt");
	int userId, toId;
	int itemId;
	string content, record;
	while (getline(ifs, record)) {
		stringstream ifs(record);
		ifs >> userId >> toId;
		Message* newMessage;
		newMessage = new Message;
		newMessage->setUserId(userId);
		newMessage->settoId(toId);
		ifs >> itemId;
		newMessage->setItemId(itemId);
		ifs >> content;
		newMessage->setContent(content);
		User* sendedUser = new User;
		sendedUser= findUserById(userId);
		sendedUser->addToSendedMessage(newMessage);
		User* recievingUser = new User;
		recievingUser= findUserById(toId);
		recievingUser->addToRecievedMessage(newMessage);
	}
}

void App::load_timeline()
{
	int timelineuserId, userid, postID;
	string content, record;
	int n = 1;
	ifstream ifs("timeline.txt");
	while (getline(ifs, record))
	{
		stringstream ifs(record);
		ifs >> timelineuserId >> userid >> postID >> content;
		User*a;
		a = new User;
		a = findUserById(timelineuserId);
		
		User*b;
		b = new User;
		b = findUserById(userid);
		
		Subject*s;
		s = new Subject;
		for (int i = 0; i < 1; i++)
		{
			(s->getoblist()).push_back(b);
		}
		Post *p; 
		p = new Post( n, s->getoblist(), timelineuserId, postID, content);
		a->addPostToMyPosts(p);
	}
}

void App::load_comment()
{
	int userId, toid, postID;
	string content, record;

	ifstream ifs("comment.txt");
	while (getline(ifs, record))
	{
		stringstream ifs(record);
		ifs >> userId >> toid >> postID >> content;
		User*b;
		b = new User;
		b = findUserById(toid);

		Comment*cs;
		cs = new Comment;
		cs->setUserId(userId);
		cs->settoId(toid);
		cs->setpostId(postID);
		cs->setContent(content);
		b->addComment(cs);
	}
}

void App::save_friends()
{
	ofstream o_rel;
	o_rel.open("friends.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		o_rel << userList[i]->getid() << " " << (userList[i]->getfriendlist()).size() << " ";
		for (int j = 0; j < (userList[i]->getfriendlist()).size(); j++)
		{
			o_rel << (userList[i]->getfriendlist())[j]->getid() << " ";
		}
		o_rel << endl;
	}
	o_rel.close();
}

void App::save_requested()
{
	ofstream o_req;
	o_req.open("requested.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		o_req << userList[i]->getid() << " " << (userList[i]->getrecievedfriendrequest()).size() << " ";
		for (int j = 0; j < (userList[i]->getrecievedfriendrequest()).size(); j++)
		{
			o_req << (userList[i]->getrecievedfriendrequest())[j]->getid() << " ";
		}
		o_req << endl;
	}
	o_req.close();
}

void App::save_user()
{
	ofstream o_users;
	o_users.open("user.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		o_users << userList[i]->getid() << " " << userList[i]->getpw() << " " << (userList[i]->getmap())["이름"] << " ";
		o_users << (userList[i]->getmap())["나이"] << " " << (userList[i]->getmap())["성"] << " " << (userList[i]->getmap())["대학교"] << " " << (userList[i]->getmap())["지역"] << endl;
	}
	o_users.close();
}

void App::save_post()
{
	ofstream o_posts;
	o_posts.open("post.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		for (int j = 0; j < (userList[i]->getmypost()).size(); j++)
		{
			o_posts << (userList[i]->getmypost())[j]->getuserid() << " " << (userList[i]->getmypost())[j]->getitemid() << " " << (userList[i]->getmypost())[j]->getcontent() << endl;
		}
	}
	o_posts.close();
}

void App::save_message()
{
	ofstream o_mess;
	o_mess.open("message.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		for (int j = 0; j < (userList[i]->getsentMessage()).size(); j++)
		{
			o_mess << (userList[i]->getsentMessage())[j]->getuserId() << " " << (userList[i]->getsentMessage())[j]->gettoid() << " " << (userList[i]->getsentMessage())[j]->getitemid() << " " << (userList[i]->getsentMessage())[j]->getcontent() << endl;
		}
	}
	o_mess.close();

}

void App::save_timeline()
{
	ofstream o_time;
	o_time.open("timeline.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		for (int j = 0; j < (userList[i]->gettimeline()).size(); j++)
		{
			o_time << userList[i]->getid() << " " << (userList[i]->gettimeline())[j]->getuserid() << " ";
			o_time << (userList[i]->gettimeline())[j]->getitemid() << " " << (userList[i]->gettimeline())[j]->getcontent() << endl;
		}
	}
	o_time.close();
}

void App::save_comment()
{
	ofstream o_com;
	o_com.open("comment.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		for (int j = 0; j < (userList[i]->getrecievedcomment()).size(); j++)
		{
			o_com << (userList[i]->getrecievedcomment())[j]->gettoid() << " " << (userList[i]->getrecievedcomment())[j]->getuserId() << " ";
			o_com << (userList[i]->getrecievedcomment())[j]->getpostid() << " " << (userList[i]->getrecievedcomment())[j]->getcontent() << endl;
		}
	}
	o_com.close();
}

string App::findusername(int id)
{
	for (int i = 0; i < userList.size(); i++)
	{
		if (userList[i]->getid() == id)
		{
			auto search = (userList[i]->getmap()).find("이름");
			if (search != (userList[i]->getmap()).end())
			{
				return search->second;
			}
		}
	}
}

void App::login()
{
	int id; string pw;
	cout << "\t ID : ";
	cin >> id;
	cout << "\t PW : ";
	cin >> pw;
	for (int i = 0; i < userList.size(); i++)
	{
		if (id == userList[i]->getid())
		{
			if (pw == userList[i]->getpw())
			{
				curuser = userList[i];
				curuser->setme(curuser);
				userrun();
			}
			else
			{
				cout << "\t비밀번호를 잘못 입력하셨습니다" << endl;
				run();
			}
		}
	}
	cout << "\t없는 ID 입니다" << endl;
	return;
}

void App::writePost()
{
	curuser->_writePost();
}

void App::printMyPosting()
{
	if ((curuser->getmypost()).size() != 0)
	{
		for (int i = (curuser->getmypost()).size() - 1; i >= 0; i--)
		{
			cout << (curuser->getmypost())[i]->getitemid() << " . " << (curuser->getmypost())[i]->getcontent() << endl;
		}
	}
	else
	{
		cout << endl << "글이 없습니다" << endl;
	}
}

void App::printTimeline()
{
	int c = 0;
	for (int i = (curuser->gettimeline()).size(); i > 0; i--)
	{
		cout << (curuser->gettimeline())[i - 1]->getitemid() << ".";
		cout << findusername((curuser->gettimeline())[i-1]->getuserid()) << " : ";
		cout << (curuser->gettimeline())[i-1]->getcontent() << endl;
	}

	if ((curuser->gettimeline()).size() != 0)
	{
		cout << "------------------------" << endl;
		cout << "\t댓글을 다시겠습니까? " << endl << "\t1. 예" << endl << "\t2. 아니오" << endl;
		int command; int num; int count = 0;
		int size = (curuser->gettimeline()).size();
		while (1)
		{
			cout << "\t->";
			cin >> command;
			if (command == 1)
			{
				cout << "\t몇번째 글에 댓글을 다시겠습니까? ";
				while (1)
				{
					cin >> num;
					for (int i = 0; i < (curuser->gettimeline()).size(); i++)
					{
						if ((curuser->gettimeline())[i]->getitemid() == num)
						{
							c++; count++;
							writecomment((curuser->gettimeline())[i]);
							break;
						}
					}

					if (c == 0)
					{
						cout << "\t다시 입력해주세요" << endl;

					}
					else
					{
						break;
					}
					
				}
				if (count != 0)
					{
						break;
					}
			}
			else if (command == 2)
			{
				break;
			}
			else
			{
				cout << "\t다시 입력해주세요. " << endl;
				break;
			}
		}
	}

}

void App::sendMessage()
{
	cout <<endl << "\t메시지 보내기 : " << endl;
	cout << "\t보낼 친구 이름 : ";
	string name; string content;
	cin >> name;
	int count = 0;
	for (int i = 0; i < userList.size(); i++)
	{
		auto search = (userList[i]->getmap()).find("이름");
		if (search != (userList[i]->getmap()).end())
		{
			count++;
			if (search->second == name)
			{
				cout << "\t--------------------------" << endl;
				cout << "\t내용 : ";
				cin >> content;
				Message* newMessage = new Message;
				newMessage->setUserId(curuser->getid());
				newMessage->setItemId(curuser->getsentMessage().size()+1);
				newMessage->settoId(userList[i]->getid());
				newMessage->setContent(content);
				curuser->addToSendedMessage(newMessage);				
				userList[i]->addToRecievedMessage(newMessage);
			}
		}
	}
	
	if (count == 0)
	{
		cout << "\t없는 친구입니다" << endl;
		return;
	}
}

void App::printMessages(int toId)
{
	User* a;
	a = new User;
	a = findUserById(toId);
	
	for (int i = (a->getsentMessage()).size()-1; i >=0 ; i--)
	{
		if ((a->getsentMessage())[i]->gettoid() == curuser->getid())
		{
			cout  << findusername(a->getid()) << " : " << (a->getsentMessage())[i]->getcontent() << endl;
			}
	}

	if ((a->getsentMessage()).size() == 0)
	{
		cout <<endl << "\t받은 메시지가 없습니다" << endl;
	}
}

void App::friendRecommendation()
{
	cout << endl <<"\t친구 추천 : " << endl;
	int count = 0; int count1 = 0;

	cout << "\t속성 3개 동일 리스트 : " << endl;

	for (int i = 0; i < userList.size(); i++)
	{
		if (curuser != userList[i])
		{
			if ((curuser->getmap())["나이"] == (userList[i]->getmap())["나이"])
			{
				count++;
			}
			if ((curuser->getmap())["성"] == (userList[i]->getmap())["성"])
			{
				count++;
			}
			if ((curuser->getmap())["대학교"] == (userList[i]->getmap())["대학교"])
			{
				count++;
			}
			if ((curuser->getmap())["지역"] == (userList[i]->getmap())["지역"])
			{
				count++;
			}

			for (int j = 0; j < (curuser->getfriendlist().size()); j++)
			{
				if (userList[i]->getid() == (curuser->getfriendlist())[j]->getid())
				{
					count = 0;
				}
			}

			if (count >= 3)
			{
				cout << ++count1 << "." << endl;
				cout << "\t이름 : " << (userList[i]->getmap())["이름"] << endl;
				cout << "\t나이 : " << (userList[i]->getmap())["나이"] << endl;
				cout << "\t성별 : " << (userList[i]->getmap())["성"] << endl;
				cout << "\t대학교 : " << (userList[i]->getmap())["대학교"] << endl;
				cout << "\t지역 : " << (userList[i]->getmap())["지역"] << endl;
				cout << "\t--------------" << endl;
				break;
			}
		}
	}
	cout << endl;
	cout << "\t친구의 친구 리스트" << endl;

	User *a; a = new User;
	for (int i = 0; i < (curuser->getfriendlist().size()); i++)
	{
		a = (curuser->getfriendlist())[i];
		for (int j = 0; j < a->getfriendlist().size(); j++)
		{
			if ((a->getfriendlist())[j]->getid() != curuser->getid())
			{
				if ((a->getfriendlist())[j]->getid() != a->getid())
				{
					cout << "\t" <<++count1 << ". " << endl;
					cout << "\t이름 : " << (a->getfriendlist()[j]->getmap())["이름"] << endl;
					cout << "\t나이 : " << (a->getfriendlist()[j]->getmap())["나이"] << endl;
					cout << "\t성별 : " << (a->getfriendlist()[j]->getmap())["성"] << endl;
					cout << "\t대학교 : " << (a->getfriendlist()[j]->getmap())["대학교"] << endl;
					cout << "\t지역 : " << (a->getfriendlist()[j]->getmap())["지역"] << endl;
					cout << "\t--------------" << endl;
					break;
				}
			}
		}
	}

	if (count1 == 0)
	{
		cout << "\t추천할 친구가 없습니다." << endl;
		return;
	}
	else
	{
		cout << "\t친구 요청하시겠습니까?" << endl;
		cout << "\t1. 네" << endl;
		cout << "\t2. 아니오" << endl; 
		int command; string name;
		while (1)
		{
			cout << "->";
			cin >> command;
			switch (command)
			{
			case 1:
				cout << endl;
				cout << "\t친구 요청하기 : " << endl;
				cout << "\t친구 이름을 입력하시오 : ";
				cin >> name;
				User* a;
				a = new User;
				a = findUserByName(name);
				a->getrecievedfriendrequest().push_back(curuser);
				cout << "\t친구 요청하셨습니다!" << endl;
				break;
			case 2: userrun();
				break;
			default:
				cout << "\t다시 입력해주세요" << endl;
				break;
			}

			if (command == 1)
			{
				break;
			}
		}
	}
}

void App::requestFriend(int toId)
{
	User* a; a = new User;
	a = findUserById(toId);
	curuser->_requestFriend(a);
}

void App::acceptFriend()
{
	cout << endl;
	cout << "\t친구 수락하기 : " << endl;

	cout << "\t리스트 : " << endl;
	
	for (int i = 0; i < (curuser->getrecievedfriendrequest()).size(); i++)
	{
		cout << i + 1 << " . ";
		cout << ((curuser->getrecievedfriendrequest())[i]->getmap())["이름"] << endl;
		cout << "\t성별 : " << ((curuser->getrecievedfriendrequest())[i]->getmap())["성"] << endl;
		cout << "\t나이 : " << ((curuser->getrecievedfriendrequest())[i]->getmap())["나이"] << endl;
		cout << "\t대학 : " << ((curuser->getrecievedfriendrequest())[i]->getmap())["대학교"] << endl;
		cout << "\t지역 : " << ((curuser->getrecievedfriendrequest())[i]->getmap())["지역"] << endl;
		cout << "\t-----------------------" << endl;
	}

	if ((curuser->getrecievedfriendrequest()).size() == 0)
	{
		cout << "\t요청한 친구가 없습니다 " << endl;
	}

	else
	{
		cout << "\t수락할 친구 번호를 입력하시오 : ";
		int num;
		cin >> num;
		curuser->_acceptFriend(num - 1);
	}
}

void App::writecomment(Post*p)
{
	string con;
	cout << "\t내용 : ";
	cin >> con;
	Comment* c;
	c = new Comment;
	c->setUserId(curuser->getid());
	c->settoId(p->getuserid());
	c->setContent(con);
	c->setpostId(p->getitemid());
	User*a;
	a = new User;
	a = findUserById(p->getuserid());
	a->addComment(c);
}

void App::printcomment()
{
	int count = 0; int a;
	for (int i = curuser->getrecievedcomment().size()-1; i >=0; i--)
	{
		a = (curuser->getrecievedcomment())[i]->getpostid();
		for (int j = (curuser->getmypost()).size()-1; j >= 0; j--)
		{
			if ((curuser->getmypost())[j]->getitemid() == a)
			{
				cout << endl << "\t" << (curuser->getmypost())[j]->getitemid() << " . ";
				cout << (curuser->getmypost())[j]->getcontent() << endl;
				break;
			}
		}
				cout << "\t------------------------" << endl;
				cout << "\t" <<findusername((curuser->getrecievedcomment())[i]->getuserId()) << " : ";
				cout << (curuser->getrecievedcomment())[i]->getcontent() << endl << endl;
				count++;	
	}

	if (count != 0)
	{
		(curuser->getunreadcomment()).clear();
	}

}

User * App::findUserById(int userid)
{
	for (int i = 0; i < userList.size(); i++)
	{
		if (userList[i]->getid() == userid)
		{
			return userList[i];
		}
	}
}

User * App::findUserByName(string name)
{
	for (int i = 0; i < userList.size(); i++)
	{
		auto search = (userList[i]->getmap()).find("이름");
		if (search != (userList[i]->getmap()).end())
		{
			if (search->second == name)
			{
				return userList[i];
			}
		}
	}

}
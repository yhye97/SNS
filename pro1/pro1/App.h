#pragma once
#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class App
{
public:
	App();
	~App();

	void run(); // ����
	void userrun(); // �α����� ����� �޴�

	void load_Relation();
	void load_user();
	void load_post();
	void load_message();
	void load_timeline();
	void load_comment();
	// �����Է�
	void save_friends();
	void save_requested();
	void save_user();
	void save_post();
	void save_message();
	void save_timeline();
	void save_comment();
	// ���� ���

private:
	void login(); // �α���
	void writePost(); // �� ����
	void printMyPosting(); // �� �� ���
	void printTimeline(); // Ÿ�Ӷ��� ���
	void sendMessage(); // �޽��� ������
	void printMessages(int toId); // �޽��� ���
	void friendRecommendation(); // ģ�� ��õ
	void requestFriend(int toId); // ģ�� ��û
	void acceptFriend(); // ģ�� ����
	void writecomment(Post *p); // ��� ����
	void printcomment(); // ��� ���
	
	User* findUserById(int userid); // ���̵�� ����� ã��
	User* findUserByName(string name); // �̸����� ����� ã��
	string findusername(int id); // ���̵�� ����� �̸� ã��
	
	User* curuser; // ���� �α����� �����
	vector<User*> userList; // ����� ����Ʈ
};


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

	void run(); // 실행
	void userrun(); // 로그인한 사용자 메뉴

	void load_Relation();
	void load_user();
	void load_post();
	void load_message();
	void load_timeline();
	void load_comment();
	// 파일입력
	void save_friends();
	void save_requested();
	void save_user();
	void save_post();
	void save_message();
	void save_timeline();
	void save_comment();
	// 파일 출력

private:
	void login(); // 로그인
	void writePost(); // 글 쓰기
	void printMyPosting(); // 내 글 출력
	void printTimeline(); // 타임라인 출력
	void sendMessage(); // 메시지 보내기
	void printMessages(int toId); // 메시지 출력
	void friendRecommendation(); // 친구 추천
	void requestFriend(int toId); // 친구 요청
	void acceptFriend(); // 친구 수락
	void writecomment(Post *p); // 댓글 쓰기
	void printcomment(); // 댓글 출력
	
	User* findUserById(int userid); // 아이디로 사용자 찾기
	User* findUserByName(string name); // 이름으로 사용자 찾기
	string findusername(int id); // 아이디로 사용자 이름 찾기
	
	User* curuser; // 현재 로그인한 사용자
	vector<User*> userList; // 사용자 리스트
};


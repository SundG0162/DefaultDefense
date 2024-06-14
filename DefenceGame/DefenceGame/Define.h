#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#define DECLARE_SINGLETON(type) \
private:\
	type() {}\
	~type() {}\
	static type* m_pInst;\
public:\
static type* getInstance()\
{\
	if(m_pInst == nullptr)\
	{\
		m_pInst = new type;\
	}\
	return m_pInst;\
}\

#define GET_SINGLETON(type) type::getInstance()

#define MAP_WIDTH 31
#define MAP_HEIGHT 20

using std::cin;
using std::cout;
using std::wcin;
using std::wcout;
using std::string; 
using std::wstring; 
using std::map;
using std::vector;
using std::shared_ptr;
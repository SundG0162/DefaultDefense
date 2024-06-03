#pragma once
#include<iostream>
#include<string>
#include<map>
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

using std::cin;
using std::cout;
using std::wcin;
using std::wcout;
using std::string; 
using std::wstring; 
using std::map;
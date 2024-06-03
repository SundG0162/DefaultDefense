#pragma once
#include<iostream>
#include<string>
#include<map>
#define DECLARE_SINGLETON(template) \
private:\
	template() {}\
	~template() {}\
	static template* m_pInst;\
public:\
static template* getInstance()\
{\
	if(m_pInst == nullptr)\
	{\
		m_pInst = new template;\
	}\
	return m_pInst;\
}\

#define GET_SINGLETON(template) template::getInstance()

using std::cin;
using std::cout;
using std::wcin;
using std::wcout;
using std::string; 
using std::wstring; 
using std::map;
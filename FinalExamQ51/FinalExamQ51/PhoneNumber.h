#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class PhoneNumber
{
	friend istream& operator>>(istream&, PhoneNumber&);
public:
	PhoneNumber(string a = "", string e = "", string l = "") : areaCode(a), exchange(e), lineNum(l) {}
	void copy(string&);
private:
	string areaCode, exchange, lineNum;
};

istream& operator>>(istream& is, PhoneNumber& pObj)
{
	is >> pObj.areaCode >> pObj.exchange >> pObj.lineNum;
	return is;
}

void PhoneNumber::copy(string& s)
{
	areaCode = s.substr(0, 5);
	exchange = s.substr(6, 3);
	lineNum = s.substr(10);
}

class Length
{
public:
	Length(string s = "Incorrect number of characters") : message(s) {}
	string what() { return message; }
private:
	string message;
};

class areaCode
{
public:
	areaCode(string s = "area code starts with", int i = 0) : message(s), num(i) {}
	string what() { return message; }
private:
	string message;
	int num;
};

class Exchange
{
public:
	Exchange(string s = "exchange starts with") : message(s) {}
	string what() { return message; }
private:
	string message;
};

class Syntax
{
public:
	Syntax(string s = "Something wrong with format of number") : message(s) {}
	string what() { return message; }
private:
	string message;
};
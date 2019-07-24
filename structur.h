#pragma once

#include <iostream>

using namespace std;

class pointList
{
	void* info;
	pointList* next;
public:
	pointList(void* info) :info(info), next(NULL) {}
	pointList() :info(NULL), next(NULL) {}
	void insertList(void* info);
	void* operator[](int index);
	int getSize();
	~pointList();
};


class table
{
	pointList* info;
	table* next;

public:
	table(pointList* info) :info(info), next(NULL) {}
	table() :info(NULL), next(NULL) {}

	void insertTable(pointList* info);
	pointList* operator[](int index);
	int getSize();

};



class linkList
{
	void* info;
	linkList* next;
	int getSize();
public:
	linkList() :info(NULL), next(NULL) {}
	linkList(void *info) { if (info != NULL)this->info = info; else info = NULL; next = NULL; }
	void addToList(void* info);
	void* operator[](int x);
	~linkList();


};


class musician
{
	int musicianId;
	string musicianName;
	int phone;
	string address;
public:
	musician(int id, char* musicianName, int phone, char* address) :musicianId(id), musicianName(musicianName), phone(phone), address(address){}
	string getMusicianName() { return this->musicianName; }
	int getMusicianId() { return this->musicianId; }

};
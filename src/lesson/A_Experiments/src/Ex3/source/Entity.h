#ifndef Entity_H_
#define Entity_H_
#include <string>
#include <iostream>
using namespace std;

class Entity {

public:

	Entity() {
		this->id = 0;
	}

	Entity(int id, string name, string major) {
		this->id = id;
		this->name = name;
		this->major = major;
	}

	~Entity() {

	}
	int getId() {
		return this->id;
	}

	void setId(int id) {
		this->id = id;
	}

	string getName() {
		return this->name;
	}

	void setName(string name) {
		cout << name << endl;
		this->name = name;
	}

	string getMajor() {
		return this->major;
	}

	void setMajor(string major) {
		cout << major << endl;
		this->major = major;
	}

	void print() {
		cout << "id=" << id << " name=" << name << " major=" << major << endl;
	}

private:
	int id;
	string name;
	string major;

};
#endif


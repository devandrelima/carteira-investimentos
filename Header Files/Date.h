#pragma once
#include <iostream>
using namespace std;

struct Data {
	unsigned dia;
	unsigned mes;
	unsigned ano;
};

istream& operator>>(istream& in, Data& d);
ostream& operator<<(ostream& out, Data& d);

#include "Degree.h"
Degree::Degree() {
	this->sign = true;
	this->func = "";
}
Degree::Degree(string func, bool sign) {
	this->func = func;
	this->sign = sign;
}
void Degree::Find(string func) {
	string argument = func;
	cout << "�������� ���������: " << argument << endl;
	string save = argument;
	for (double x = -10; x < 10.1; x += 0.1) {
		double y = Calculate(x, save);
		Cord ss;
			ss.x = x;
			ss.y = y;
			cd.push_back(ss);
	}
	for (const auto& it : cd) {
		cout << "X: " << it.x << "   Y: " << it.y << endl;
	}
}
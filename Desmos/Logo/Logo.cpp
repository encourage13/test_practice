#include "Logo.h"
using namespace std;

Logo::Logo() {
	this->func = "";
	this->sign = true;
}
Logo::Logo(string func, bool sign) {
	this->func = func;
	this->sign = sign;
}
double Logo::log_base_a(double x, double a) {
	// ����� �� �������� ���������?
	return std::log(x) / std::log(a);
}
void Logo::Find() {
	bool flag = false;
	auto it = this->func.begin();
	it += 3;
	if (*it == '1' && *(it+1)!='.'&& *(it+1)!=',') { return; }
	if (*it == '0') { return; } 
	if (*it == 'e') flag = true;
	string osn;
	for (it; *it != '('; it++) {
		osn += *it;
	}
	string argument = this->Defi(this->func);
	cout << "�������� ���������: " << argument << endl;
	for (double x = -10; x < 10.1; x += 0.125) {
		double y = Calculate(x, argument, argument.size());
		if (y > 0) {
			Cord ss;
			if (flag == false) {
				double a = stod(osn);
				double y1 = log_base_a(y, a);
				ss.x = x;
				ss.y = y1;
				this->cd.push_back(ss);
			}
			else {
				double y1 = log(y);
				ss.x = x;
				ss.y = y1;
				this->cd.push_back(ss);
			}	
		}
	}
	int j = this->cd.size();
	for (int i = 0; i < j;) {
		if (isfinite(this->cd[i].y) == false) {
			this->cd.erase(this->cd.begin() + i);
			j--;
		}
		else {
			i++;
		}
	}
	this->coordinates.push_back({ this->cd,this->sign });
	for (const auto& it : this->cd) {
		cout << "X: " << it.x << "   Y: " << it.y << endl;
	}

}
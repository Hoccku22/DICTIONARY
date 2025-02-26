#include <iostream>
#include <locale.h>
#include <vector>
#include <string.h>

using namespace std;

int find(vector<string> primary, string value) {
	for (int i = 0; i < primary.size(); i++) {
		if (primary[i] == value) {
			return i;
		}
	}
	return -1;
}

class secSlot {
public:
	secSlot(int num, string val) {
		setPointer(num);
		setValue(val);
	}
	void setValue(string s) {
		value = s;
	}
	void setPointer(int num) {
		pointer = num;
	}
private:
	string value;
	int pointer;
};

class DICTIONARY {
public:
	void addPrimary(string s) {
		primary.push_back(s);
	}
	void addSecondary(int pointer, string value)
	{
		secSlot newSlot(pointer, value);
		secondary.push_back(newSlot);
	}
	int getPointer(string s) {
		return find(primary, s);
	}
private:
	vector <string> primary;
	vector <secSlot> secondary;
};

int main() {
	DICTIONARY locale;
	locale.addPrimary("allias");
	locale.addSecondary(0, "als");
}

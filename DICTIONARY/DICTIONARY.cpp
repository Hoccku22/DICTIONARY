#include <iostream>
#include <locale.h>
#include <vector>
#include <string.h>

using namespace std;


//Функция поиска индекса первичного значения по параметру Value
int find(vector<string> primary, string value) {
	for (int i = 0; i < primary.size(); i++) {
		if (primary[i] == value) {
			return i;
		}
	}
	return -1;
}

//Атомарная единица secondary
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
	string getValue() {
		return this->value;
	}
	int getPointer() {
		return this->pointer;
	}
private:
	string value;
	int pointer;
};

class DICTIONARY {
public:
	int primaryLenght(DICTIONARY dictionaryName) {
		return primary.size();
	}
	int secondaryLenght(DICTIONARY dictionaryName) {
		return secondary.size();
	}
	void addPrimary(string s) {
		primary.push_back(s);
	}
	string getPrimary(DICTIONARY dictionaryName, int i) {
		return dictionaryName.primary[i];
	}
	secSlot getSecondary(DICTIONARY dictionaryName, int i) {
		return dictionaryName.secondary[i];
	}
	void addSecondary(int pointer, string value)
	{
		secSlot newSlot(pointer, value);
		secondary.push_back(newSlot);
	}
	int getPrimaryPointer(string s) {
		return find(primary, s);
	}
	void dictList(DICTIONARY dictionaryName) {
		int j = 0;
		for (int i = 0; i < dictionaryName.primaryLenght(dictionaryName); i++) {
			cout << dictionaryName.getPrimary(dictionaryName, i) << "{ ";
			for (int j = 0; j < dictionaryName.secondaryLenght(dictionaryName); j++) {
				if (dictionaryName.getSecondary(dictionaryName, j).getPointer() == i) {
					cout << dictionaryName.getSecondary(dictionaryName, j).getValue() << ", ";
				}
			}
			cout << " }" << endl;
		}
	}
private:
	vector <string> primary;
	vector <secSlot> secondary;
};

int main() {
	DICTIONARY locale;
	locale.addPrimary("allias");
	locale.addSecondary(0, "als");
	locale.dictList(locale);
}

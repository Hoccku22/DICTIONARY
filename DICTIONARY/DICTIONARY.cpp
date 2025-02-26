#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int maxW = 0;

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

	//Инициализатор слота вторичного значения
	secSlot(int num, string val) {
		setPointer(num);
		setValue(val);
	}

	//Задание значения вторичному значению
	void setValue(string s) {
		value = s;
	}

	//Задание указателя на первичное значение
	void setPointer(int num) {
		pointer = num;
	}

	//Получение вторичного значения
	string getValue() {
		return this->value;
	}

	//Получение указателя на первичное значение
	int getPointer() {
		return this->pointer;
	}
private:
	string value;
	int pointer;
};

class DICTIONARY {
public:

	//Получение размера первичного вектора
	int primaryLenght(DICTIONARY dictionaryName) {
		return primary.size();
	}

	//Получение размера вторичного вектора
	int secondaryLenght(DICTIONARY dictionaryName) {
		return secondary.size();
	}

	//Добавление первичного значения
	void addPrimary(string s) {
		primary.push_back(s);
	}

	//Получение первичного значения
	string getPrimary(DICTIONARY dictionaryName, int i) {
		return dictionaryName.primary[i];
	}

	//Получение вторичного значения
	secSlot getSecondary(DICTIONARY dictionaryName, int i) {
		return dictionaryName.secondary[i];
	}

	//Добавление вторичного значения
	void addSecondary(int pointer, string value)
	{
		secSlot newSlot(pointer, value);
		secondary.push_back(newSlot);
	}

	//Поиск индекса первичного значения по имени
	int getPrimaryPointer(string s) {
		return find(primary, s);
	}

	//Вывод всех primary значений и связанных secondary значений
	void dictList(DICTIONARY dictionaryName) {
		int j;
		for (int i = 0; i < dictionaryName.primaryLenght(dictionaryName); i++) {
			cout << setw(maxW) << right << dictionaryName.getPrimary(dictionaryName, i) << ": { ";
			for (int j = 0; j < dictionaryName.secondaryLenght(dictionaryName); j++) {
				if (dictionaryName.getSecondary(dictionaryName, j).getPointer() == i) {
					cout << dictionaryName.getSecondary(dictionaryName, j).getValue();
					if (j+1 < secondary.size() and dictionaryName.getSecondary(dictionaryName, j + 1).getPointer() == i) cout << ", ";
				}
			}
			cout << " }" << endl;
		}
	}
private:
	vector <string> primary;
	vector <secSlot> secondary;
};

//Функция получения ширины строки
int getMaxWidth(DICTIONARY dictionaryName) {
	int len = dictionaryName.primaryLenght(dictionaryName);
	int maxW = 0;
	int curW = 0;
	for (int i = 0; i < len; i++) {
		curW = dictionaryName.getPrimary(dictionaryName, i).length();
		if (curW > maxW) maxW = curW;
	}
	return maxW;
}

int main() {
	DICTIONARY locale;
	locale.addPrimary("allias");
	locale.addPrimary("range");
	locale.addPrimary("VeryLongAndStupidName");
	maxW = getMaxWidth(locale);
	locale.addSecondary(0, "als");
	locale.addSecondary(0, "alis");
	locale.addSecondary(1, "rng");
	locale.addSecondary(2, "VLASN");
	locale.dictList(locale);
}

#include <iostream>
#include <string.h>
#include <vector>
#define endl '\n';
#define cout std::cout
class myString{
private:
	char* str;
	int string_length;
	int memory_capacity;
public:
	myString(char c) {
		str = new char[1];
		str[0] = c;
		string_length = 1;
		memory_capacity = 1;
	}
	myString(const char * s);
	myString(const myString& s);
	explicit myString(int k) {
		memory_capacity = k;
		str = new char[memory_capacity];
		string_length = 0;
	}
	~myString() {
		delete[] str;
	}
	int length() const;
	void concat(char* s);
	

	int find(int, const myString& ) const;
	int find(int find_from, char c) const;
	int find(int find_from, const char* s) const;

	bool sameAs(char* s);
	int compare(const myString& str) const; //0:same, 1:str이 더 크다, -1:s가 더크다
	void print() const;
	void println() const;
	void reserve(int size);
	int capacity() const;
	myString& assign(const myString& s);
	myString& assign(const char* s);
	char at(int i) const;
	myString& insert(int loc, const myString& s);
	myString& insert(int loc, const char* s);
	myString& insert(int loc, char c);
	myString& erase(int loc, int num);
	friend std::vector<int> makeTable(const myString&);
	friend std::ostream& operator<<(std::ostream &out, const myString&);
};

myString::myString(const char* s) {

	string_length = strlen(s);
	memory_capacity = string_length;
	str = new char[string_length];
	for (int i = 0; i < string_length; i++) {
		str[i] = s[i];
	}
}
myString::myString(const myString& s) {
	string_length = s.string_length;
	memory_capacity = string_length;
	str = new char[string_length];
	for (int i = 0; i < string_length; i++) {
		str[i] = s.str[i];
	}
}

myString& myString::erase(int loc, int num) {
	//loc에 해당하는 문자 부터 num개의 문자 지우기
	//abcd, erase(1,2) -> ad
	if (num < 0 || loc<0 || loc>string_length) return *this;

	for (int i = loc + num; i < string_length; i++) {
		str[i - num ] = str[i];
	}
	string_length -= num;
	return *this;
}
int myString::length() const {
	return string_length;
}
void myString::concat(char * s)
{
	char* nstr = new char[string_length + strlen(s)];
	for (int i = 0; i < string_length; i++) {
		nstr[i] = str[i];
	}
	for (int i = string_length; i < strlen(s) + string_length; i++) {
		nstr[i] = s[i - string_length];
	}
	string_length = strlen(nstr);
	delete str;
	str = nstr;
}

std::vector<int> makeTable(const myString& str) {
	char* pattern = str.str;
	std::vector<int> table(str.string_length, 0);
	int i, j=0;
	for (int i = 1; i < str.string_length; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			j += 1;
			table[i] = j;
		}
	}
	return table;
}

std::ostream & operator<<(std::ostream & out, const myString &s)
{
	s.print();
	return out;
}

int myString::find(int find_from,  const myString & pattern) const
{
	std::vector<int>table=makeTable(pattern);
	int j = 0;
	for (int i = find_from; i < string_length; ++i) {
		while (j > 0 && pattern.str[j] != str[i]) {
			j = table[j - 1];
		}
		if (pattern.str[j] == str[i]) {
			if (j == pattern.string_length - 1) {
				return i - pattern.string_length + 2;
			}
			else {
				j++;
			}
		}

	}
	return -1;// 못찾았을 때,
}

int myString::find(int find_from, char c) const
{
	return find(find_from, myString(c));
}

int myString::find(int find_from, const char * s) const
{
	return find(find_from, myString(s));
}

bool myString::sameAs(char * s)
{
	int tlen = sizeof(s) / sizeof(char);
	if (tlen == string_length) {
		for (int i = 0; i < string_length; i++) {
			if (s[i] != str[i]) {
				return false;
			}
		}
		return true;
		
	}
	return false;
}
int myString::compare(const myString& s) const
{
	//1은 (*this)가 사전식으로 더 뒤에 있다.
	//-1은 (*this)가 사전식으로 더 앞에 있다.
	int tlen = s.length();
	if (tlen > string_length) {
		tlen = string_length;
	}
	for (int i = 0; i < tlen; i++) {
		if (s.str[i] != str[i]) {
			if (s.str[i] < str[i]) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	
	if (string_length == s.length()) { return 0; }
	else if (string_length > s.length()) {
		return 1;
	}
	else {
		return -1;
	}

}
void myString::print() const
{
	for (int i = 0; i < string_length; i++) {
		cout << str[i];
	}
}
void myString::println() const
{
	print();
	cout << endl;

}
void myString::reserve(int size)
{
	if (size > memory_capacity) {
		char* mem = new char[size];
		memory_capacity = size;
		for (int i = 0; i < string_length; i++) {
			mem[i] = str[i];
		}
		delete[] str;
		str = mem;
	}
}
int myString::capacity() const
{
	return memory_capacity;
}
myString & myString::assign(const myString & s)
{
	if (memory_capacity < s.string_length) {
		delete[]str;
		str = new char[s.string_length];
		string_length = s.string_length;
		memory_capacity = string_length;
	}
	for (int i = 0; i < string_length; i++) {
		str[i] = s.str[i];
	}
	return *this;
}

myString & myString::assign(const char * s)
{
	int slen = strlen(s);
	if (slen > memory_capacity) {
		string_length = slen;
		delete[]str;
		str = new char[string_length];
		memory_capacity = string_length;
	}
	for (int i = 0; i < string_length; i++) {
		str[i] = s[i];
	}
	return *this;
}

char myString::at(int i) const
{
	if (0 <= i && i < string_length) {
		return str[i];
	}
	return NULL;
}

myString & myString::insert(int loc, const myString & s)
{
	//범위가 넘어가면 자기자신 return
	if (loc<0 || loc>string_length) return *this;

	if (memory_capacity < string_length + s.length()) {
		//새롭게 동적할당하기
		char* prev = str;
		//memory_capacity = string_length + s.length();
		if (memory_capacity * 2 > string_length + s.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + s.string_length;

		str = new char[memory_capacity];

		//<=loc-1
		int i;
		for (i = 0; i < loc; i++) {
			str[i] = prev[i];
		}
		//s
		for (int i = loc; i < loc + s.length(); i++) {
			str[i] = s.str[i - loc];
		}
		for (; i < string_length; i++) {
			str[i + s.length()] = prev[i];
		}

		delete[] prev;

	}
	else {
		//동적할당 안해도 됨 대신 밀어야함
		for (int i = string_length - 1; i >= loc; i--) {
			str[i + s.length()] = str[i];
		}
		//insert
		for (int i = 0; i < s.length(); i++) {
			str[i + loc] = s.str[i];
		}

	}

	string_length += s.length();
	return *this;
}

myString & myString::insert(int loc, const char * s)
{
	return insert(loc, myString(s));
}

myString & myString::insert(int loc, char c)
{
	return insert(loc, myString(c));
}

int main() {
	myString str1("ababacbabaccbaabacaabaaba");
	myString str2("abacaaba");

	cout<<str1.find(0,str2)<<"번째에서 찾았다!"<<endl;
	str2.insert(4, 'j');
	str2.println();
	myString str3("33abchello!");
	cout << str3 << " " << "잘 작동됩니다." << endl;
	return 0;
}
#pragma once
class Str
{
private:
	char* string;
	int size;
public:
	Str(const char string[]) {
		while (string[size] != '\0') {
			size++;
		}
		this->string = new char[size + 1];
		for (int i = 0; i < size; i++) {
			this->string[i] = string[i];
		}
		this->string[size] = '\0';
	}

	//size
	int length() {
		return size;
	}

	//clear
	void clear() {
		delete[]string;
		size = 0;
		string = new char[1]{ '\0' };
	}

	//resize
	void resize(int n, char c='\0') {
		char* buf = new char[n+1];
		if (n > size) {
			for (int i = 0; i < size; i++) {
				buf[i] = string[i];
			}
			for (int i = size; i < n; i++) {
				buf[i] = c;
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				buf[i] = string[i];
			}
		}
		buf[n] = '\0';
		size = n;
		delete[]string;
		string = buf;
	}

	//print
	void print() {
		cout << string;
	}

	//empty
	bool empty() {
		//(string[0] == '\0') ? return true : return false;
		if (string[0] == '\0') {
			return true;
		}
		return false;
	}

	//push_back
	void push_back(char c) {
		char* buf = new char[size + 2];
		for (int i = 0; i < size; i++) {
			buf[i] = string[i];
		}
		buf[size] = c;
		buf[++size] = '\0';
		delete[]string;
		string = buf;
	}

	//append
	void append(int n, char c) {
		char* buf = new char[length()+n+1];
		for (int i = 0; i < size; i++) {
			buf[i] = string[i];
		}
		for (int i = size; i < length()+n+1; i++) {
			buf[i] = c;
		}
		buf[length()+n] = '\0';
		size = length() + n;
		delete[]string;
		string = buf;
	}
	void append(Str str) {
		char* buf = new char[size + str.length() + 1];
		for (int i = 0; i < size; i++) {
			buf[i] = string[i];
		}
		for (int i = 0; i < str.length(); i++) {
			buf[i + size] = str.string[i];
		}
		size = size + str.length();
		buf[size] = '\0';
		delete[]string;
		string = buf;
	}
	void append(const char str[]) {
		int strsize = strlen(str);
		char* buf = new char[size + strsize + 1];
		for (int i = 0; i < size; i++) {
			buf[i] = string[i];
		}
		for (int i = 0; i < strsize; i++) {
			buf[i + size] = str[i];
		}
		size = size + strsize;
		buf[size] = '\0';
		delete[]string;
		string = buf;
	}
	void append(const char str[], int pos, int count) {
		resize(pos);
		for (int j = 0; j < count; j++) {
			append(str);
		}
	}
	void append(Str str, int pos, int count) {
		resize(pos);
		for (int j = 0; j < count; j++) {
			append(str);
		}
	}

	//erase
	void erase(int pos) {
		resize(--pos);
	}
	void erase(int pos, int count) {
		if (pos + count < length()) {
			char* buf = new char[length()-count+1];
			for (int i = count; i < length(); i++) {
				buf[i-count] = string[i + pos];
			}
			buf[length() - count] = '\0';
			resize(pos);
			append(buf);
		}
	}

	//insert
	void insert(int pos, int n, char c) {
		char* buf = new char[length() - pos + 1];
		for (int i = pos; i < length(); i++) {
			buf[i - pos] = string[i];
		}
		buf[length() - pos] = '\0';
		resize(pos);
		append(n, c);
		append(buf);
	}
	void insert(int pos, Str str) {
		char* buf = new char[length() - pos + 1];
		for (int i = pos; i < length(); i++) {
			buf[i - pos] = string[i];
		}
		buf[length() - pos] = '\0';
		resize(pos);
		append(str);
		append(buf);
	}
	void insert(int pos, const char str[]) {
		char* buf = new char[length() - pos + 1];
		for (int i = pos; i < length(); i++) {
			buf[i - pos] = string[i];
		}
		buf[length() - pos] = '\0';
		resize(pos);
		append(str);
		append(buf);
	}
	void insert(int pos, Str str, int strpos, int count) {
		char* buf = new char[length() - pos + count + 1];
		char* bufstr = new char[count+1];
		for (int i = pos; i < length(); i++) {
			buf[i - pos] = string[i];
		}
		if (strpos + count < str.length()) {
			for (int i = 0; i < count; i++) {
				bufstr[i] = str.string[i + strpos];
			}
		}
		else {
			for (int i = 0; i < str.length() - strpos; i++) {
				bufstr[i] = str.string[i + strpos];
			}
		}
		bufstr[count] = '\0';
		buf[length() - pos + count] = '\0';
		resize(pos);
		append(bufstr);
		append(buf);
	}
	void insert(int pos, const char str[], int strpos, int count) {
		char* buf = new char[length() - pos + count + 1];
		char* bufstr = new char[count + 1];
		for (int i = pos; i < length(); i++) {
			buf[i - pos] = string[i];
		}
		if (strpos + count < strlen(str)) {
			for (int i = 0; i < count; i++) {
				bufstr[i] = str[i + strpos];
			}
		}
		else {
			for (int i = 0; i < strlen(str) - strpos; i++) {
				bufstr[i] = str[i + strpos];
			}
		}
		bufstr[count] = '\0';
		buf[length() - pos + count] = '\0';
		resize(pos);
		append(bufstr);
		append(buf);
	}

	//substr
	Str substr(int pos) {
		char* buf = new char[length() - pos + 1];
		for (int i = pos; i < length(); i++) {
			buf[i-pos] = string[i];
		}
		buf[length() - pos] = '\0';
		size = length() - pos;
		return Str(buf);
	}
	Str substr(int pos, int count) {
		char* buf = new char[count + 1];
		if (pos + count < length()) {
			for (int i = 0; i < count; i++) {
				buf[i] = string[i + pos];
			}
			buf[count] = '\0';
			return Str(buf);
		}
		else {
			return substr(pos);
		}
	}

	//replace
	void replace(int pos, int count, int n, char c) {
		char* buf = new char[length() - count + 1];
		for (int i = pos + count; i < length(); i++) {
			buf[i - (pos + count)] = string[i];
		}
		buf[length() - count - 1] = '\0';
		resize(pos);
		append(n, c);
		append(buf);
	}
	void replace(int pos, int count, const char str[]) {
		char* buf = new char[length() - pos - count + 1];
		for (int i = pos + count; i < length(); i++) {
			buf[i - (pos + count)] = string[i];
		}
		buf[length() - pos - count] = '\0';
		resize(pos);
		append(str);
		append(buf);
	}
	void replace(int pos, int count, const char str[], int pos2, int count2) {
		char* buf = new char[length() - pos - count + 1];
		char* buf2 = new char[strlen(str) - pos2 - (strlen(str) - count2) + 1];
		for (int i = pos + count; i < length(); i++) {
			buf[i - (pos + count)] = string[i];
		}
		for (int i = 0; i < count2; i++) {
			buf2[i] = str[i + pos2];
		}
		buf[length() - pos - count] = '\0';
		buf2[length() - pos2 - (strlen(str) - count2)] = '\0';
		resize(pos);
		append(buf2);
		append(buf);
	}
	void replace(int pos, int count, Str str, int pos2, int count2) {
		char* buf = new char[length() - pos - count + 1];
		char* buf2 = new char[length() - pos2 - (length() - count2) + 1];
		for (int i = pos + count; i < length(); i++) {
			buf[i - (pos + count)] = string[i];
		}
		for (int i = 0; i < count2; i++) {
			buf2[i] = str.string[i + pos2];
		}
		buf[length() - pos - count] = '\0';
		buf2[length() - pos2 - (length() - count2)] = '\0';
		resize(pos);
		append(buf2);
		append(buf);
	}

	//find
	int find(Str str, int pos = 0) {
		for (int i = pos; i < length(); i++) {
			if (str.string[0] == string[i]) {
				for (int j = i; j < str.length(); j++) {
					if (str.string[j-i] != string[j]) {
						break;
					}
					if (j >= str.length() - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	int find(const char str[], int pos = 0) {
		for (int i = pos; i < length(); i++) {
			if (str[0] == string[i]) {
				for (int j = i; j < strlen(str); j++) {
					if (str[j - i] != string[j]) {
						break;
					}
					if (j >= strlen(str) - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	int find(Str str, int pos, int n) {
		n--;
		for (int i = pos; i < length(); i++) {
			if (str.string[0] == string[i]) {
				for (int j = i; j < str.length() - n; j++) {
					if (str.string[j - i] != string[j]) {
						break;
					}
					if (j >= str.length() - n - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	int find(const char str[], int pos, int n) {
		n--;
		for (int i = pos; i < length(); i++) {
			if (str[0] == string[i]) {
				for (int j = i; j < strlen(str) - n; j++) {
					if (str[j - i] != string[j]) {
						break;
					}
					if (j >= strlen(str) - n - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}

	//rfind
	int rfind(Str str, int pos = 0) {
		for (int i = length(); i >= pos; i--) {
			if (str.string[str.length()-1] == string[i]) {
				for (int j = str.length(); j > i-1; j--) {
					if (str.string[j - i] != string[j]) {
						break;
					}
					if (j <= i-1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	int rfind(const char str[], int pos = 0) {
		for (int i = length(); i >= pos; i--) {
			if (str[strlen(str)-1] == string[i]) {
				for (int j = strlen(str); j < i-1; j--) {
					if (str[j - i] != string[j]) {
						break;
					}
					if (j <= i-1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	int rfind(Str str, int pos, int n) {
		n--;
		for (int i = length(); i >= pos; i--) {
			if (str.string[0] == string[i]) {
				for (int j = str.length(); j > i - 1 + n; j--) {
					if (str.string[j - i] != string[j]) {
						break;
					}
					if (j >= str.length() - n - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	int rfind(const char str[], int pos, int n) {
		n--;
		for (int i = length(); i >= pos; i--) {
			if (str[0] == string[i]) {
				for (int j = strlen(str); j > i - 1 + n; j--) {
					if (str[j - i] != string[j]) {
						break;
					}
					if (j >= strlen(str) - n - 1) {
						return i;
					}
				}
			}
		}
		return -1;
	}

	//find_first_of
	int find_first_of(Str str) {
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < length(); j++) {
				if (str.string[i] == string[j]) {
					return j;
				}
			}
		}
	}
	int find_first_of(const char str[]) {
		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < length(); j++) {
				if (str[i] == string[j]) {
					return j;
				}
			}
		}
	}

	//find_last_of
	int find_last_of(Str str) {
		int c = -1;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < length(); j++) {
				if (str.string[i] == string[j] && c < j) {
					c = j;
				}
			}
		}
		return c;
	}
	int find_last_of(const char str[]) {
		int c = -1;
		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < length(); j++) {
				if (str[i] == string[j] && c < j) {
					c = j;
				}
			}
		}
		return c;
	}

	//find_first_not_of
	int find_first_not_of(Str str) {
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < length(); j++) {
				if (str.string[i] == string[j]) {
					break;
				}
				if (j >= length()-1) {
					return i;
				}
			}
		}
		return -1;
	}
	int find_first_not_of(const char str[]) {
		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < length(); j++) {
				if (str[i] == string[j]) {
					break;
				}
				if (j >= length() - 1) {
					return i;
				}
			}
		}
		return -1;
	}

	//find_last_not_of
	int find_last_not_of(Str str) {
		int c = -1;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < length(); j++) {
				if (str.string[i] == string[j]) {
					break;
				}
				if (j >= length() - 1) {
					c = i;
				}
			}
		}
		return c;
	}
	int find_last_not_of(const char str[]) {
		int c = -1;
		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < length(); j++) {
				if (str[i] == string[j]) {
					break;
				}
				if (j >= length() - 1) {
					c = i;
				}
			}
		}
		return c;
	}
	
	//c_str
	char* c_str() {
		char* buf = new char[length()+1];
		for (int i = 0; i < length(); i++) {
			buf[i] = string[i];
		}
		buf[length()] = '\0';
		return buf;
	}
};

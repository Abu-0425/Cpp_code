﻿#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
	string s1("hello");
	s1.resize(15, '#');
	char *str = (char *)s1.c_str();
	system("pause");
	return 0;
}
#endif

#if 0 
int main()
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	//false false false
	return 0;
}
#endif

#if 0
int main()
{
	string str("Hello Bit.");
	str.reserve(111);
	str.resize(5);
	str.reserve(50);
	cout << str.size() << ":" << str.capacity() << endl;//111:5

	return 0;

}
#endif

#if 0
int main(int argc, char *argv[])
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;
	int size_pos = 0;
	int size_prev_pos = 0;
	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
		size_prev_pos = ++size_pos;
	}
	if (size_prev_pos != strText.size())
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
	}
	cout << endl;
	return 0;

}
#endif

#if 0
int main()
{
	string str = "Hello Bit.";
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it != ' ')
			cout << *it;
		else
			str.erase(it);
		it++;
	}
	return 0;
}
#endif

#if 0
int main()
{
	string s1 = "hello world";
	string s2 = "change world";
	string::iterator it = s1.begin();
	swap(s1, s2);
	while (it != s1.end())
		cout << *it;
	cout << endl;
	return 0;
}
#endif

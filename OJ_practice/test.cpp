#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

#if 0
//�ָ�����
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *lessHead, *lessTail;
		ListNode *greaterHead, *greaterTail;
		greaterHead = greaterTail = new ListNode(-1);
		lessHead = lessTail = new ListNode(-1);
		while (head) {
			if (head->val < x) {
				lessTail->next = head;
				lessTail = head;
			}
			else {
				greaterTail->next = head;
				greaterTail = head;
			}
			head = head->next;
		}
		lessTail->next = greaterHead->next;
		greaterTail->next = nullptr;
		head = lessHead->next;
		delete greaterHead;
		delete lessHead;
		return head;
	}
};


//��ת����
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if(!head || !head->next) {
			return head;
		}
		int len = 1; //ͳ����������
		ListNode *p = head;
		while(p->next) {
			len++;
			p = p->next;
		}
		p->next = head; //�պ�����
		k %= len; //ȡģȥ��
		p = head; 
		//Ѱ�ҶϿ��ĵط�
		while(--len != k) {
			p = p->next;
		}
		//�Ͽ�����������
		head = p->next;
		p->next = nullptr;
		return head;
	}
};

//��Сջ
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		if(minS.empty() || x <= minS.top()) {
			minS.push(x);
		}
	}

	void pop() {
		if(s.top() == minS.top()) {
			minS.pop();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return minS.top();
	}
private:
	stack<int> s;
	stack<int> minS;
};

//ջ��ѹ�뵯��˳��
class Solution {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		size_t i = 0, j = 0;
		stack<int> s;
		while(j < popV.size()) {
			//ջ�ջ���ջ��Ԫ�ز����ڳ�ջԪ��ʱ������ջ
			while(i < pushV.size() && (s.empty() || s.top() != popV[j])) {
				s.push(pushV[i]);
				i++;
			}
			//��ʱ��������ȣ���˵���϶��д�
			if(s.top() != popV[j]) {
				return false;
			}
			s.pop();
			j++;
		}
		return true;
	}
};

//�沨������ʽ��ֵ
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		size_t i = 0;
		for (auto e : tokens) {
			if (e != "+" && e != "-" && e != "*" && e != "/") {
				s.push(atoi(e.c_str()));
			}
			else {
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				int res;
				switch (e[0]) {
				case '+':
					res = left + right;
					break;
				case '-':
					res = left - right;
					break;
				case '*':
					res = left * right;
					break;
				case '/':
					res = left / right;
					break;
				}
				s.push(res);
			}
		}
		return s.top();
	}
};
#endif

#if 0
//��������������������������(�ڵ㰴�ղ���������α��(1,2,3,...))
class LCA {
public:
	int getLCA(int a, int b) {
		//�ֱ�洢�����ڵ������
		vector<int> v1;
		vector<int> v2;
		while (a) {
			v1.push_back(a);
			a /= 2;
		}
		while (b) {
			v2.push_back(b);
			b /= 2;
		}
		int ret = 0;
		int s1 = v1.size();
		int s2 = v2.size();
		int size = min(s1, s2); //�϶������size
		for (int i = size - 1; i >= 0; i--) {
			//�ӽ϶������һ��Ԫ�أ��ϳ������ͬһλ�ã���ʼ�Ƚ�
			if (v1[s1 - 1 - i] == v2[s2 - 1 - i]) {
				ret = v1[s1 - 1 - i];
				break;
			}
		}
		return ret;
	}
};

//���������bit��(byte������)
int main()
{
	int a = 0; 
	while(cin >> a) {
		int count = 0;
		for(int i = 0; i < 8; i++) {
			int tmp = 0; //��ʱ����
			while(i < 8 && (a & 0x1)) {
				tmp++; //����ñ���λΪ1���¼��ʱ���Ȳ������ж���һ������λ
				a >>= 1;
				i++;
			}
			count = max(tmp, count); //���³���
			a >>= 1; //aÿ������һλ
		}
		cout << count << endl;
	}
	return 0;
}
#endif

#if 0
//���밲ȫ�ȼ��ж�
int lengthSorce(string &s)
{
	int len = s.size();
	int sorce = 0;
	if(len >= 8) {
		sorce = 25;
	}
	else if(len >= 5 && len <= 7) {
		sorce = 10;
	}
	else {
		sorce = 5;
	}
	return sorce;
}

int letterSorce(string &s)
{
	int len = s.size();
	int sorce = 0;
	bool lower = false, upper = false;
	for (int i = 0; i < len; i++) {
		if (islower(s[i])) {
			lower = true;
		}
		if (isupper(s[i])) {
			upper = true;
		}
	}
	if (lower && upper) {
		sorce = 20;
	}
	else if (lower || upper) {
		sorce = 10;
	}
	else {
		sorce = 0;
	}
	return sorce;
}

int numberSorce(string &s)
{
	int len = s.size();
	int sorce = 0;
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			count++;
		}
	}
	if (count > 1) {
		sorce = 20;
	}
	else if (count == 1) {
		sorce = 10;
	}
	else {
		sorce = 0;
	}
	return sorce;
}

int symbolSorce(string &s)
{
	int len = s.size();
	int sorce = 0;
	int count = 0;
	for (int i = 0; i < len; i++) {
		if ((s[i] >= 0x21 && s[i] <= 0x2f) || (s[i] >= 0x3a && s[i] <= 0x40)
			|| (s[i] >= 0x5b && s[i] <= 0x60) || (s[i] >= 0x7b && s[i] <= 0x7e)) {
			count++;
		}
	}
	if (count > 1) {
		sorce = 25;
	}
	else if (count == 1) {
		sorce = 10;
	}
	else {
		sorce = 0;
	}
	return sorce;
}

int awardSorce(string &s)
{
	int sorce = 0;
	if ((letterSorce(s) == 20) && numberSorce(s) && symbolSorce(s)) {
		sorce = 5;
	}
	else if (letterSorce(s) && numberSorce(s) && symbolSorce(s)) {
		sorce = 3;
	}
	else {
		sorce = 2;
	}
	return sorce;
}

int main()
{
	string code = "";
	cin >> code;
	int sorce = lengthSorce(code) + letterSorce(code) + numberSorce(code)
		+ symbolSorce(code) + awardSorce(code);
	if (sorce >= 90) {
		cout << "VERY_SECURE" << endl;
	}
	else if (sorce >= 80) {
		cout << "SECURE" << endl;
	}
	else if (sorce >= 70) {
		cout << "VERY_STRONG" << endl;
	}
	else if (sorce >= 60) {
		cout << "STRONG" << endl;
	}
	else if (sorce >= 50) {
		cout << "AVERAGE" << endl;
	}
	else if (sorce >= 25) {
		cout << "WEAK" << endl;
	}
	else {
		cout << "VERY_WEAK" << endl;
	}
	return 0;
}

#if 0
void func(char **m)
{
	++m;
	cout << *m << endl; //afternoon
}

int main()
{
	static char *a[] = { "morning", "afternoon", "evening" }; 
	char **p = a;
	func(p);
	return 0;
}
#endif


#if 0
int findCount(int n, int m)
{
	if(n == 0 || m == 0) {
		return 1;
	}
	else {
		return findCount(n, m - 1) + findCount(n - 1, m);
	}
}

int main()
{
	int n = 0, m = 0;
	cin >> n;
	cin >> m;
	int res = findCount(n, m);
	cout << res << endl;
	return 0;
}
#endif

#if 0
//�ַ����ǰ����ֵ��������ǰ��ճ�������(1,2,both,none)
bool isDict(vector<string> &v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		string s1 = v[i], s2 = v[i + 1];
		if (strcmp(s1.c_str(), s2.c_str()) > 0) {
			return false;
		}
	}
	return true;
}

bool isLeng(vector<string> &v)
{
	int n = v.size();
	for (int i = 0; i < n- 1; i++) {
		if (v[i].size() > v[i + 1].size()) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	if (n < 2) {
		cout << "both" << endl;
		return 0;
	}
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s = "";
		cin >> s;
		v.push_back(s);
	}
	if (isDict(v) && isLeng(v)) {
		cout << "both" << endl;
	}
	else if (isDict(v)) {
		cout << "lexicographically" << endl;
	}
	else if (isLeng(v)) {
		cout << "lengths" << endl;
	}
	else {
		cout << "none" << endl;
	}
	return 0;
}
#endif


#if 0
//�������䷴ת[m, n]
class Solution {
public:
	/**
	*
	* @param head ListNode��
	* @param m int����
	* @param n int����
	* @return ListNode��
	*/
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || head->next == nullptr) {
			return head;
		}
		ListNode *p = head, *q = nullptr;
		//��¼qΪǰ�߲���Ҫ��ת���ֵ����һ���ڵ�
		for (int i = 0; i < m - 1; i++) {
			q = p;
			p = p->next;
		}
		//��ʱpλ��m��λ��
		ListNode *rend = p, *next = nullptr;
		ListNode *prev = p;
		p = p->next; //p�ȵ���һ���ڵ㣬��ʼ��ת
		for (int i = m; i < n; i++) {
			next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		//��ʱp��n+1��λ��
		rend->next = p; //rendΪ��ת��������β
		if (q) { //q��Ϊnullptr����������
			q->next = prev;
		}
		else { //Ϊnullptr���ʾͷ������Ŀ��������ͷ
			head = prev;
		}
		return head;
	}
};

//��������Ӻ�Ϊ0����Ԫ��
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> v;
		int n = num.size();
		if(n < 3) {
			return v;
		}
		sort(num.begin(), num.end()); //����
		for(int i = 0; i < n - 2; i++) {
			int front = i + 1;
			int back = n - 1;
			int add = -num[i]; //�����ߵ�Ŀ���
			while(front < back) {
				if(num[front] + num[back] > add) {
					back--; //back����ǰ�ƶ�Ѱ��
				} 
				else if(num[front] + num[back] < add) {
					front++; //front�������ƶ�����
				}
				else {
					//�ҵ�һ�����Ҫ������ݣ�����
					vector<int> tmp = {num[i], num[front], num[back]};
					v.push_back(tmp);
					//ȥ��
					while(front+1 < back && num[front] == num[front+1]) {
						front++;
					}
					while(back-1 > front && num[back] == num[back-1]) {
						back--;
					}
					front++, back--;
				}
			}
			//ȥ��
			while(i + 1 < n - 2 && num[i] == num[i+1]) {
				i++;
			}
		}
		return v;
	}
};
#endif

#if 0
//��Ҫ2��
//�ֵ�������
int main()
{
	//��������0��ʾ��ǰλ�ÿ��Էŵ��⣬-1��ʾ����
	vector<vector<int>> v;
	int w, h = 0;
	while (cin >> w >> h) {
		v.resize(h);
		for (int i = 0; i < h; i++) {
			v[i].resize(w, 0); //��ʼ��Ϊȫ0
		}
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//��ʾ���Էŵ���
				if (v[i][j] == 0) {
					count++;
					//��ŷ����þ���Ϊ2�ĵ���Ϊ-1����ʾ���ܷŵ���
					if (j - 2 >= 0) {
						v[i][j - 2] = -1;
					}
					if (j + 2 <= w - 1) {
						v[i][j + 2] = -1;
					}
					if (i - 2 >= 0) {
						v[i - 2][j] = -1;
					}
					if (i + 2 <= h - 1) {
						v[i + 2][j] = -1;
					}
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
#endif

/*���ַ���ת������*/
class Solution1 {
public:
	int StrToInt(string str) {
		int n = str.size();
		int i = 0;
		if (str[i] == '+') {
			i++;
		}
		int flag = 1;
		if (str[i] == '-') {
			flag = -flag;
			i++;
		}
		int res = 0;
		while (i < n) {
			if (isdigit(str[i])) {
				res = res * 10 + flag * (str[i] - '0');
			}
			else {
				return 0;
			}
			i++;
		}
		return res;
	}
};
#endif



#if 0
//�жϽ����Ĵ�B���������Ĵ�A����Ȼ�����м��ְ취
bool isHui(string &s)
{
	int n = s.size();
	int begin = 0, end = n - 1;
	while (begin < end) {
		if (s[begin] != s[end]) {
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

int main()
{
	string A, B;
	cin >> A >> B;
	int n = A.size();
	int count = 0;
	string tmp(A);
	for (int i = 0; i < n; i++) {
		tmp.insert(i, B);
		if (isHui(tmp)) {
			count++;
		}
		tmp = A;
	}
	cout << count << endl;

	return 0;
}
#endif

#if 0
//ʮ����ת�������
int main()
{

	int M, N;
	cin >> M >> N;
	string s = "ABCDEF"; //���ڴ���ʮ�������Ĵ洢
	if(N == 10 || M == 0) {
		cout << M << endl;
		return 0;
	}
	//�������
	if(M < 0) {
		M = - M;
		cout << "-";
	}
	string retStr;
	while(M) {
		int rem = M % N; //����
		if(rem >= 10) {
			retStr.push_back(s[rem - 10]);
		}
		else {
			retStr.push_back(rem + '0');
		}
		M /= N; //����M����������
	}
	//���Ӧ��ת
	reverse(retStr.begin(), retStr.end());
	cout << retStr << endl;

	return 0;
}
#endif

#if 0
int main()
{
	int A, B, C = 0;
	int n1, n2, n3, n4 = 0;
	cin >> n1 >> n2 >> n3 >> n4;
	A = (n1 + n3) / 2;
	B = -(n1 - n3) / 2;
	C = -(n2 - n4) / 2;
	if ((n1 == A - B) && (n2 == B - C) && (n3 == A + B) && (n4 == B + C)) {
		cout << A << " " << B << " " << C << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
#endif

#if 0
int main()
{
	string s = "";
	getline(cin, s);
	int n = s.size();
	int sub_len = 0; //Ŀ���Ӵ��ĳ���
	int sub_index = 0; //Ŀ���Ӵ�����ʼ�±�
	int tmp_len = 0; //��ʱ�Ӵ��ĳ���
	int tmp_index = 0; //��ʱ�Ӵ�����ʼ�±�
	for (int i = 0; i < n; i++) {
		while (i < n && (s[i] >= '0' && s[i] <= '9')) {
			tmp_len++;
			if (tmp_len == 1) {
				tmp_index = i;
			}
			i++;
		}
		if (sub_len < tmp_len) {
			// ������Ϣ
			sub_len = tmp_len;
			sub_index = tmp_index;
		}
		// ������ʱ�Ӵ��ĳ���
		tmp_len = 0;
	}
	//��ȡĿ���Ӵ�
	string sub_string = s.substr(sub_index, sub_len);
	cout << sub_string << endl;
	return 0;
}
#endif


#if 0 
//����������
int main()
{
	int n = 0;
	cin >> n;
	if (n <= 2) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int count = 1;
	for (int i = 1; i < n - 1; i++) {
		if (v[i] == v[i + 1]) {
			continue;
		}
		if ((v[i] > v[i - 1] && v[i] > v[i + 1]) ||
			(v[i] < v[i - 1] && v[i] < v[i + 1])) {
			count++;
			if (i != n - 3) {
				i++;
			}
		}
	}
	cout << count << endl;

	return 0;
}
#endif


#if 0
//I like beijing.
//beijing. like I
int main()
{
	string s = "";
	getline(cin, s);
	int length = s.size();
	std::reverse(s.begin(), s.end());

	int start , end = 0; //��¼ÿ�����ʵ���ʼλ��
	int i = 0;
	while (i < length) {
		start = i;
		while (i < length && s[i] != ' ') {
			i++;
		}
		end = i - 1;
		while (start < end) {
			swap(s[start], s[end]);
			start++;
			end--;
		}
		if (i < length && s[i] == ' ') {
			i++;
		}
	}
	cout << s << endl;

	return 0;
}
#endif

#if 0
//ɾ��s1��������s2�г��ֵ��ַ�������ɾ������ַ���
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string res;
	int length1 = s1.size();
	int length2 = s2.size();
	res.resize(length1 + 1, 0);
	int k = 0;
	for (int i = 0; i < length1; i++) {
		bool flag = false;
		for (int j = 0; j < length2; j++) {
			if (s1[i] == s2[j]) {
				flag = true;
			}
		}
		if (flag == false) {
			res[k] = s1[i];
			k++;
		}
	}
	res.resize(k);
	cout << res << endl;

	return 0;
}
#endif

#if 0
//ţţ�����
int main()
{
	int n = 0;
	cin >> n;
	long long max = 0;
	vector<int> v(3 * n);
	for (int a_i = 0; a_i < 3 * n; a_i++) {
		cin >> v[a_i];
	}
	std::sort(v.begin(), v.end());
	for (int i = n; i < 3 * n; i += 2) {
		max += v[i];
	}
	cout << max << endl;

	return 0;
}
#endif
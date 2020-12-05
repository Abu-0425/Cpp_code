#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;



void fun(const int &v1, const int &v2)
{
	cout << v1 << endl; 
	cout << v2 << endl; 
}

int main()
{
	int i = 0;
	fun(++i, i++); //2 0
	//fun(i++, ++i); //1 2
	return 0;
}


#if 0
//旋转链表
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if(!head || !head->next) {
			return head;
		}
		int len = 1; //统计链表长度
		ListNode *p = head;
		while(p->next) {
			len++;
			p = p->next;
		}
		p->next = head; //闭合链表
		k %= len; //取模去重
		p = head; 
		//寻找断开的地方
		while(--len != k) {
			p = p->next;
		}
		//断开并重新连接
		head = p->next;
		p->next = nullptr;
		return head;
	}
};

//最小栈
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

//栈的压入弹出顺序
class Solution {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		size_t i = 0, j = 0;
		stack<int> s;
		while(j < popV.size()) {
			//栈空或者栈顶元素不等于出栈元素时不断入栈
			while(i < pushV.size() && (s.empty() || s.top() != popV[j])) {
				s.push(pushV[i]);
				i++;
			}
			//此时若还不相等，就说明肯定有错
			if(s.top() != popV[j]) {
				return false;
			}
			s.pop();
			j++;
		}
		return true;
	}
};

//逆波兰表达式求值
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
//无穷大满二叉树的最近公共祖先(节点按照层序遍历依次编号(1,2,3,...))
class LCA {
public:
	int getLCA(int a, int b) {
		//分别存储俩个节点的祖先
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
		int size = min(s1, s2); //较短数组的size
		for (int i = size - 1; i >= 0; i--) {
			//从较短数组的一个元素（较长数组的同一位置）开始比较
			if (v1[s1 - 1 - i] == v2[s2 - 1 - i]) {
				ret = v1[s1 - 1 - i];
				break;
			}
		}
		return ret;
	}
};

//求连续最大bit数(byte型数据)
int main()
{
	int a = 0; 
	while(cin >> a) {
		int count = 0;
		for(int i = 0; i < 8; i++) {
			int tmp = 0; //临时长度
			while(i < 8 && (a & 0x1)) {
				tmp++; //如果该比特位为1则记录临时长度并继续判断下一个比特位
				a >>= 1;
				i++;
			}
			count = max(tmp, count); //更新长度
			a >>= 1; //a每次右移一位
		}
		cout << count << endl;
	}
	return 0;
}
#endif

#if 0
//密码安全等级判定
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
//字符串是按照字典序排序还是按照长度排序(1,2,both,none)
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
//链表区间反转[m, n]
class Solution {
public:
	/**
	*
	* @param head ListNode类
	* @param m int整型
	* @param n int整型
	* @return ListNode类
	*/
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || head->next == nullptr) {
			return head;
		}
		ListNode *p = head, *q = nullptr;
		//记录q为前边不需要反转部分的最后一个节点
		for (int i = 0; i < m - 1; i++) {
			q = p;
			p = p->next;
		}
		//此时p位于m的位置
		ListNode *rend = p, *next = nullptr;
		ListNode *prev = p;
		p = p->next; //p先到下一个节点，开始反转
		for (int i = m; i < n; i++) {
			next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		//此时p在n+1的位置
		rend->next = p; //rend为反转后链表的尾
		if (q) { //q不为nullptr则连接链表
			q->next = prev;
		}
		else { //为nullptr则表示头结点就是目标链表的头
			head = prev;
		}
		return head;
	}
};

//数组中相加和为0的三元组
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> v;
		int n = num.size();
		if(n < 3) {
			return v;
		}
		sort(num.begin(), num.end()); //排序
		for(int i = 0; i < n - 2; i++) {
			int front = i + 1;
			int back = n - 1;
			int add = -num[i]; //后俩者的目标和
			while(front < back) {
				if(num[front] + num[back] > add) {
					back--; //back需往前移动寻找
				} 
				else if(num[front] + num[back] < add) {
					front++; //front需往后移动查找
				}
				else {
					//找到一组符合要求的数据，保存
					vector<int> tmp = {num[i], num[front], num[back]};
					v.push_back(tmp);
					//去重
					while(front+1 < back && num[front] == num[front+1]) {
						front++;
					}
					while(back-1 > front && num[back] == num[back-1]) {
						back--;
					}
					front++, back--;
				}
			}
			//去重
			while(i + 1 < n - 2 && num[i] == num[i+1]) {
				i++;
			}
		}
		return v;
	}
};
#endif

#if 0
//不要2！
//分蛋糕问题
int main()
{
	//遍历，用0表示当前位置可以放蛋糕，-1表示不能
	vector<vector<int>> v;
	int w, h = 0;
	while (cin >> w >> h) {
		v.resize(h);
		for (int i = 0; i < h; i++) {
			v[i].resize(w, 0); //初始化为全0
		}
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//表示可以放蛋糕
				if (v[i][j] == 0) {
					count++;
					//将欧几里得距离为2的点设为-1，表示不能放蛋糕
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

/*将字符串转成整形*/
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
//判断将回文串B插入至回文串A中仍然回文有几种办法
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
//十进制转任意进制
int main()
{

	int M, N;
	cin >> M >> N;
	string s = "ABCDEF"; //用于大于十进制数的存储
	if(N == 10 || M == 0) {
		cout << M << endl;
		return 0;
	}
	//负数情况
	if(M < 0) {
		M = - M;
		cout << "-";
	}
	string retStr;
	while(M) {
		int rem = M % N; //余数
		if(rem >= 10) {
			retStr.push_back(s[rem - 10]);
		}
		else {
			retStr.push_back(rem + '0');
		}
		M /= N; //更新M，继续求余
	}
	//结果应反转
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
	int sub_len = 0; //目标子串的长度
	int sub_index = 0; //目标子串的起始下标
	int tmp_len = 0; //临时子串的长度
	int tmp_index = 0; //临时子串的起始下标
	for (int i = 0; i < n; i++) {
		while (i < n && (s[i] >= '0' && s[i] <= '9')) {
			tmp_len++;
			if (tmp_len == 1) {
				tmp_index = i;
			}
			i++;
		}
		if (sub_len < tmp_len) {
			// 更新信息
			sub_len = tmp_len;
			sub_index = tmp_index;
		}
		// 更新临时子串的长度
		tmp_len = 0;
	}
	//截取目标子串
	string sub_string = s.substr(sub_index, sub_len);
	cout << sub_string << endl;
	return 0;
}
#endif


#if 0 
//排序子序列
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

	int start , end = 0; //记录每个单词的起始位置
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
//删除s1中所有在s2中出现的字符，返回删除后的字符串
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
//牛牛编程赛
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
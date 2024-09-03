#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];
	fgets(s,300,stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}

int myStrlen (char s[]) {
	int i = 0;
	while (true) {
		if(s[i] == '\0')
		return i;
		i++;
	}
}
int myStrcmp(char s1[], char s2[]) {
	if (s1[myStrlen(s1)-1] == '\n') s1[myStrlen(s1)-1] = '\0';
	int n = myStrlen(s1);
	int m = myStrlen(s2);
	int min = n < m ? n : m;
	for (int i = 0; i < min; i++) {
	if (s1[i] > s2[i])
	return 1;
	else if (s1[i] < s2[i])
	return -1;
	}
	if (n > m)
	return 1;
	else if (n < m)
	return -1;
	return 0;
}
void myStrcpy(char s1[], char s[]) {
	int n = myStrlen(s);
	for (int i = 0; i < n; i++)
	s1[i] = s[i];
	s1[n] = '\0';
}
void connect (char s1[], char s2[]) {
	int n = myStrlen(s1);
	int m = myStrlen(s2);
	for (int i = n; i < n + m; i++)
	s1[i] = s2[i - n];
	s1[n+m] = '\0';
}
void hoanvi(char &x, char &y) {
	int temp = x;
	x = y;
	y = temp;
}
void StringReverse(char st[]) {
	int n = myStrlen(st);
	for (int i = 0; i < n/2; i++) {
		hoanvi(st[i], st[n - i - 1]);
	}
	char s1[100];
	char s2[100] = "";
	myStrcpy(s1,st);
	for (int i = n-1; i >=0; i--) {
		if (s1[i] == ' ') {
			connect(s2, s1 + i + 1);
			connect(s2, " ");
			s1[i] = '\0';
		}
	}
    connect(s2, s1);
	for (int i = 0; i < n; i++ )
	st[i] = s2[i];	
}

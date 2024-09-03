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

int myStrlen(char s[], int k)
{
    int i=0, cnt=0;
    while (s[i]!='\0') cnt++, i++;
    return cnt;
}

int myStrcmp(char s1[MAX], char s2[MAX])
{
    if (myStrlen(s1, MAX)==0 || s1[0]=='\n') return 0;
    return 1;
}
void myStrcpy(char s1[], char s[]) {
	int n = myStrlen(s,MAX);
	for (int i = 0; i < n; i++)
	s1[i] = s[i];
	s1[n] = '\0';
}
void connect (char s1[], char s2[]) {
	int n = myStrlen(s1, MAX);
	int m = myStrlen(s2, MAX);
	for (int i = n; i < n + m; i++)
	s1[i] = s2[i - n];
	s1[n+m] = '\0';
}
void StringReverse(char st[]) {
	int n = myStrlen(st, MAX);
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

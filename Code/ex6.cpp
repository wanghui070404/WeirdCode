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

int myStrlen (char s[], int k) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int myStrcmp(char s1[], char s2[]) {
	int n = myStrlen(s1,0);
	int m = myStrlen(s2,0);
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
void StringReverse(char s[])
{
    int i=0, n=myStrlen(s, MAX);

   while (i<n)
   {
        int j=0; char str[MAX]="";
        while(s[i]==' ' && i<n) i++;
        while (s[i]!=' ' && i<n-1)
        {
            str[j]=s[i];
            s[i]=' ';
            i++;
            j++;
        }

        if (str[0]!='\0')
        {
           int m=myStrlen(str, MAX);
           for (int k=i-1; k>=i-m; k--)
                s[k]=str[i-k-1];
        }
        i++;
   }    
}

// void StringReverse(char st[]) {
//	int n = myStrlen(st);
//	char s1[100];
//	char s2[100] = "";
//	myStrcpy(s1,st);
//	for (int i = n-1; i >=0; i--) {
//		if (s1[i] == ' ') {
//			connect(s2, s1 + i + 1);
//			connect(s2, " ");
//			s1[i] = '\0';
//		}
//	}
//   connect(s2, s1);
//	for (int i = 0; i < n; i++ )
//	st[i] = s2[i];	
//}

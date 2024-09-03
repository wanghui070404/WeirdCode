#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
	char s[MAX], s1[MAX];
	fgets(s,300,stdin);
	fgets(s1,300,stdin);
	int k;
	cin >> k;
	if (k < 0 || k>myStrlen(s, 0))
		cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
	else
	{

ChenChuoiTaiVitriK(s, s1, k);
			puts(s);
    }
}
int myStrlen(char s[], int k)
{
    if (s[0]=='\n') return 0;
    
    int n=0;
    for (int i=0; i<=MAX; i++) {
        if (s[i]=='\n' || s[i]=='\0') 
		break;
        n++;
    }
    
    return n;
}
void Them(char s[], int vt, char kt) {
	for (int i = myStrlen(s,MAX) - 1; i >= vt; i--) 
	s[i+1] = s[i];
	s[vt] = kt;
	s[myStrlen(s,MAX) + 1] = '\0';
	} 

void ChenChuoiTaiVitriK(char s[], char s1[], int k) {
	int n = myStrlen(s1,MAX);
	for (int i = n-1; i >= 0; i--) {
		Them(s, k, s1[i]);
	}
}

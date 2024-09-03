#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

void DemTieng(char s1[]);
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void myMemmove(char s[], int vt, int k);
int myStrstr(char s[], char s1[]);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s[MAX];
	fgets(s,300,stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemTieng(s);
	return 0;
}


int myStrlen(char s[], int k)
{
    if (s[0]=='\n') s[0]='\0';
    for (int i=0; i<= MAX; i++)
    {
        if (s[i]=='\n')
        {
            s[i]='\0';
            break;
        }
    }
    
    int count = 0;
    while (s[count] != '\0')
    count++;
    return count;
}

int myStrcmp(char s1[MAX], char s2[MAX])
{

    if (myStrlen(s1, MAX)==0 ) return 0;

    bool check=true;
    for (int i=0; i<myStrlen(s1, MAX); i++)
    {
        if (s1[i]!=' ')
        {
            check=false;
            break;
        }
    }
    if (check) return 0;

    return 1;
}

void DemTieng(char s[])
{
    int n=myStrlen(s, MAX); 
	    s[n]='\0';
    int i=0;
    while (i<n)
    {
        int j=0; 
		char str[MAX]="";
        while(s[i]==' ' && i<n) i++;
        while (s[i]!=' ' && i<n)
        {
            str[j]=s[i];
            s[i]=' ';
            i++;
            j++;
        }
        int m=myStrlen(str,MAX);
        if (m>0)
        {
            int count=1, k=i+1;  
            while (k<n)
            {
                if (str[0]==s[k])
                {
                    bool check=true;

                    for (int h=1; h<m; h++)
                    {
                        if (str[h]!=s[k+h])
                        {
                            check=false;
                            break;
                        }
                    }

                    if (check)
                    {
                        for (int h=k; h<k+m; h++) s[h]=' ';
                        count++;
                    }
                }

                k++;
            }
            cout<<str<<": "<<count<< endl << endl;
        }
        i++;
    } 
}


int equivalent(char s1[], char s2[]) {
//	if (s1[myStrlen(s1)-1] == '\n') s1[myStrlen(s1)-1] = '\0';
	int n = myStrlen(s1, MAX);
	int m = myStrlen(s2, MAX);
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
	int n = myStrlen(s, MAX);
	for (int i = 0; i < n; i++)
	s1[i] = s[i];
	s1[n] = '\0';
}

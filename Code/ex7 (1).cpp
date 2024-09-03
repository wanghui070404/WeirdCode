int myStrlen(char s[], int k)
{
    if (s[0]=='\n') return 0;
    
    int cnt=0;
    for (int i=0; i<=MAX; i++)
    {
        if (s[i]=='\n' || s[i]=='\0') break;
        cnt++;
    }
    
    return cnt;
}

int myStrcmp(char s1[MAX], char s2[MAX])
{

    if (myStrlen(s1, MAX)==0 ) return 0;
    return 1;
}

void StringReverse(char s[])
{
    int n = myStrlen(s, MAX);
 
    char ans[MAX]; 

    for (int i=0; i<n; i++) ans[i]=s[n-i-1];
    ans[n]='\0';
    
    int i=0;
    while (i<n)
    {
        int j=0; char str[MAX]="";
        while(ans[i]==' ' && i<n) i++;
        while (ans[i]!=' ' && i<n)
        {
            str[j]=ans[i];
            ans[i]=' ';
            i++;
            j++;
        }
        // str[myStrlen(str,0)]='\0';
        // cout<<str[0]<<endl;
        if (str[0]!='\0')
        {
           int m=myStrlen(str, MAX);
           for (int k=i-1; k>=i-m; k--)
                ans[k]=str[i-k-1];
        }
        i++;
    }

    int na=myStrlen(ans, MAX);
    // cout<<na<<endl;
    for (int i=0; i<=na; i++) s[i]=ans[i];
}
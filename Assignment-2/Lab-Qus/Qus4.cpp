#include<iostream>
#include<cstring>

using namespace std;

void Concatentate(char arr[],char brr[],int l1,int l2)
{
    char crr[l1+l2+1];
    int i=0;

    while(arr[i]!='\0')
    {
        crr[i]=arr[i];
         i++;
    }

    int j=0;
    while(brr[j]!='\0')
    {
        crr[i]=brr[j];
        i++;
        j++;
    } 

    crr[i]='\0';

    cout<<crr<<endl;
    

    
    
}

int getLength(char arr[])
{
    int count=0;
    int i=0;

    while(arr[i]!='\0')
    {
        count++;
        i++;
    }

    return count;

}

void Reverse(char *arr,int i,int j)
{
    if(i>j)
    {
        return;

    }

   else{
    swap(arr[i],arr[j]);
    i++;
    j--;

   } 
    Reverse(arr,i,j);
}

void vowel(char brr[])
{
   int len = getLength(brr);
    char result[len + 1]; 
    int k = 0;

    for (int i = 0; i < len; i++) {
        char ch = brr[i];
        if (!(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||
              ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U')) {
            result[k++] = ch;
        }
    }
    result[k] = '\0';
    cout << "String after removing vowels: " << result << endl;
}

void SortStrings(char arr[][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) { 
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

void Lowercase(char &ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + ('a' - 'A');
    }
}

int main ()
{

    char arr[]="Ayush";
    char brr[]="Jindal";

    int l1=getLength(arr);
    int l2=getLength(brr);

    Concatentate(arr,brr,l1,l2);

    int i=0,j=l1-1;

    Reverse(arr,i,j);


    cout<<"Reversed string is "<<endl<<arr<<endl;

    vowel(brr);
    


    char strings[3][50] = {"Banana", "Apple", "Mango"};
    SortStrings(strings, 3);

     char ch = 'A';
    Lowercase(ch);
    cout << "Lowercase of A: " << ch << endl;


}

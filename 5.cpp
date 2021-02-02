
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    char s1[10], s2[10];
    cout << "Digite una palabra: ñ ";
    cin >> s2;
    //***********************
    cout << "La longitud de s2 es: " << strlen(s2) << endl;
    //***********************
    strcpy(s1, s2);
    cout << "s1 es: " << s1 << endl;
    //***********************
    strncpy(s1, "abcdef", 3);
    cout << "s1 es: " << s1 << endl;
    //***********************
    cout << "Digite una palabra para s1: ";
    cin >> s1;
    cout << "Digite una palabra para s2: ";
    cin >> s2;
    strcat(s1, s2);
    cout << "s1 es: " << s1 << endl;
    return 0;
}

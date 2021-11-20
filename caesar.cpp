#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char msg[100];
    cout << "Input the message you want to encode";
    cin.getline(msg);
    // char ch;

    // for (int i = 0; msg[i] != '\0'; ++i)
    // {

    //     ch = msg[i];
    //     if (ch >= 'a' && ch <= 'z')
    //     {
    //         ch = ch + key;
    //         if (ch > 'z')
    //         {
    //             ch = ch - 'z' + 'a' - 1;
    //         }
    //         msg[i] = ch;
    //     }

    //     else if (ch >= 'A' && ch <= 'Z')
    //     {
    //         ch = ch + key;
    //         if (ch > 'Z')
    //         {
    //             ch = ch - 'Z' + 'A' - 1;
    //         }
    //         msg[i] = ch;
    //     }
    // }
    // printf("Encrypted message: %s", msg);

    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;


string create_keyword(string key, int len)
{

    char keyword[100];
    int j=0;
    for(int i=0; i < len; i++){
        
        if(j == key.size())
            j = 0;
        
        keyword[i] = key[j];

        j = j + 1; 
    }
    return string(keyword);
 }


 string uppercase(string str)
 {
    for (int i = 0; i<str.size(); i++)
    {
        str[i] = toupper(str[i]);
     }

    return str;

 }



string cipher(string msg, string keyword)
{
    char encrypted_msg[msg.size()];


    for (int i = 0; i<msg.size(); i++)
    {
        msg[i] = toupper(msg[i]);
        keyword[i] = toupper(keyword[i]);
     }

    for (int i = 0; i<msg.size(); i++)
    {
        cout << "m: " << msg[i] << " " << "k: " << keyword[i] << "\n";
        char temp = (msg[i] - 'A' + keyword[i] - 'A') % 26 + 'A';
        encrypted_msg[i] = char(temp);
    }

    return string(encrypted_msg);
}




string decipher(string msg, string keyword)
{
    char encrypted_msg[msg.size()];


    for (int i = 0; i<msg.size(); i++)
    {
        msg[i] = toupper(msg[i]);
        keyword[i] = toupper(keyword[i]);
     }

    for (int i = 0; i<msg.size(); i++)
    {
        char temp = (msg[i] - 'A' - (keyword[i] - 'A') + 26) % 26 + 'A';
        encrypted_msg[i] = char(temp);
    }

    return string(encrypted_msg);
}
int main()
{
    string msg;
    string key;
    cout << "Input the message you want to encode";
    cin >> msg;

    cout << "Input the key you want to encode with:";
    cin >> key;

    string keyword = create_keyword(key, msg.size() );
    
    string encrypted_msg = cipher(msg, keyword);
    cout << encrypted_msg;

    cout << "Deciphered: ";
    cout << decipher(encrypted_msg, keyword);
    return 0;
}
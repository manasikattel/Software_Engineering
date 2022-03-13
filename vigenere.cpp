#include <iostream>


/**
 * Create the keyword for a given key and length of message for Vignere cipher. 
 * For example: If the key passed is "HELLO" and the length of the message is 11,
 * the keyword returned will be "HELLOHELL0H"
 *
 * @param[in] key Key to use for encryption 
 * @param[in] len Length of the message 
 * @return Keyword in the length of input message.
 */
std::string create_keyword(std::string key, int len)    
{
    char keyword[len];
    int j=0;
    for(int i=0; i < len; i++){
        if(j == key.size())
            j = 0;
        keyword[i] = key[j];
        j = j + 1; 
    }
    return std::string(keyword);
 }




/**
 * Convert a string to Uppercase.  

 *
 * @param[in] str String to convert to uppercase. 
 * @return The string converted to uppercase.
 */
 std::string uppercase(std::string str)
 {
    for (int i = 0; i<str.size(); i++)
        str[i] = toupper(str[i]);
    return str;
 }


/**
 * Encrypt the given message with the given keyword 
 * using Vignere cipher.  

 *
 * @param[in] msg Message to be encrypted. 
 * @param[in] keyword Keyword to be used to encrypt. 

 * @return The encrypted message.
 */
std::string cipher(std::string msg, std::string keyword)
{
    char encrypted_msg[msg.size()];
    for (int i = 0; i<msg.size(); i++)
        keyword[i] = toupper(keyword[i]);

    for (int i = 0; i<msg.size(); i++)
    {
      char letter = msg[i];
    if (letter == ' ')
         encrypted_msg[i] = ' ';
    else{
      if (letter >= 'a' and letter <= 'z')
         letter += 'A' - 'a';
      else if (letter < 'A' or letter > 'Z')
         continue;

      char temp = (letter - 'A' + keyword[i] - 'A') % 26 + 'A';

      if (msg[i] >= 'a' and msg[i] <= 'z')
            temp = (char)tolower(temp);
      encrypted_msg[i] = char(temp);
    }
    }
    return std::string(encrypted_msg);
}




/**
 * Decrypt the given message with the given keyword 
 * using Vignere cipher.  

 *
 * @param[in] msg Message to be decrypted. 
 * @param[in] keyword Keyword to be used to decrypt. 

 * @return The decrypted message.
 */
std::string decipher(std::string msg, std::string keyword)
{
    char decrypted_msg[msg.size()];

    for (int i = 0; i<msg.size(); i++)
        keyword[i] = toupper(keyword[i]);

    for (int i = 0; i<msg.size(); i++)
    {
        char letter = msg[i];

    if(letter == ' ')
         decrypted_msg[i] = ' ';
    else{
        if (letter >= 'a' and letter <= 'z')
            letter += 'A' - 'a';
        else if (letter < 'A' or letter > 'Z')
            continue;

        char temp = (letter - 'A' - (keyword[i] - 'A') + 26) % 26 + 'A';
        
        if (msg[i] >= 'a' and msg[i] <= 'z')
            temp = (char)tolower(temp);
        decrypted_msg[i] = char(temp);
    }
    }
    return std::string(decrypted_msg);
}


int main()
{
    std::string msg;
    std::string key;
    std::cout << "Input the message you want to encode: \n";
    getline(std::cin, msg);

    std::cout << "Input the key you want to encode with: \n";
    std::cin >> key;

    std::string keyword = create_keyword(key, msg.size() );    
    std::string encrypted_msg = cipher(msg, keyword);
    std::cout << "Encrypted message: "<<encrypted_msg << "\n";

    std::cout << "Deciphered: ";
    std::cout << decipher(encrypted_msg, keyword);

    return 0;
}
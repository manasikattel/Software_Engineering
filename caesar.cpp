#include <iostream>
#include <algorithm>
#include <cstring>




/**

 * Generates Sentence Encryption based on Caesar cipher.
 * @param[in] sentence String that corresponds to the sentence to be encrypted.
 * @param[in] key corresponding to the shift to be applied for the encryption.
 @return encrypted sentence.

*/

std::string Sentence_Encryption(std::string sentence, int key)

{
    char base[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string final_sentence;
    char sentence_char[sentence.length()+1];
    char sentence_result_char[sentence.length()+1];
    strcpy(sentence_char,sentence.c_str());
    for (int i=0; i<sentence.length();i++)
        for (int j=0; j< sizeof(base)/sizeof(base[0]); j++)
    {
        {
            if(sentence_char[i] == ' ')
            {
                sentence_result_char[i]= ' ';
            }
            else if (sentence_char[i] == base[j] || sentence_char[i] == (char)tolower(base[j]))
            {
               int caesar_index= (j+key)%26;
               if (caesar_index > 25)
               {
                   caesar_index= caesar_index-26;
               }
               if(islower(sentence_char[i]))
               {
                   sentence_result_char[i]= (char)tolower(base[caesar_index]);
               }
               else{
                    sentence_result_char[i] = base[caesar_index];

               }
            }

        }
    }
    for (int i = 0; i < sentence.length(); i++)
    {
        final_sentence = final_sentence + sentence_result_char[i];
    }

    return final_sentence;

}

/**

 * Generates Sentence Decryption based on Caesar cipher.
 * @param[in] sentence String that corresponds to the sentence to be decrypted.
 * @param[in] key corresponding to the shift to be applied for the decryption.
 @return decrypted sentence.

*/
std::string Sentence_Decryption(std::string sentence, int key)
{
    char base[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string final_sentence;
    char sentence_char[sentence.length()+1];
    char sentence_result_char[sentence.length()+1];
    strcpy(sentence_char,sentence.c_str());
    for (int i=0; i<sentence.length();i++)
        for (int j=0; j< sizeof(base)/sizeof(base[0]); j++)
    {
        {
            if(sentence_char[i] == ' ')
            {
                sentence_result_char[i]= ' ';
            }
           else if (sentence_char[i] == base[j] || sentence_char[i] == (char)tolower(base[j]))
           {
               int caesar_index= (j-key)%26;
               if(caesar_index<0)
               {
                   caesar_index= caesar_index+26;
               }
               if(islower(sentence_char[i]))
               {
                   sentence_result_char[i]= (char)tolower(base[caesar_index]);
               }
               else{
                    sentence_result_char[i] = base[caesar_index];

               }
           }
        }
    }
    for (int i = 0; i < sentence.length(); i++)
    {
        final_sentence = final_sentence + sentence_result_char[i];
    }

    return final_sentence;

}

int main()
{

    std::string example_sentence;
    std:: cout << "Enter the message that you want to encode:"<<std::endl;
    getline(std::cin,example_sentence);
    std::string result= Sentence_Encryption(example_sentence, 23);
    std::string result_decrypted= Sentence_Decryption(result,23);
    std::cout<<"Original Sentence"<<std::endl;
    std::cout << example_sentence<<std::endl;
    std::cout<<"Encrypted Sentence"<<std::endl;
    std::cout <<result<<std::endl;
    std::cout<<"Decrypted Sentence"<<std::endl;
    std::cout << result_decrypted<<std::endl;

    return 0;
}

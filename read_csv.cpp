#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <regex>




int main()
{

    std::ifstream fin;
    fin.open("titanic.csv");
    std::string line;

    while(!fin.fail()){
        getline(fin, line);
        std::cout<<line<< std::endl;
        
    }


    return 0;

}

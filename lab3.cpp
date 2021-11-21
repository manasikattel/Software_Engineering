
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
struct info {
    int Survived;
    int Pclass;
    string Name;
    string sex;
    int Age;
    int SSAboard;
    int PCAboard;
    float fare;
};

int main(){

  ifstream ip("titanic.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string Survived;
    string Pclass;
    string Name;
    string sex;
    string Age;
    string SSAboard;
    string PCAboard;
    string fare;

  vector <info> passenger;

  while(ip.good()){

    getline(ip,Survived,',');
    getline(ip,Pclass,',');
    getline(ip,Name,',');
    getline(ip,sex,',');
    getline(ip,Age,',');
    getline(ip,SSAboard,',');
    getline(ip,PCAboard,',');
    getline(ip,fare,'\n');

    info temp;
    temp.Survived = stoi(Survived);
    temp.Pclass = stoi(Pclass);
    temp.Name = Name;
    temp.sex = sex;
    temp.Age = stoi(Age);
    temp.SSAboard = stoi(SSAboard);
    temp.PCAboard = stoi(PCAboard);
    temp.fare = stof(fare);

    passenger.push_back(temp);
  }


  ip.close();

  for (int i=0; i<passenger.size(); ++i)
    {
        std::cout << passenger[i].Survived<< ' ';
        std::cout << passenger[i].Pclass << ' '; 
        std::cout << passenger[i].Name << ' '; 
        std::cout << passenger[i].sex << ' '; 
        std::cout << passenger[i].Age << ' '; 
        std::cout << passenger[i].SSAboard << ' '; 
        std::cout << passenger[i].PCAboard << ' '; 
        std::cout << passenger[i].fare << ' '; 
        std::cout << "\n";

    }

}

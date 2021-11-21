#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>

using namespace std;
struct info {
    int Survived;
    int Pclass;
    string Name;
    string sex;
    float Age;
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
    temp.Age = stof(Age);
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


  int survive_f_class1 = 0;
  int survive_f_class2 = 0;
  int survive_f_class3 = 0;
  int survive_m_class1 = 0;
  int survive_m_class2 = 0;
  int survive_m_class3 = 0;
  int survive_child_class3 = 0;

  int f_class1 = 0; 
  int f_class2 = 0; 
  int f_class3 = 0; 
  int m_class1 = 0; 
  int m_class2 = 0; 
  int m_class3 = 0; 
  int child_class3 = 0; 

  float class1_fare_sum = 0;
  float class2_fare_sum = 0;
  float class3_fare_sum = 0;
  float total_fare = 0;

  int c1_count = 0;
  int c2_count = 0;
  int c3_count = 0;


  for (int i=0; i<passenger.size(); ++i)
    {
        if ((passenger[i].sex == "female") && (passenger[i].Pclass == 1) && (passenger[i].Survived == 1))
            survive_f_class1 += 1;
        if ((passenger[i].sex == "female") && (passenger[i].Pclass == 2) && (passenger[i].Survived == 1))
            survive_f_class2 += 1;
        if ((passenger[i].sex == "female") && (passenger[i].Pclass == 3) && (passenger[i].Survived == 1))
            survive_f_class3 += 1;

        if ((passenger[i].sex == "male") && (passenger[i].Pclass == 1) && (passenger[i].Survived == 1))
            survive_m_class1 += 1;
        if ((passenger[i].sex == "male") && (passenger[i].Pclass == 2) && (passenger[i].Survived == 1))
            survive_m_class2 += 1;
        if ((passenger[i].sex == "male") && (passenger[i].Pclass == 3) && (passenger[i].Survived == 1))
            survive_m_class3 += 1;

        if ((passenger[i].Age <= 10) && (passenger[i].Pclass == 3) && (passenger[i].Survived == 1))
            survive_child_class3 += 1;




        if ((passenger[i].sex == "female") && (passenger[i].Pclass == 1))
            f_class1 += 1;
        if ((passenger[i].sex == "female") && (passenger[i].Pclass == 2))
            f_class2 += 1;
        if ((passenger[i].sex == "female") && (passenger[i].Pclass == 3))
            f_class3 += 1;

        if ((passenger[i].sex == "male") && (passenger[i].Pclass == 1))
            m_class1 += 1;
        if ((passenger[i].sex == "male") && (passenger[i].Pclass == 2))
            m_class2 += 1;
        if ((passenger[i].sex == "male") && (passenger[i].Pclass == 3))
            m_class3 += 1;

        if ((passenger[i].Age <= 10) && (passenger[i].Pclass == 3))
            child_class3 += 1;

        if (passenger[i].Pclass == 1)
        {
            class1_fare_sum += passenger[i].fare;
            c1_count +=1;
        }
        if (passenger[i].Pclass == 2)
        {
            class2_fare_sum += passenger[i].fare;
            c2_count +=1;

        }
        if (passenger[i].Pclass == 3)
        {
            class3_fare_sum += passenger[i].fare;
            c3_count +=1;

        }

        total_fare += passenger[i].fare;
    
    }



    float p_f_1 = float(survive_f_class1) / float(f_class1);
    float p_f_2 = float(survive_f_class2) / float(f_class2);
    float p_f_3 = float(survive_f_class3) / float(f_class3);
    
    float p_m_1 = float(survive_m_class1) / float(m_class1);
    float p_m_2 = float(survive_m_class2) / float(m_class2);
    float p_m_3 = float(survive_m_class3) / float(m_class3);


    float p_c_3 = float(survive_child_class3) / float(child_class3);

    float expectation_c1  = float(class1_fare_sum)/float(c1_count);
    float expectation_c2  = float(class2_fare_sum)/float(c2_count);
    float expectation_c3  = float(class3_fare_sum)/float(c3_count);


    cout << "P(S=true | G=female,C=1) = " << p_f_1 << "\n";
    cout << "P(S=true | G=female,C=2) = " <<  p_f_2 << "\n";
    cout << "P(S=true | G=female,C=3) = " << p_f_3 << "\n";
    
    cout << "P(S=true | G=male,C=1) = " << p_m_1 << "\n";
    cout << "P(S=true | G=male,C=2) = " << p_m_2 << "\n";
    cout << "P(S=true | G=male,C=3) = " << p_m_3 << "\n";
    
    cout << "P(S=true | Age <= 10,C=3) = " << p_c_3 << "\n";

    cout << "E(X | C=1) = " << expectation_c1 << "\n";
    cout << "E(X | C=2) = " << expectation_c2 << "\n";
    cout << "E(X | C=3) = " << expectation_c3 << "\n";
}

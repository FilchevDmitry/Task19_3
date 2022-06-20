#include <iostream>
#include<fstream>
#include<string>
#include<sstream>

int main()
{
    std::ifstream pay;
    std::string name;
    int sum=0;
    int max = 0;
    pay.open("Payments.txt");
    if (pay.is_open())
    {
        while (!pay.eof())
        {
            std::string text;
            std::getline(pay, text);
            std::stringstream temp(text);
            std::string f_name;
            std::string l_name;
            int payments = 0;
            temp >> f_name >> l_name >> payments;
            sum += payments;
            if (max < payments)
            {
                max = payments;
                name = f_name+" "+l_name;
            }
        }
    }
    else
    {
        std::cout << "NO";
    }
    std::cout <<"Total amount of funds paid = " << sum << std::endl;
    std::cout <<"The person with the maximum payout amount " << name << " " << max << std::endl;
    pay.close();
}


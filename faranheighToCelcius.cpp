#include <iostream>
using namespace std;

class convTemp
{
private:
    float faranTemp;
    float celciusTemp;

public:
    void getTemp(void);
    float conTemp(void);
};

void convTemp::getTemp(void)
{
    cout << "Enter temprature in fahrenheit" << endl;
    cin >> faranTemp;
}
float convTemp::conTemp(void)
{
    return celciusTemp = (faranTemp - 32) / 1.8;
}
int main()
{
    convTemp obj1;
    obj1.getTemp();
    float get = obj1.conTemp();
    cout << "Temprature in celcius is :" << get << endl;

    return 0;
}

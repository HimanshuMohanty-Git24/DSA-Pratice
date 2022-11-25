#include <iostream>
using namespace std;
class MILES_8102;
class KM_8102
{
public:
    float data_8102;
    static int count1;

public:
    KM_8102()
    {
        cout << "\nEnter the distance" << count1 << "(KM):";
        cin >> data_8102;
        count1++;
    }
    float operator=(MILES_8102 m);
    void display()
    {
        cout << "\nThe distance is:" << data_8102 << " KM\n";
    }
};
class MILES_8102
{
public:
    float data_8102;
    static int count2;

public:
    MILES_8102()
    {
        cout << "\nEnter the distance" << count2 << "(MILES):";
        cin >> data_8102;
        count2++;
    }
    float operator=(KM_8102 k);
    void display()
    {
        cout << "\nThe distance is:" << data_8102 << " MILES\n";
    }
};
float KM_8102::operator=(MILES_8102 m)
{
    return data_8102 = m.data_8102 * 1.609;
}
float MILES_8102::operator=(KM_8102 k)
{
    return data_8102 = k.data_8102 * 0.6213712;
}
int KM_8102::count1 = 1;
int MILES_8102::count2 = 1;
int main()
{
    cout << "\nSumit Kumar Samal...2128102\n";
    KM_8102 k1, k2;
    MILES_8102 m1, m2;
    k1.display();
    k2.display();
    m1.display();
    m2.display();
    k1 = m1;
    m2 = k2;
    cout << "\nConversion of m1 to k1\n";
    k1.display();
    cout << "\nConversion of k2 to m2\n";
    m2.display();
}

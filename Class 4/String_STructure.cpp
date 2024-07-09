#include <bits/stdc++.h>
using namespace std;


struct Students
{
    string name;
    string ID;
    float Cgpa;
};

int main()
{
    struct Students s1;

    s1.name = "Molla Omar";
    s1.ID = "0112310485";
    s1.Cgpa = 3.21;

    printf("Name: %s\n", s1.name.c_str());
    printf("ID: %s\n", s1.ID.c_str());
    printf("Cgpa: %.2f\n", s1.Cgpa);

    return 0;
}

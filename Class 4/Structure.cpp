#include <stdio.h>
#include<string.h>

struct Students
{
    char name[20];
    char ID[20];
    float Cgpa;
};

int main()
{
    struct Students s1;


    strcpy(s1.name, "Molla Omar");
    strcpy(s1.ID, "0112310485");
    s1.Cgpa = 3.21;


    printf("Name: %s\n", s1.name);
    printf("ID: %s\n", s1.ID);
    printf("Cgpa: %.2f\n", s1.Cgpa);



}

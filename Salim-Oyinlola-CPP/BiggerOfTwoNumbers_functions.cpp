#include <iostream>

using namespace std;

// Declaring functions
void AskForTwoNumbers(int*, int*); // Using pointers to declare variable
int FindBigOne(int, int); 
int main()
{
    int f_num, s_num, bigger_num;
    AskForTwoNumbers(&f_num, &s_num);
    bigger_num = FindBigOne(f_num, s_num);
    cout << "The bigger number is: " << bigger_num;
    return 0;
}

//The function that asks for the two numbers to be comapred from the User
void AskForTwoNumbers(int *num1, int *num2)
{
    int f_num, s_num;
    cout << "Enter the first number: " << endl; 
    cin >> f_num;
    cout << "Enter the second number: " << endl;
    cin >> s_num;

    *num1 = f_num;
    *num2 = s_num;
}

// The function that returns the bigger number using comparators
int FindBigOne(int x, int y)
{
    int a, b;
    if(a > b)
        return a;
    else if(b > a)
        return b;
    else
        return a;
}

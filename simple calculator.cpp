#include<iostream>
using namespace std;
int main()
{
    int ch,a,b;
    cout<<"\nWelcome to My calculator";
    while(1)
    {
        cout<<"\n1.Addition.\n2.Subtraction.\n3.Multiplication.\n4.Division.\n5.Exit.\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter the number for addition: ";
            cin>>a>>b;
            cout<<"Addition is : "<<a+b;
        }
        else if(ch==2)
        {
            cout<<"Enter the number for subtraction.(a>b): ";
            cin>>a>>b;
            cout<<"Subtraction is : "<<a-b;
        }
        else if(ch==3)
        {
            cout<<"Enter the number for Multiplication: ";
            cin>>a>>b;
            cout<<"Multiplication is : "<<a*b;
        }
        else if(ch==4)
        {
            cout<<"Enter the number for Division (a>b): ";
            cin>>a>>b;
            cout<<"Division is : "<<a/b;
        }
        else if(ch==5)
        {
            cout<<"Thank You";
            break;
        }
        else
        {
            cout<<"Enter valid choice.";
        }
    }
}

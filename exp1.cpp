#include<iostream>
using namespace std;

class  student{
    private: 
        int roll_no;
        string name;
        float marks;

    public:
        void input(){
            cout<<"Enter Your Name:";
            getline(cin,name);
            cout<<"Enter Your Roll Number:";
            cin>>roll_no;
            cout<<"Enter Your Marks:";
            cin>>marks;
        }

        void display(){
            cout<<"Roll Number:"<<roll_no<<endl;
            cout<<"Name:"<<name<<endl;
            cout<<"Marks:"<<marks<<endl;
        }
};

int main(){
    student s;
    s.input();
    s.display();
    return 0;
}
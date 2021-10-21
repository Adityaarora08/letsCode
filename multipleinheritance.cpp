#include<iostream>
using namespace std;
class Teacher
{
	public:
	int a;
	string n,s,p;
	get1()
	{
		cout<<"\n Enter the teacher code: ";
		cin>>a;
		cout<<"\n Enter the teacher name: ";
		cin>>n;
		cout<<"\n Enter the teacher subject: ";
		cin>>s;
		cout<<"\n Enter the teacher publication: ";
		cin>>p;
	}

};
class Office
{
	public:
	int c,g;
	string i;
	get2()
	{
		cout<<"\n Enter the office code: ";
		cin>>c;
		cout<<"\n Enter the office name: ";
		cin>>i;
		cout<<"\n Enter the office grade: ";
		cin>>g;	
	}

};
class Typist:public Teacher,public Office
{
	public:
	int code,sp,dw;
	string l;
get()
{
		cout<<"\n Enter the typist code: ";
		cin>>code;
		cout<<"\n Enter the typist name: ";
		cin>>l;
		cout<<"\n Enter the speed : ";
		cin>>sp;
		cout<<"\n Enter the daily wages : ";
		cin>>dw;
}
show()
	{
		cout<<"\n  the teacher code: "<<a;
		cout<<"\n  the teacher name: "<<n;
		cout<<"\n  the teacher subject: "<<s;
		cout<<"\n  the teacher publication: "<<p;
	
		cout<<"\n  the office code: "<<c;
		cout<<"\n  the office name: "<<i;
		cout<<"\n  the office grade: "<<g;
			
		cout<<"\n  the typist code: "<<code;
		cout<<"\n  the typist name: "<<l;
		cout<<"\n  the speed : "<<sp;
		cout<<"\n  the daily wages : "<<dw;
	}
};
int main()
{
	Typist obj;
	obj.get1();
	obj.get2();
	obj.get();
	obj.show();
	return 0;
}

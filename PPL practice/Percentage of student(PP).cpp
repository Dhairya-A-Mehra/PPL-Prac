#include<iostream>
using namespace std;

class student
{
	public:
		float phy;
		float chem;
		float math;
		string name;
		
		void getdata()
		{
			cout << "Enter the name of the student: ";
       	 	cin >> name;
			cout<<"Enter the marks of Physics: ";
			cin>>phy;
			cout<<"\nEnter the marks of Chemistry: ";
			cin>>chem;
			cout<<"\nEnter the marks of Mathematics: ";
			cin>>math;
		}
		
		int percentage()
		{
			float total= phy + chem + math;
			return (total/3.0f);	
		}
};

int main()
{
	student std1;
	std1.getdata();
	float percent = std1.percentage();
	cout<<"Student Name: "<<std1.name<<endl;
	cout<<"Percentage: "<<percent<<"%"<<endl;
	return 0;	
}

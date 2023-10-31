#include<iostream>
using namespace std;

class rectangle
{
	public:
		float l;
		float b;
		
		void setDim()
		{
			cout<<"Enter the lenght of rectange: ";
			cin>>l;
			cout<<"\nEnter the breadth of rectangle: ";
			cin>>b;
		}
		
		float getArea()
		{
			float area=l * b;
			return area;
		}
};

int main()
{
	rectangle r;
	r.setDim();
	float a=r.getArea();
	cout<<"Area of rectangle is: "<<a<<" m^2"<<endl;
	return 0;
}

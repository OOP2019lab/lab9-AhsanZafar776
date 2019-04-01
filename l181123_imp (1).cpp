#include"employee.h"
#include<string>

Address::Address(char* hn, char* sn, char * City,char* County)
{  
	house_Number=new char[strlen(hn)];
	strcpy(house_Number,hn);
	street_Name=new char[strlen(sn)];
	strcpy(street_Name,sn);
	city= new char[strlen(City)];
	strcpy(city,City);
	county= new char[strlen(County)];
	strcpy(county,County);
}
Address::Address(const Address & ad)
{
	house_Number=new char[strlen(ad.house_Number)];
	strcpy(house_Number,ad.house_Number);
	street_Name=new char[strlen(ad.street_Name)];
	strcpy(street_Name,ad.street_Name);
	city= new char[strlen(ad.city)];
	strcpy(city,ad.city);
	county= new char[strlen(ad.county)];
	strcpy(county,ad.county);

}
ostream& operator<<(ostream& out, const Address& ad)
{
	out<<ad.house_Number<<","<<ad.street_Name<<","<<ad.city<<","<<ad.county<<endl;
	return out;
}
const Address &   Address::operator=(const Address& other)
{
	delete house_Number;
	delete street_Name;
	delete city;
	delete county;

	house_Number=new char[strlen(other.house_Number)];
	strcpy(house_Number,other.house_Number);
	street_Name=new char[strlen(other.street_Name)];
	strcpy(street_Name,other.street_Name);
	city= new char[strlen(other.city)];
	strcpy(city,other.city);
	county= new char[strlen(other.county)];
	strcpy(county,other.county);
	return *this;

}
Address::~Address()
{
	delete house_Number;
	delete street_Name;
	delete city;
	delete county;
}
Project::Project(char* n, int b, int d)
{
	name=new char[strlen(n)];
	strcpy(name,n);
	budget=b;
	duration=d;
}
Project::Project(const Project& p2)
{
	name=new char[strlen(p2.name)];
	strcpy(name,p2.name);
	budget=p2.budget;
	duration=p2.duration;
  
}
ostream& operator<<(ostream& out, const Project& p2)
{
	out<<p2.name<<","<<p2.budget<<","<<p2.duration<<endl;
	return out;
}
void Project::setBudget(int a)
{
	budget=a;

}
Project::~Project()
{
	delete name;
}
Employee::Employee(char* name, const Address& ad):emp_ad(ad)
{
	emp_name=new char[strlen(name)];
	strcpy(emp_name,name);
	emp_pro= new Project*(nullptr);
}
Employee::Employee(const Employee& e1):emp_ad(e1.emp_ad)
{
	emp_name=new char[strlen(e1.emp_name)];
	strcpy(emp_name,e1.emp_name);
	if(e1.emp_pro==nullptr)
		emp_pro=new Project*(nullptr);
	else
	{
		projects=e1.projects;
		emp_pro=new Project*[projects];
		for(int i =0;i<projects;i++)
			emp_pro[i]=new Project(*e1.emp_pro[i]);

	}
} 

ostream& operator<<(ostream& out, const Employee& e1)
{
	out<<e1.emp_name<<endl;
	out<<e1.emp_ad;
	out<<e1.emp_pro;
	return out;
}
const Employee&  Employee::operator=(const Employee& e1)
{
	emp_ad=e1.emp_ad;
	emp_name=new char[strlen(e1.emp_name)];
	strcpy(emp_name,e1.emp_name);
	if(e1.emp_pro==nullptr)
		emp_pro=new Project*(nullptr);
	else
	{
		projects=e1.projects;
		emp_pro=new Project*[projects];
		for(int i =0;i<projects;i++)
			emp_pro[i]=new Project(*e1.emp_pro[i]);

	}
	
	return *this;
}
void Employee::addProject(Project const *p1 ) 
{
	if(projects<2){
	Project **p2=new Project *[projects];
		for(int i=0;i<projects;i++)
		p2[i]=new Project(*emp_pro[i]);
		for(int i=0;i<projects;i++)
			delete[]emp_pro[i];
		delete []emp_pro;
		projects=projects+1;
		emp_pro=new Project*[projects];
		int i=0;
		for(;i<projects-1;i++)
		emp_pro[i]=new Project(*p2[i]);
		emp_pro[i+1]=new Project (*p1);
		
	}
}
void Employee::removeProject(Project const *p1 ) 
{
	
	Project **p2=new Project *[projects-1];
	int k=0;
		for(int i=0;i<projects;i++){
			if(emp_pro[i]!=p1){
		p2[k]=new Project(*emp_pro[k]);
		k++;}
		}
		projects=projects-1;
		emp_pro=new Project*[projects];
		int i=0;
		for(;i<projects;i++)
		emp_pro[i]=new Project(*p2[i]);
		for( i=0;i<projects;i++)
		delete []p2[i];
		delete[] p2;
}
Employee::~Employee()
{
	if(emp_pro!=nullptr)
	{
	for( int i=0;i<projects;i++)
		delete []emp_pro[i];
	}
	delete emp_pro;

	delete emp_name;
}
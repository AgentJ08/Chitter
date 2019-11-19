#include<bits/stdc++.h>
using namespace std;
#include "assets.cpp"

int adj[1000][1000];
int checklogin = 0;

int follow(int count, int x)
{
	adj[count-1][x-1] = 1;
}

void renderSignup()
{
        cout<<"        SIGNUP!          "<<endl;
	string finame,laname,usname,ubio;
	date biday;
	cout<<"Enter first name: ";
	cin>>finame;
	cout<<"Enter last name: ";
        cin>>laname;
	cout<<"Enter username: ";
        cin>>usname;
	while(!checkunameavail(usname)) {cout<<"Username already taken! Please try again."; cin>>usname;}
	cout<<"Enter your birthday: ";
	cout<<"Date: ";
	cin>>biday.dd;
	cout<<"Month: ";
	cin>>biday.mm;
	cout<<"Year: ";
	cin>>biday.yyyy;
	cout<<"Enter a short bio about you: ";
        cin>>ubio;
	if(signup()) cout<<"Signed up successfully!"<<endl;
	else cout<<"Some error in signup! Please try again later."<<endl;
}

void renderLogin()
{
        cout<<"        LOGIN!          "<<endl;
	string uname;
	string pwd;
	cout<<"Enter username: ";
	cin>>uname;
	cout<<"Enter password: ";
	cin>>pwd;
	if(uname!="" && pwd!="") cout<<"Checking credentials..."<<endl;//checkCredentials(uname, pwd);
	else
	{
		cout<<"Invalid entry! Please try again.";
		renderLogin();
	}
}

void renderWhat()
{
	int wtd;
	cout<<"Press 1 for signup. And 2 to login, if you're already a user: ";
        cin>>wtd;
        if(wtd==1)  renderSignup();
        else if(wtd==2) renderLogin();
        else
	{
		cout<<"Invalid entry. Please try again!"<<endl;
		renderWhat();
	}
}

void renderHomepage()
{
        cout<<"        HOMEPAGE!          "<<endl;
        renderWhat();
}

int main()
{
	renderHomepage();
	return 0;
}

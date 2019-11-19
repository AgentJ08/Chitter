#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int adj[1000][1000];
int login = 0;

int follow(int count, int x)
{
	adj[count-1][x-1] = 1;
}

void renderSignup()
{
        cout<<"        SIGNUP!          "<<endl;

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

#include<bits/stdc++.h>
using namespace std;

int user=0;
int uxu[100][100],i=0,j=0,k;
int uxp[100][100];

struct date
{
	int dd;
	int mm;
	int yyyy;
};

struct time
{
	int hr;
	int min;
	int sec;
};


struct chit
{
	int cid;
	int uid;
	struct time t;
	char content[101];
};

struct profile
{
	int uid = 0;
	char fname[20];
	char lname[20];
	char uname[20];
	char pass[20];
	struct date BDAY;
	char bio[50];
	char emailid[20];
	int nofers=0;
	int nofing=0;
	int noc=0;
	int nol=0;
};


void setmatrixs()
{
	FILE *fp;
	fp = fopen("fmatrix.txt","r");
	do
	{
		for(j=0;j<100;j++)
		{
			fscanf(fp, "%d ",&uxu[i][j]);
		}
		i++;
	}
	while(!feof(fp));
	fclose(fp);

	i=0;
	j=0;
	fp = fopen("lmatrix.txt","r");
	do
	{
		for(j=0;j<100;j++)
		{
			fscanf(fp, "%d ",&uxp[i][j]);
		}
		i++;
	}
	while(!feof(fp));
	fclose(fp);
}

int signup(int uid, char *fname,char *lname,char *uname,char *pass,char *bio,char *emailid,int dd, int mm, int yyyy, int nofers, int nofing, int noc, int nol)
{
	user=0;
	FILE *fp;
	fp = fopen("users.txt","r");
	do
	{
		struct profile c;
		fscanf(fp, "%d\n%s %s %s %s %s %s\n%d %d %d %d %d %d %d\n",&c.uid,c.fname,c.lname,c.uname,c.pass,c.bio,c.emailid,&c.BDAY.dd,&c.BDAY.mm,&c.BDAY.yyyy,&c.nofers,&c.nofing,&c.noc,&c.nol);
		user=c.uid;
	}
	while(!feof(fp));
	fclose(fp);

	uid=user+1;
	fp = fopen("users.txt","a");
	fprintf(fp, "%d\n%s %s %s %s %s %s\n%d %d %d %d %d %d %d\n",uid,fname,lname,uname,pass,bio,emailid,dd,mm,yyyy,nofers,nofing,noc,nol);
	fclose(fp);
	return 1;
}

int login(char *usname, char *pwd)
{
	int flag=0;
	FILE *fp;
	fp = fopen("users.txt","r");
	do
	{
		struct profile l;
		fscanf(fp, "%d\n%s %s %s %s %s %s\n%d %d %d %d %d %d %d\n",&l.uid,l.fname,l.lname,l.uname,l.pass,l.bio,l.emailid,&l.BDAY.dd,&l.BDAY.mm,&l.BDAY.yyyy,&l.nofers,&l.nofing,&l.noc,&l.nol);
		if(!(strcmp(usname,l.uname)||strcmp(pwd,l.pass))) return l.uid;
	}
	while(!feof(fp));
	fclose(fp);
	return 0;
}

int checkunameavail(char *usname)
{
        FILE *fp;
        fp = fopen("users.txt","r");
        do
        {
                struct profile l;
                fscanf(fp, "%d\n%s %s %s %s %s %s\n%d %d %d %d %d %d %d\n",&l.uid,l.fname,l.lname,l.uname,l.pass,l.bio,l.emailid,&l.BDAY.dd,&l.BDAY.mm,&l.BDAY.yyyy,&l.nofers,&l.nofing,&l.noc,&l.nol);
                if(!strcmp(usname,l.uname)) return 0;
        }
        while(!feof(fp));
        fclose(fp);
	return 1;
}

void loginuser(int uid)
{
	int i,j,k;
	FILE *fp;
	fp = fopen("fmatrix.txt","r");
	//print all the posts of the followed users.
	for(i=0;i<100;i++)
	{
		//print all the posts of that user.
		do
		{
			for(j=0;j<100;j++)
			{
				fscanf(fp, "%d ",&uxu[i][j]);
			}
			i++;
		}
		while(!feof(fp));
		fclose(fp);
	}
	int watnow;
	cout<<"Welcome to Chitter!"<<endl;
	cout<<"What you wanna do today?"<<endl;
	cout<<"1. Chit what's on your mind!?"<<endl;
	cout<<"2. View your own profile!?"<<endl;
	cout<<"3. See what's trending now!?"<<endl;
	cin>>watnow;
	/*fp = fopen("fmatrix.txt","w");
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
			{
				fprintf(fp, "%d ",uxu[i][j]);
			}
			fprintf(fp, "\n");
		}
	}
	fclose(fp);*/
}

int follow(int user, int tof)
{
	int i,j,k;
	uxu[user-1][tof-1] = 1;
	FILE *fp;
	fp = fopen("fmatrix.txt","w");
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			fprintf(fp,"%d ",uxu[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

int like(int user, int tol)
{
	int i,j,k;
	uxp[user-1][tol-1] = 1;
	FILE *fp;
	fp = fopen("lmatrix.txt","w");
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		{
			fprintf(fp,"%d ",uxp[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

void renderSignup()
{
	cout<<"        SIGNUP!          "<<endl;
	struct profile n;
	cout<<"Enter first name: ";
	scanf("%s",n.fname);
	cout<<"Enter last name: ";
	scanf("%s",n.lname);
	cout<<"Enter username: ";
	scanf("%s",n.uname);
	cout<<"Enter password: ";
        scanf("%s",n.pass);
	while(!checkunameavail(n.uname)) {cout<<"Username already taken! Please try again."; scanf("%s",n.uname);}
	cout<<"Enter email id: ";
	scanf("%s",n.emailid);
	cout<<"Enter your birthday: "<<endl;
	cout<<"Date: ";
	cin>>n.BDAY.dd;
	cout<<"Month: ";
	cin>>n.BDAY.mm;
	cout<<"Year: ";
	cin>>n.BDAY.yyyy;
	printf("Enter a short bio about you: ");
	scanf("%[^\n]%*c",n.bio);
	user++;
	if(signup(user,n.fname,n.lname,n.uname,n.pass,n.bio,n.emailid,n.BDAY.dd,n.BDAY.mm,n.BDAY.yyyy,n.nofers,n.nofing,n.noc,n.nol)) cout<<"Signed up successfully!"<<endl;
	else {user--; cout<<"Some error in signup! Please try again later."<<endl;}
}

void renderLogin()
{
	cout<<"        LOGIN!          "<<endl;
	char uname[20];
	char pwd[20];
	cout<<"Enter username: ";
	cin>>uname;
	cout<<"Enter password: ";
	cin>>pwd;
	if(uname!="" || pwd!="")
	{
		user = login(uname, pwd);
		if(user) {cout<<"Logged in successfully!"<<endl; loginuser(user);}
		else {cout<<"Invalid credentials! or User yet not registered!"<<endl; renderLogin();}
	}
	else
	{
		cout<<"Invalid entry! Please try again.";
		renderLogin();
	}
}

void renderWhat()
{
	int wtd;
	cout<<"Press 1 for signup. Or 2 to login, if you're already a user: ";
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
	setmatrixs();
	renderHomepage();
	return 0;
}

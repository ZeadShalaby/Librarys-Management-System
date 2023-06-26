#include<bits/stdc++.h>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;
void readfile();
void addbook();
void displaydata();
void menu();
void searchbook();
void deletebook();
void sorting();
//void deleterecord();
char ch;
const int size = 100;
int IDbook[size];
string style[size];
string model[size];
int price[size];

string br, md;
int id, pr;

int Eindex();
int Edindex();
int Lindex(int idnum);
void writefile();
bool Sindex(int idno);
void update();
int c = 0; // counter

int main()
{
	int choose;
	do
	{
		system("cls");

		cout << "\n\n\t                                     PLEASE SELECT FROM THE MENUE  ";
		cout << "\n\n\t                               Please choose one of the below options:   \n\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "(1).Add a Book \n\n";
		cout << "(2).Delete a Book  \n\n";
		cout << "(3).Update Book \n\n";
		cout << "(4).Find Book  \n\n";
		cout << "(5).List Book \n\n";
		cout << "(6).Show statistics \n \n";
		cout << "(7).exit \n\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
        cout<< "please input the number of the choice you want to excute : ";
		cin >> choose;

		readfile();
		system("cls");

		switch (choose)
		{

		case 1:
			//readfile();
			addbook();
			writefile();
			break;

		case 2:

			deletebook();
			writefile();
			break;
		case 3:
			update();
			writefile();

			break;
		case 4:
			searchbook();
			break;
		case 5:

			displaydata();
			system("cls");
			for (int i = 0; i<c; i++)
				cout << IDbook[i] << "\t" << style[i] << "\t" << model[i] << "\t" << price[i] << endl;

			break;
		case 6:

			break;
		case 7:
			cout << "\n\n\n\n\n\n\t\t                 GOOD BYE.....";
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (choose != 7);

	return 0;
}




//**********************************************************************************************************************************************************
void addbook()
{
	string x;
	int idno;
	do{
		int label = Eindex();
		if (label == -1)
		{
			cout << "\n\t\t no avialable space for new car\n";
			return;
		}


		bool h;
		do{
			system("cls");
			cout << "\n\nPLEASE ENTER THE ID Book:  ";
			cin >> idno;

			if (Sindex(idno))
			{
				cout << "\n\t\t THE ID Book IS EXIST, TRY AGAIN\n";
				h = 1;
			}
			else
				h = 0;
		} while (h);


		IDbook[label] = idno;

		cout << "\n\nPLEASE ENTER style:  ";
		cin >> br;
		cout << "\n\nPLEASE ENTER model:  ";
		cin >> md;
		cout << "\n\nPLEASE ENTER price:  ";
		cin >> pr;


		style[label] = br;
		model[label] = md;
		price[label] = pr;




		cout << "\n\n\nTO ADD MORE ENTER (Y).. OR To Exit Enter (N) ";
		cin >> x;
	} while (x != "N" && x != "n");

	cout << "\nTHE RECORD IS SUCCESSFULY CREATED..";
}
//*****************************************************************
void readfile()						// READING THE INFORMATION FROM THE FILE
{
	ifstream inFile;
	inFile.open("library.txt");
	if (!inFile)
	{
		return;
	}
	int i = 0;
	while (!inFile.eof())
	{
		int idno; br, md, pr;
		inFile >> idno;
		if (idno <= 0)
			return;
		inFile >> br >> md >> pr;

		IDbook[i] = idno;
		style[i] = br;
		model[i] = md;
		price[i] = pr;


		i++;
	}
	for (int i = 0; i <= c; i++)

		inFile.close();
}






void writefile()						// WRITING THE DATA INTO THE FILE
{
	ofstream outFile;
	outFile.open("library.txt");
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (IDbook[i] == 0)
			break;
		outFile << "\n" << IDbook[i] << "          " << style[i] <<  "          " << model[i] <<  "          " << price[i];

	}
	outFile.close();
}


bool Sindex(int idno)				// RETURN TRUE IF THE car EXIST
{
	for (int i = 0; i < size; i++)
	{
		if (IDbook[i] == 0)
			return false;
		if (IDbook[i] == idno)
			return true;
	}
	return false;
}


int Eindex()					// SEARCH  EMPTY INDEX IN ARRAY
{
	for (int i = 0; i < size; i++)
	{
		if (IDbook[i] == 0)
			return i;
	}
	return -1;
}


int Lindex(int idnum)			// SEARCH THE IDCAR INDEX IN ARRAY
{
	void sorting();
	for (int i = 0; i < size; i++)
	{
		if (IDbook[i] == 0)
			return -1;
		if (IDbook[i] == idnum)
			return i;
	}
	return -1;
}


void menu()
{
	cout << "\n\n\t   TO UPDATE.. CHOOSE FROM THE MENUE: ";
	cout << "\n\n\t1. UPDATE THE ID BOOK FIELD:\t";
	cout << "\n\n\t2. UPDATE THE STYLE FIELD:\t";
	cout << "\n\n\t3. UPDATE THE MODEL FEILD:\t";
	cout << "\n\n\t4. UPDATE THE PRICE  FELD:\t";

	cout << "\n\n\tPLEASE ENTER YOUR CHOICE:\t";
}

//**************************************************************
void update()						//   UPDATE CAR INFORMATION
{

	system("cls");
	menu();
	int IDno;

	cout << "\n\nPLEASE ENTER ID BOOK:  ";
	cin >> IDno;

	if (!Sindex(IDno))
	{
		cout << "\n\t\t  ID BOOK IS NOT FOUND\n";
		return;
	}

	int S = Lindex(IDno);

	IDbook[S] = IDno;

	int x;
	do{
		system("cls");
		menu();
		cin >> x;
		switch (x){
		case 1:
			cout << "\n\nPLEASE ENTER THE ID BOOK";
			cin >> IDno;
			IDbook[S] = IDno;
			cout << "\n\nTHANK YOU";
			break;
		case 2:

			cout << "\n\nPLEASE ENTER style:  ";
			cin >> br;
			style[S] = br;
			cout << "\n\nTHANK YOU ";
			break;
		case 3:

			cout << "\n\nPLEASE ENTER THE MODEL :  ";
			cin >> md;
			model[S] = md;
			cout << "\n\nTHANK YOU";
			break;
		case 4:

			cout << "\n\nPLEASE ENTER  PRICE:  ";
			cin >> pr;
			price[S] = pr;
			cout << "\n\nTHANK YOU";
			break;


		default:cout << "\n\nINVALID ENTERED ... TRY AGAIN ";
		}
		cout << "\n\nWOULD YOU LKE TO CHANGE ANOTHER FEILD?(Y/N):";

		cin >> ch;
	}

	while (ch != 'n'&& ch != 'N');

	cout << "\nTHE BOOK FILE IS UPDATED..";
}


//**************************************************************
void searchbook()
{
	system("cls");

	int IDno;

	cout << "\n\nPLEASE ENTER ID BOOK:  ";
	cin >> IDno;

	if (!Sindex(IDno))
	{
		cout << "\n\t\t  ID BOOK IS NOT FOUND\n";
		return;
	}

	int S = Lindex(IDno);

	cout << IDbook[S] << "\t" << style[S] << "\t" << model[S] << "\t" << price[S] << endl;
}

//**************************************************************
void displaydata()
{
	ifstream infile;

	infile.open("library.txt");
	if (infile)
	while (!infile.eof())
	{
		infile >> IDbook[c] >> style[c] >> model[c] >> price[c];
		c++;
	}
	infile.close();
}

void deletebook()
{
	system("cls");
	int id_no, ss;
	cout << "\n\n\t PLEASE ENTER THE IDbook ";
	cin >> id_no;
	if (!Sindex(id_no))
	{
		cout << "\n\t\t IDbook  is not found\n";
		return;
	}

	ss = Lindex(id_no);

	if (IDbook[ss + 1] == 0)
	{
		IDbook[ss] = 0;
		cout << "\n\n\t Record is deleted ";
		return;
	}


	for (int i = ss; i<size - 1; i++)
	{
		if (IDbook[i + 1] == 0)
		{
			IDbook[i] = 0;
			cout << "\n\n\t Record is deleted ";
			i = size;
		}
		else
			IDbook[i] = IDbook[i + 1];


	}
	cout << "\n\n\t Record is deleted ";


}

int Edindex()					// SEARCH  EMPTY INDEX IN ARRAY
{
	for (int i = 0; i < size; i++)
	{
		if (IDbook[i] == 0)
			return i;
	}
	return -1;
}
//**********************************
void sorting()
{
	int i, j, temp;
	for (i = 0; i<c; i++)
	{
		for (j = 0; j<size - 1; j++)
		{
			if (IDbook[j]>IDbook[j + 1])
			{
				temp = IDbook[j];
				IDbook[j] = IDbook[j + 1];
				IDbook[j + 1] = temp;
			}
		}
	}
}






















/*
/////////////  Codeforces 427A     //////////
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,v,con=0,conn=0;
cin>>n;
for(int i=0;i<n;i++){
    cin>>v;
    if(v>0){
        con+=v;
        continue;
    }
    else if(v<0&&con>0){
        con-=1;
        continue;
    }
    else if(v<0){
        conn++;
}}
cout<<conn;
}
///////   Codeforces 289A       //////////
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,con=0;
cin>>n>>m;
for(int i=0;i<n;i++){
    int s,e;
    cin>>s>>e;
    con+=e-s+1;
     con%=m;
}
if(con!=0)
 con=m-con;
    cout<<con;
}
////////////Codeforces 467A/////////

#include<bits/stdc++.h>
using namespace std;
int main(){
int n,con=0;
cin>>n;
for(int i=0;i<n;i++){
    int p,q;
    cin>>p>>q;
   if(q-p>=2){
    con++;
}}
cout<<con;
}
///////////////  A. Shaass and Oskols  /////////

#include<bits/stdc++.h>
using namespace std;
int main(){
int n,mx=100;
cin>>n;
int a[mx];
for(int i=0;i<n;i++)
    cin>>a[i];
int b;
cin>>b;
for(int i=0;i<b;i++){
int x,y;
cin>>x>>y;
x--;
if(x!=0)
    a[x-1]+=y-1;

  if(x!=n-1)
    a[x+1]+=a[x]-y;

  a[x]=0;
}

for(int i=0;i<n;i++){
    cout<<a[i]<<"\n";
    #include<bits/stdc++.h>

using namespace std;
#define cin(vec) for(auto& i : (vec)) cin >> i;
#define cout(vec) for(auto& i : (vec)) cout << i << " "; cout << "\n";
#define int long long
#define ull unsigned long long
#define dd double
#define endl "\n"
#define all(v) ((v).begin()), ((v).end())
#define gcd(a, b)  __gcd(arr, b)
#define lcm(a, b) (arr * b) / (gcd(arr, b))
#define mod(a, b) (arr - arr / b * b)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

}}



*/

#include <iostream>
#include <vector>
#include "User.h"
#include "User.cpp"
#include <queue>

using namespace std;
int main()
{

	vector<User> users;
	BSTree<long long> B;
	BSTree<string> C;
	queue<long long>RemovedIds;
	int choice = 0;
	User u;
	User u1, u2,admin;
	int Cn = 0;

	// User One 
	u1.nat_id = 1357;
	u1.age = 20;
	u1.name = "Nada Mohamed";
	u1.Country = "Egypt";
	u1.A_V = true;
	u1.A_V1 = true;
	u1.gender = "female";
	u1.Doses = 1;
	u1.Gover = "Cairo";
	u1.Pass = "abc";

	// User two
	u2.nat_id = 2468;
	u2.age = 21;
	u2.name = "Habiba El Nahrawy";
	u2.Country = "Egypt";
	u2.A_V = true;
	u2.A_V1 = true;
	u2.gender = "female";
	u2.Doses = 2;
	u2.Gover = "Cairo";
	u2.Pass = "xyz";


	users.push_back(u1);
	B.insert(u1.nat_id);
	C.insert(u1.Pass);

	users.push_back(u2);
	B.insert(u2.nat_id);
	C.insert(u2.Pass);
	RemovedIds.push(0);


	cout << "\n**********Welcome to the online Vaccination system \n\n *Choose an Option from below* \n" << endl;
	while (true)
	{
		cout << "\n 1) Register as a new user \t 2) Login \t 3)Exit" << endl;
		cin >> choice;
		string  pass;
		long long id;
		int x = 0;
		string new_name;
		string new_pass;
		string new_Gover;
		string new_ID;
		int new_Doses;
		bool Can_Delete_2 = true;
		bool Can_Delete_1 = false;
		
		switch (choice)
		{

			//register
		case 1:

			cout << "\n 1)Fill the Registaraion form \t\t 2)Back to Main menu \n\n";

			cin >> choice;

			if (choice == 1) {

				cout << "Enter Your Name:" << endl;
				cin >> u.name;
				while (find_if(u.name.begin(),u.name.end(),isdigit)!=u.name.end())
				{
					cout << "\nYour Name Can't Contain Any Numbers\n\n";
					cout << "Enter Your Name:" << endl;
					cin >> u.name;
				}
				cout << "Enter Your Password:" << endl;
				cin >> u.Pass;		
				
				while (true)
				{
					cout << "Enter Your ID:" << endl;
					cin >> u.nat_id;
					string Str =to_string (u.nat_id);
					if (Str.length()==13)
					{
						if (B.contains(u.nat_id)) {

							cout << "ID Already exists\n\n";
							continue;
						}

						else
						{
							break;
						}


						///////////////gdiddddddddddddddddddd




					}
					else
					{
						cout << "\n Your ID Must Contain 13 Numbers\n\n";
						continue;
					}

				}

				u.read(users, u1);

			}
			else
				break;

			users.push_back(u);
			B.insert(u.nat_id);
			C.insert(u.Pass);

			cout << "\n\n ******Registeration Done Succesfully**** \n\n" << endl;

			u.Login(users, x, u.nat_id, u.Pass, u);
			break;

			//Login
		case 2:

			cout << "Enter Your ID:\t";
			cin >> id;
			cout << endl;
			cout << "Enter Your Password:\t";
			cin >> pass;
			cout << endl;
			x = id;



			//logged in as an admin
			if (id == 123 && pass == "admin")
			{
				cout << "Logged in as an Admin \n\n";
				long long input;
				cout << "enter the user national id : " << endl;
				cin >> input;
				for (unsigned int i = 0; i < users.size(); i++)
				{
					
					if (users[i].nat_id == input)
					{


					if (B.contains(input) && users[i].name.empty() == false)
					{
						cout << RemovedIds.back();
						if (RemovedIds.back() == u1.nat_id)
							RemovedIds.pop();
						if (RemovedIds.back() == users[i].nat_id|| RemovedIds.front() == users[i].nat_id) {
							cout << "This Account Doesn't Exist or Has Been Deleted !!!!" << endl;
							break;

						}
						cout << "User Founded Succesfully\n\n";
						while (true)
						{

							if (Cn > 0) {
								Cn++;
								cout << "\n\n 1) Make another Operation \t 2) Return to main menu \n\n" << endl;
								cin >> choice;
								if (choice == 2)
									break;

							}
								


							cout << "\n1)Display User Account \t 2)Delete The User Account \t 3)Show Waiting list \t 4)Back to main menu \n\n";
							cin >> choice;
							if (choice == 1)
							{
								cout << "Your Name Is ::\t";
								cout << users[i].name << endl;
								cout << "Your ID Is ::\t";
								cout << users[i].nat_id << endl;
								cout << "Your Age::\t";
								cout << users[i].age << endl;
								cout << "Your Gender Is ::\t";
								cout << users[i].gender << endl;
								cout << "Your Password Is ::\t";
								cout << users[i].Pass << endl;
								cout << "Your Country Is ::\t";
								cout << users[i].Country << endl;
								cout << "Your Governerate Is ::\t";
								cout << users[i].Gover << endl;
								cout << "The Number Of Doses Taken::\t";
								cout << users[i].Doses << endl;
								cout << "\n*********************** \n";
								cout << "\n Opertion Done Suucesfully \n\n";

							}
							//edit
							else if (choice == 2)
							{
								users[i].name.clear();
								cout << "\nAccount Deleted..\n";
								RemovedIds.push(input);
								break;

							}
							else if (choice == 3)
							{
								u.Show_Waiting_List(u1);
							}
							else if (choice == 4)
							{
								break;
							}
							else
							{
								cout << "\nInvalid Choice Entry !!\n";
								break;
							}
						}

					}
					else
					{
						cout << "This Account Doesn't Exist or Has Been Deleted !!!!" << endl;
						continue;
					}
				}

		        }
			}

			//logged in as user
			else if (B.contains(id) && C.contains(pass))
			{
				if (RemovedIds.back() == u1.nat_id)
					RemovedIds.pop();
				if (RemovedIds.back() == id || RemovedIds.front() == id )
				{
					if (u.name.empty() == true) {
						cout << "\n********User Deleteeeed**********\n\n" << endl;
						break;
					}
				}
				
				int userno;

				for(int i=0;i<users.size();i++)
				{
					if (id == users[i].nat_id) 
					{
						cout << "\n*********************** \n";
						cout << "-Logged In Succesfully as : " << users[i].name << endl<<endl;
						userno = i;
					}
				}

			

				if (u.Login(users, x, id, pass, u) == true)

					
						RemovedIds.push(id);
					
			}

			//Invalid Login
			else
			{
				cout << "This Account Doesn't Exit !!!!\n" << endl;
			}
			break;
	
		case 3:
			cout << "\n *******thanks for using our system******* \n\n";
			exit(0);
			break;

			default:
				cout << "Invalid Choice Entry !!\n";
		}
	}
}

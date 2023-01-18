#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//template <class T>
class User
{
public:

	long long nat_id;
	string name;
	string gender;
	string Pass, Country, Gover;
	string A_V1;
	bool A_V = true;
	int Doses;
	int age;
	int cOunt = 0;
	int CCount = 0;
	int z = 1;

	//int n_of_user;
  //  User(string Name, int number);
	void Terminate() {
		exit(0);
	}

	void Show_Waiting_List(User u1) 
	{
		int choice = 0;
		if (CCount == 0)
			Admin_WaitingList.push(u1.nat_id);

		cout << "The waiting list of the Registerd Users: \n\n";
		for (int i = 0; i < Admin_WaitingList.size(); i++)
		{
			CCount++;
			cout << CCount << ") " << Admin_WaitingList.front() << endl;
			Admin_WaitingList.pop();

		}

	}


	bool Login(vector<User> users, int x, int id, string pass, User u) {
		int Cn = 0;
		int choice = 0;
		int choice2;
		int mainchoice;
		int New_Doses;
		string New_name;
		string New_Password;
		string New_Governerate;


		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].nat_id == id)
			{

			  while (true)
			  {
				if (Cn > 0) {
					cout << "\n 1) Make a " << Cn + 1 << "nd Operation \t 2) Back to Main Menu \n";
					cin >> mainchoice;
					if (mainchoice == 2)
					{
						break;
					}
				}
					Cn++;
					cout << "\n Choose an Option From below \n\n" << endl;
					cout << " 1) Display your Record  \t 2) Edit your record  \t 3)delete your record \t 4) Back to Main Menu\n " << endl;
					cin >> choice;


				//Display User Info
					if (choice == 1) 
					{

							if (users[i].name.empty() == 1)
							{
								cout << "You Can't Display a Deleted Account\n";
								break;
							}
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
							cout << "Your Current Account Information Are ::" << endl;
							cout << "Your Current name Is : " << users[i].name << endl;
							cout << "Your Current password Is : " << users[i].Pass << endl;
							cout << "Your Current Governerate Is : " << users[i].Gover << endl;
							cout << "Your Current Number Of Doses Is/Are :" << users[i].Doses << endl;
							cout << "Choose The Field You Desire To Edit [1==>4] :\n";

							cin >> choice2;

							//Change Name Attribute
							if (choice2 == 1)
							{
								while (true)
								{
									cout << "Your Current name is: \t" << users[i].name << "\n Enter Your New Name: \n";
									cin >> New_name;
									if (users[i].name == New_name)
									{
										cout << "Operation Cancelled!! (New Name matches The Old One)..\n\n";
										continue;
									}
									else
									{
										users[i].name = New_name;
										break;
									}
								}
							}
							//Change Password Attribute
							else if (choice2 == 2)
							{
								while (true)
								{
									cout << "Your Current Password is: \t" << users[i].Pass << "\n Enter Your New Password: \n";
									cin >> New_Password;
									if (users[i].Pass == New_Password)
									{
										cout << "Operation Cancelled!! (New Password matches The Old One)..\n\n";
										continue;
									}
									else
									{
										users[i].Pass = New_Password;
										break;
									}
								}
							}
						
							//Change Governerate Attribute
							else if (choice2 == 3)
							{
								while (true)
								{
									cout << "Your Current Governerate is: \t" << users[i].Pass << "\n Enter Your New Governerate: \n";
									cin >> New_Governerate;
									if (users[i].Gover == New_Governerate)
									{
										cout << "Operation Cancelled!! (New Governerate matches The Old One)..\n\n";
										continue;
									}
									else
									{
										users[i].Gover = New_Governerate;
										break;
									}
								}
							}
							//Change Number of Doses Attribute
							else if (choice2 == 4)
							{
								while (true)
								{
									cout << "Your Current Number Of Doses is: \t" << users[i].Pass << "\n Enter Your New Number Of Doses: \n";
									cin >> New_Doses;
									if(New_Doses == 1 || New_Doses == 2)
									{
										if (users[i].Doses == New_Doses)
										{
											cout << "Operation Cancelled!! (New Number Of Doses The Old One)..\n\n";
											continue;
										}
										else
										{
											users[i].Doses = New_Doses;
											break;
										}
									}
									else
									{
										cout << "The Number Of Doses Is Either 1 Or 2 !!\n\n";
										continue;
									}
								}
							}
							else 
							{
								cout << "Invalid Choice Entry !!\n";
								continue;
							}
				
							cout << "\n*********************** \n";
							cout << "\n Opertion Done Suucesfully \n\n";

						}
	
						//Delete 
						else if (choice == 3)
						{
							/*if(Can_Delete==true)
							{*/
								cout << "User Record Deleted \n\n";
						
								return true;
							/*}*/
							/*else
							{
								cout << "\nyou Can't Delete A Newly Regitered User\n\n";

								return true;

								continue;
							}*/
						}

						else if (choice == 4)
						{
							break;;
						}

			  }
			}	
		}
	}


	//read Function
	queue<int>WaitingList;

	queue<int>Admin_WaitingList;


	void read(vector<User> users,User u1)
	{

		
		while (true)
		{
			cout << "\nEnter Your Age:" << endl;
			cin >> age;
			//invalid age
			if (age > 100 || age < 5)
			{
				cout << "Invalid Age Entry !!\n";
			}
			//valid age
			else
				break;
		}
		while (true)
		{
			cout << "Enter Your Gender:" << endl;
			cin >> gender;
			if (gender != "m" && gender != "male" && gender != "female" && gender != "f")
			{
				cout << "Invalid Gender Entry !!\n\n";

			}
			else
				break;
		}
		while (true)
		{
			cout << "Enter Your Country:" << endl;
			cin >> Country;
			if(Country=="Egypt" || Country == "EGYPT" || Country == "egypt")
			{
				break;
			}
			else
			{
				cout << "\nYou Must Be An Egyptian to Apply For vaccination \n\n";
				continue;
			}
		}
		
		cout << "Enter Your Governerate:" << endl;
		cin >> Gover;
		
		while (true)
		{
			cout << "State Whether You are Vaccinated Or Not::" << endl;
			cin >> A_V1;
			if (A_V1 == "y" || A_V1 == "Y" || A_V1 == "yes" || A_V1 == "YES")
			{

				while (true)
				{
					cout << "Enter The Number of Doses You Have Taken (1-2) :" << endl;
					cin >> Doses;
					if (cOunt == 0) {
					WaitingList.push(u1.nat_id);
					}
					
						WaitingList.push(nat_id);
						Admin_WaitingList.push(nat_id);
				
					
					if (Doses == 1)
					{
						cOunt++;
						cout << "**************************************\n\n";
						cout << "\n\n*****you are now added to the ("<<cOunt+1 <<"nd) place in the waiting list With ID: "<<nat_id<<" ***** \n\n";

								long retrieveReservation = WaitingList.front();
								WaitingList.pop();
								cout << "User with ID :  " << retrieveReservation << " is the 1st to have his second vaccine on (" << cOunt << "/6/2021) \n\n";
								cout << "You are now added as User: "<< nat_id << " \n\n Your Vaccine registeration is on(" << cOunt + 1 << "/6/2021) \n\n" << endl;
							
						break;
					}
					else if (Doses == 2)
					{
						A_V = true;
						cout << "You Have Completed Your Vaccination Procedure as you succesfylly recieved the 2 vaccines needed:\n";
						break;
					}
					else
					{
						cout << "Invalid Number Of Doses Entry !!\n\n";
					}

				}
				
				break;
			}

			else if (A_V1 == "n" || A_V1 == "N" || A_V1 == "no" || A_V1 == "NO")
			{

					if (cOunt == 0)
						WaitingList.push(u1.nat_id);
					WaitingList.push(nat_id);

						cOunt++;

						cout << "\n **you are now added to the waiting list** \n ";

						cout << "**************************************\n\n";

						long retrieveReservation = WaitingList.front();
						WaitingList.pop();
						cout << "User with ID :  " << retrieveReservation << " is now ready to have his second vaccine on (" << cOunt << "/6/2021) \n\n";
						cout << "You are now in the " << cOunt + 1 << "nd position in the waiting list, \n\n Your Vaccine registeration is on (" << cOunt + 1 << "/6/2021) \n\n" << endl;


				break;
			}

			else
			{
				cout << "Invalid State Of Vaccination Entry !!\n\n";
			}
		}
		
	}

	 void Delete(vector<User> users)
	 {
		 // vector<User> users;
		for (unsigned int i = 0; i < users.size(); i++)
		{
			users[i].name.clear();
			users[i].Pass.clear();
			users[i].gender.clear();
			users[i].Country.clear();
			users[i].Gover.clear();
			users[i].age = NULL;
			users[i].Doses = NULL;
			users[i].A_V1.clear();
			users[i].nat_id = NULL;
		}

	 }

	User(double nat_id, string name, string gender, string Pass, string Country, string Gover, bool A_V, int Doses, int age)
	{
		this->nat_id = nat_id;
		this->name = name;
		this->gender = gender;
		this->Pass = Pass;
		this->Country = Country;
		this->Gover = Gover;
		this->A_V = A_V;
		this->Doses = Doses;
		this->age = age;
	}

	// Default Constructor

	User() {}

	void display(User us)
	{
		if (true)
		{

		}
			cout << "Your Name Is ::\t";
			cout << name << endl;
			cout << "Your ID Is ::\t";
			cout << nat_id << endl;
			cout << "Your Age::\t";
			cout << age << endl;
			cout << "Your Gender Is ::\t";
			cout << gender << endl;
			cout << "Your Password Is ::\t";
			cout << Pass << endl;
			cout << "Your Country Is ::\t";
			cout << Country << endl;
			cout << "Your Governerate Is ::\t";
			cout << Gover << endl;
			cout << "The Number Of Doses Taken::\t";
			cout << Doses << endl;
		
	}
};
template<class T>
class Node
{
public:
	T Nat_Id;

	Node<T>* left, * right;
	Node();
	Node(T val);
};

template<class T>
class BSTree
{
	Node<T>* root;

public:
	BSTree();
	bool contains(T val);
	Node<T>* findNode(T val);
	void insert(T val);
};

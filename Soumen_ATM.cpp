//*****************************************************************************************
//  Program Filename   : SoumenATM.cpp
//  Version            : 1.0
//  Author             : Soumen Nath
//  Purpose            : To demonstrate the ability to create an working ATM
//  Date               : December, 6
//  Input from         : Keboard
//  Output to          : Screen
//*****************************************************************************************


//Preprocessor Directives
#include <iostream>
#include <vector>
using namespace std;


//Function Declarations
void welcome();
int pin(); //The pin number can be any 4 digit number
int menu();
int depositMoney();
int withdrawMoney(int);
void requestBalance(int);
void goodbye();


//Name Constant Definitions
//*****************************************************************************************
// Function Name: main
// Purpose: main function of program
// Inputs to Function: N/A
// Outputs from Function: N/A
// External Inputs to Function: cin
// External Outputs from Function: cout
//*****************************************************************************************
int main()
{
    //Variable Declarations:
    system ("color 1f"); //Changes the background colour to dark blue and the text colour to white
    vector<int> account; //Vector that stores the pin number and the account balance for each user
    int temp = 0 ; //Temporary variable that stores the value for the account balance
    int temp2 = 0; //Temporary variable that stores the value for the account balance
    int temp3; //Temporary variable that stores the value for the account balance
    int pinNum = 0; //Variable that stores the pin number temporarily until another user is using the ATM
    int balance = 0; //Variable that stores the account balance temporarily
    int uOption = 0; //Variable that stores the user's option
    //Variables that store an arbitrary values and whose purpose is to keep the do while loops infinite
	int infinite = 0; 
    int infinite2 = 1;
    
    //Function Body
   do 
   {
   	 	welcome(); //Call the welcome function
    	pinNum=pin(); //Call the pin function and make pinNum equal to the value that was returned from the pin function 
    	account.push_back(pinNum); //Add a new element at the end of the vector to store each pin number
    	account.push_back(balance); //Add a new element at the end of the vector to store the account balance for each user 
    	for (int i=0; i<account.size(); i++) //For loop that checks if the same pin number was entered again
		{
			for (int j=0; j<account.size(); j++)
			{
				if (account[i]==account[j] && i!=j) //if the same pin number was entered again then:
				{
					balance=account[i+1]; //The balance is equal to the cell that is after the one that stores the pin number
					//Removes two elements at the end of the vector
					//This makes it so that when the same pin number is entered again, two new cells are not created to store the same pin number and another balance
					account.pop_back();
					account.pop_back();
				}
			} 
		} 
    	do 
		{
			uOption=menu(); //Call the menu function
		   	switch (uOption) 
			{
				case 1: //If the user pressed 1:
					temp=depositMoney(); //Call on the deposit function and store the return value in temp
					for (int l=0; l<account.size(); l++) //for loop that checks if the value in the account vector is equal to the value in pinNum
					{
						if (account[l]==pinNum) //If they are equal then:
						{
							account[l+1]+=temp; //The cell after the account is increased by the value in temp
							balance+=temp; //The balance is increased by the value in temp
						}
					}
					temp=0; //Resets the value of temp to 0;
					break;
				case 2: //If the user pressed 2 then:
					temp2=withdrawMoney(balance); //Call on the withdraw function, pass the value of balance to the withdraw function and store the return value in temp2
					for (int m=0; m<account.size(); m++) //for loop that checks if the value in the account vector is equal to the value in pinNum
					{
						if (account[m]==pinNum) //If they are equal then:
						{
							account[m+1]-=temp2; //The cell after the account is decreased by the value in temp
							balance-=temp2; //The balance is decreased by the value in temp
						}
					}
					temp2=0; //Resets the value of temp2 to 0;
					break;
				case 3: //If the user pressed 3 then:
					for (int n=0; n<account.size(); n++)
					{
						if (account[n]==pinNum) //If they are equal then:
						{
							temp3=account[n+1]; //Make the value of temp3 equal to the value of account[n+1}
							requestBalance(temp3); //Call on the requestBalance function and pass the value of temp3 to the requestBalance function  
						}
					}
					break;
				case 4: //If the user pressed 4 then:
					goodbye(); //Call the goodbye fucntion
					infinite2=2; //Make infinite 2 equal 2 in order to break this infinite loop
					break;					
			}
			cout<<endl;
		} while(infinite2==1); 
		infinite2=1; //Reset inifite2 back so it equals one again
		balance=0; //Rest the balance to 0
	} while (infinite==0);
    return 0;
}
//end function main


//Name Constant Definitions
//*****************************************************************************************
// Function Name: welcome
// Purpose: welcomes the user to the program
// Inputs to Function: N/A
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
void welcome()
{
	//Displays the statements in quotations
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;
    cout<<"\t\tWelcome to The Majectic Bank Of Canada's ATM"<<endl<<endl;;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl<<endl;
}
//end function welcome


//Name Constant Definitions
//*****************************************************************************************
// Function Name: pin
// Purpose: accepts the pin number from the user and returns that value to main
// Inputs to Function: N/A
// Outputs from Function: reurn
// External Inputs to Function: cin
// External Outputs from Function: cout
//*****************************************************************************************
int pin()
{
	int pinNumber;  //The variable that accepts the user's pin number
	cout<<"Please enter your pin number: "; //Displays the statement in quotations
	cin>>pinNumber; //Accepts the pin number from the user
	cout<<endl;
	if(pinNumber>=1000 && pinNumber<=9999) //If the pin number is in the correct range then return the pin number to main
	{
		return pinNumber;	
	}
	while (!(pinNumber>=1000 && pinNumber<=9999)) //While the pin number is not in the correct range then the user will be asked to enter it again
	{
		cout<<"Invalid entry! Please enter your pin number again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin>>pinNumber;
		cout<<endl;	
	}
}
//end function pin


//Name Constant Definitions
//*****************************************************************************************
// Function Name: menu
// Purpose: Displays the main menu to the user and accepts the user's choice 
// Inputs to Function: N/A
// Outputs from Function:  return
// External Inputs to Function: cin
// External Outputs from Function: cout
//*****************************************************************************************
int menu()
{
	int userOption=0; //Varible that accepts the user option
	//Display the following statements in quotations
	cout<<"Please select an option from the menu below:"<<endl;
	cout<<"1 -> Deposit Money"<<endl;
	cout<<"2 -> Withdraw Money"<<endl;
	cout<<"3 -> Request Balance"<<endl;
	cout<<"4 -> Quit"<<endl;
	cout<<">";
	cin>>userOption; //Accept user option
	while (userOption<1 || userOption>4) //While the option is not in the correct range then the user will be asked to enter it again
	{
		cout<<"\nInvalid entry! Please enter your option again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin>>userOption;	
	}
	return userOption;	//Return the user option to main
}
//end function menu


//Name Constant Definitions
//*****************************************************************************************
// Function Name: depositMoney
// Purpose: Accepts the user's deposit and alter's and returns the new balance to main 
// Inputs to Function: N/A
// Outputs from Function: return
// External Inputs to Function: cin
// External Outputs from Function: cout
//*****************************************************************************************
int depositMoney()
{
	int deposit; //Variable that accepts the amount of money that the user wants to deposit
	cout<<"\nAmount of deposit: $"; //Display this statement
	cin>>deposit; //Accept the amount of deposit that the user wishes to make
	while (!cin.good()) //While the deposit entered by the user in not a number, the user will be asked to enter a number
	{
		cout<<"\nInvalid entry! Please enter the amount of deposit again: $";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin>>deposit;	
	}
	return deposit; //Return the deposit that the user made to main
}
//end function depositMoney


//Name Constant Definitions
//*****************************************************************************************
// Function Name: withdrayMoney
// Purpose: Accepts the user's deposit and alter's and returns the new balance to main 
// Inputs to Function: int
// Outputs from Function: return
// External Inputs to Function: cin
// External Outputs from Function: cout
//*****************************************************************************************
int withdrawMoney(int b)
{
	int withdraw; //Variable that accepts the amount of money that the user wants to withdraw
	do
	{
	cout<<"\nAmount of withdrawal: $"; //Diplays the statement in quotation mark
	cin>>withdraw; //Accepts the amount of money that the user wants to withdraw
	if (!cin.good()) //if the withdrawl entered by the user in not a number, the user will be asked to enter a number
	{
			cout<<"\nInvalid entry! Please enter the amount of withdrawl again: $";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin>>withdraw;	
	}
	else if (withdraw<=b) //If the withdrawl that the user wishes to make is less than his or her account balance then the withdrawl ammount is returned to balance
	{
		return withdraw; 
	}
	else //If the withdrawl that the user wishes to make is greater than he or she is asked to enter the amount of withdrawl again
	{
		cout<<"\nYou can not witdraw more money than there is in your bank balance."<<endl; 
		cout<<endl;
	}
		
	} while (withdraw>b);
}
//end function withdrawMoney


//Name Constant Definitions
//*****************************************************************************************
// Function Name: requestBalance
// Purpose: Displays the user's current balance
// Inputs to Function: int
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
void requestBalance(int b)
{
	cout<<"\nYour balance is: $"<<b<<endl; //Displays the user's current account balance
}
//end function requestBalance


//Name Constant Definitions
//*****************************************************************************************
// Function Name: goodbye
// Purpose: Thanks the user for using the program
// Inputs to Function: N/A
// Outputs from Function: N/A
// External Inputs to Function: N/A
// External Outputs from Function: cout
//*****************************************************************************************
void goodbye() 
{
	system("cls");
	cout<<"\nThank you for using the ATM of The Majectic Bank Of Canada. Goodbye!"<<endl<<endl<<endl<<endl<<endl<<endl; //Displays the statement in quotations
}
//end function goodbye

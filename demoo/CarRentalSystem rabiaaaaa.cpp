
#include <iostream>
#include <iomanip> 


string cars[2][5] = {{"HONDA", "SUZUKI", "TOYOTA", "AUDI", "RANGE ROVER"}, 
{"Available", "Available","Available","Available","Available"}}; // array with 2 rows and 5 columns




string name, cnic, phone;
int payment = 15000;
char option;
int serial , days, total;


void menu();
void rent();
void returnCar();
void logo();
void bill();


int main() {
	
	menu();
	system("pause");
	
}


void rent () {
	
	logo();
	
	cout << "\n\n";
	cout << "\t\t" << "List of available vehicles: \n\n";
	

	for (int i = 0; i < 2; i++){
		
		for (int j = 0; j < 5; j++){
			
		
			if (cars [i][j] == "Available"){
				
				cout << "\t\t" << "Serial Number - "<< j << " --- " << cars [i-1][j] /*name of cars*/ << " is available"<< endl;
			}
		}
	}
	
	cout << "\n\n";
	cout << "\t\t" << "Enter the SERIAL NUMBER of the car you want to rent... ";
	
	cin >> serial;
	

	
	if(cars[1][serial] == "Not Available"){
		
		cout << "\n\n\t\t";
		cout << "You have chosen " << cars [0][serial] << " which is currently " << cars[1][serial] << endl;
		cout << "\n\t\tSelect a car which is available. ";
		system("pause");
		
		rent();
	}
	
	cout << "\n\t\t" << "You have chosen " << cars [0][serial] << " which is currently " << cars[1][serial] << endl;
	cout << "\n\t\t" << "To unselect this car, press 1, enter 2 to go back to main menu otherwise enter anything to proceed... ";
	
	cin >> option;
	
	if(option == '1') {
		
		rent();
	}
	else if(option == '2'){
		menu();
	}
	else{
		
		system("cls");
		logo();
		
		cout << "\n\n\t\t" << "Enter your name: ";
		cin >> name;
		
		cout << "\t\t" << "Enter your CNIC: ";
		cin >> cnic;
		
		cout << "\t\t" << "Enter your phone number: ";
		cin >> phone;
		
		
		cout << "\t\t" << "Enter number of days you will rent the car: ";
		
		cin >> days;
		
		total = payment * days;
		
		cars [1][serial] = "Not Available";
		
		bill();
		
	}
}


void bill(){
	
	system ("CLS");
	logo();
	
	// setw() function yaha pe sirf width ko equal rakhne k liye use kia hai - setw() function me interger value hi enter ho gi as its parameter
	
	cout << "\n\n\n\t\t\t\t\t\t" << "Car Rental - Customer Invoice" << endl;
	cout << "\t\t\t\t" << "///////////////////////////////////////////////////" << endl;
	cout << "\t\t\t\t| " << "Name: -------------------------|" << setw(15) << name << " |" <<  endl;
	cout << "\t\t\t\t| " << "CNIC: -------------------------|" << setw(15) << cnic << " |" << endl;
	cout << "\t\t\t\t| " << "Phone: ------------------------|" << setw(15) << phone << " |" << endl;
	cout << "\t\t\t\t| " << "Car: --------------------------|" << setw(15) << cars [0][serial] << " |" << endl;
	cout << "\t\t\t\t| " << "Days: -------------------------|" << setw(15) << days << " |" << endl;
	cout << "\t\t\t\t| " << "Rent: -------------------------|" << setw(10) << "Rs." << payment << " |" << endl;
	cout << "\t\t\t\t" << "___________________________________________________\n\n";
	cout << "\t\t\t\t| " << "Total Rent is: ----------------|" << setw(10) << "Rs." << total << " |" << endl;
	cout << "\t\t\t\t" << "///////////////////////////////////////////////////" << endl;
	cout << "\n\n\t\t\t\t";
	system("pause");
}


void returnCar () {
	
	system("cls");
	logo();
	cout << "\n\n\t\t" << "List of already returnable vehicles: \n";
	

	for (int i = 0; i < 2; i++){
		
		for (int j = 0; j < 5; j++){
			
			if (cars [i][j] == "Not Available"){
				
				cout << "\t\t" << "Serial Number "<< j << " : Car Model: " << cars [i-1][j] << endl;
			}
			
		}
	}
	cout << "\t\t" << "Please enter the serial number of the car you want to return. ";
	cin >> serial;
	

	cars [1][serial] = "Available";
	

	menu();
}


void menu() {
	
	// reference for colors in the program (https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/)
	// system(color [bgcolor][textcolor]) - this is syntax for writing the color function
	
	
	system("color 0C"); // light red color
	
	
	logo();
	cout << endl << endl;
	
	cout << "\t\t" << "Enter 1 - To Rent a Car" << endl;
	cout << "\t\t" << "Enter 2 - To Return a Car" << endl;
	cout << "\t\t" << "Enter 3 - To See All Cars" << endl;
	cout << endl << endl;
	cout << "\t\t" << "Your choice: ";
	
	cin >> option;
	
	switch (option){
		
		case '1':
			system("color 0A"); //  light green color
			rent ();
			cout << "\n\t\t\t\t" << "Back to main menu. ";
			system("pause");
			menu ();
			
			break;
			
		case '2':
			system("color 06"); // yellow color 
			returnCar();
			
			break;
			
		case '3':
			system("color 0B"); // light aqua color
			cout << "\n\n";
			
			
			
			for (int i = 0; i <= 1; i++){
				
				if(i==1) {
					
					break;
				}
				
				for (int j = 0; j <= 4; j++){
					
					cout << "\t\t" << cars [i][j] << " is " << cars [i+1][j] << endl;					
				}
			}
			cout << "\n\n\t\t";
			system ("pause");
			menu ();
			
			break;
			
		default:
			
			system("color 40");
			cout << endl << endl;
			cout << "\t\t" << "Invalid entry, try again. ";
			system("pause");
			system("cls");
			menu();
	}
}


void logo(){
	system ("cls");
	
	// ##################################################   to write backslash - enter two backslashes
	
	
	cout << "\n\t\t" << "----------------------------------------------------------------------------------" << endl;	
	cout << "\t\t" << " _____            ______           _        _   _____           _                 " << endl;
	cout << "\t\t" << "/  __ \\           | ___ \\         | |      | | /  ___|         | |                " << endl;
	cout << "\t\t" << "| /  \\/ __ _ _ __ | |_/ /___ _ __ | |_ __ _| | \\ `--. _   _ ___| |_ ___ _ __ ___  " << endl;
	cout << "\t\t" << "| |    / _` | '__||    // _ \\ '_ \\| __/ _` | |  `--. \\ | | / __| __/ _ \\ '_ ` _ \\ " << endl;
	cout << "\t\t" << "| \\__/\\ (_| | |   | |\\ \\  __/ | | | || (_| | | /\\__/ / |_| \\__ \\ ||  __/ | | | | |" << endl;
	cout << "\t\t" << " \\____/\\__,_|_|   \\_| \\_\\___|_| |_|\\__\\__,_|_| \\____/ \\__, |___/\\__\\___|_| |_| |_|" << endl;
	cout << "\t\t" << "                                                       __/ |                      " << endl;
	cout << "\t\t" << "                                                      |___/                       " << endl;
	cout << "\t\t" << "----------------------------------------------------------------------------------" << endl;

	cout << "\t\t\t\t\t\t\t     " << "Made by Rabia, Muqaddas, Arkam, Arham, Haider, Jawad" << endl;
	
	
	
	
	//   The logo above has been made with the help of this website (https://patorjk.com/software/taag/#p=testall&f=Graffiti&t=Car%20Rental%20System) 
	//   The Font Name is Doom	
	
}

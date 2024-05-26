#include<iostream>
#include<fstream>
using namespace std;
//prototypes
void ADDrecord(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[],string Pastmedicalhistory[], string Diseases[], const string& name, const string& cnic, const string& gender, const string& date, const string& pasthistory, const string& regid, const string& disease, int& patientcount, int maxcapacity);
void Delrecord(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[],string Pastmedicalhistory[], string Diseases[], string& regid, int& patientcount);
void Patientdisplay(string Names[], string Regids[], string Cnics[], string Genders[],string Dates[], string Pastmedicalhistory[], string Diseases[], int& patientcount);
void Searchpatient(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[],string Pastmedicalhistory[], string Diseases[], string& regid, int& patientcount);
void Saverecord(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[], string Pastmedicalhistory[], string Diseases[],const string& filename, int patientcount);
//main function
int main() {
	const int maxcapacity = 100;
	string Names[maxcapacity],Regids[maxcapacity],Cnics[maxcapacity],Genders[maxcapacity],Dates[maxcapacity],Pastmedicalhistory[maxcapacity],Diseases[maxcapacity];
	string name, regid, cnic, gender, date, pasthistory,disease;
	int choice;
	const string filename = "record.txt";
	int patientcount = 0;
	do
	{
		cout<<endl << "<----Medical information system---->" << endl;
		cout << "Menu" << endl << "1)Patient Record entry" << endl << "2)Patient record deletion" << endl << "3)Display all patient records" << endl << "4)Patient record count" << endl<<"5)Search patient record"<<endl<<"6)Save current patients record in a file"<<endl<<"7)exit";
		cout << endl << "Enter your choice  :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl << "Enter patient name :";
			cin >> name;
			cout << endl << "Enter patient cnic :";
			cin >> cnic;
			cout << endl << "Enter patient gender :";
			cin >> gender;
			cout << endl << "Enter patient disease :";
			cin >> disease;
			cout << endl << "Enter patient past medical histories :";
			cin >> pasthistory;
			cout << endl << "Enter patient checkin date :";
			cin >> date;
			cout << endl << "Enter patient reg id :";
			cin >> regid;
			ADDrecord(Names, Regids, Cnics, Genders, Dates, Pastmedicalhistory, Diseases, name, cnic, gender, date, pasthistory, regid, disease, patientcount, maxcapacity);
			break;
		case 2:
			cout << endl << "Enter patient regid :";
			cin >> regid;
			Delrecord(Names, Regids, Cnics, Genders, Dates, Pastmedicalhistory, Diseases, regid, patientcount);
			break;
		case 3:
			Patientdisplay(Names, Regids, Cnics, Genders, Dates, Pastmedicalhistory, Diseases, patientcount);
			break;
		case 4:
			cout<<endl << "There are total :" << patientcount << " in the record as of now ";
			break;
		case 5:
			cout<<endl << "Enter patient reg id to search :";
			cin >> regid;
			Searchpatient(Names, Regids, Cnics, Genders, Dates, Pastmedicalhistory, Diseases, regid, patientcount);
			break;
		case 6:
			Saverecord(Names, Regids, Cnics, Genders, Dates, Pastmedicalhistory, Diseases, filename, patientcount);
			cout << endl << "Patients record saved sucessfully";
			break;
		default:
			cout<<endl << " Invalid choice!!!";
			break;
		}
	} while (choice!=7);
	
}
void ADDrecord(string Names[],string Regids[],string Cnics[],string Genders[],string Dates[],string Pastmedicalhistory[],string Diseases[], const string& name, const string& cnic, const string& gender, const string& date, const string& pasthistory, const string& regid,const string&disease, int& patientcount, int maxcapacity) {
	if (patientcount<maxcapacity)
	{
		Names[patientcount] = name;
		Regids[patientcount] = regid;
		Cnics[patientcount] = cnic;
		Genders[patientcount] = gender;
		Dates[patientcount] = date;
		Pastmedicalhistory[patientcount] = pasthistory;
		Diseases[patientcount] = disease;
		patientcount++;
	}
	else
	{
		cout << "sorry there is no more space in the medical information system";
	}
}
void Delrecord(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[], string Pastmedicalhistory[], string Diseases[],string& regid,int &patientcount){
	bool patientFound = false;
	for (int i = 0; i < patientcount; i++)
	{
		if (regid==Regids[i])
		{
			for (int j = i; j < patientcount-1; j++)
			{
				Names[i] = Names[j+1];
				Regids[i] = Regids[j+1];
				Cnics[i] = Cnics[j+1];
				Genders[i] = Genders[j+1];
				Dates[i] = Dates[j+1];
				Pastmedicalhistory[i] = Pastmedicalhistory[j+1];
				Diseases[i] = Diseases[j+1];
			}
			patientcount--;
			patientFound = true;
			cout<<endl << Names[i] << "  has checked out sucessfully";
			break;
		}
	}
	if (!patientFound) {
		cout<<endl << "Patient with regid :" << regid << "not found";
	}
}
void Patientdisplay(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[], string Pastmedicalhistory[],string Diseases[], int& patientcount) {
	for (int i = 0; i < patientcount; i++)
	{
		cout << endl << "Name :" << Names[i] << "\tCnic :" << Cnics[i] << "\tReg-id :" << Regids[i] << "\tDisease :" << Diseases[i] << endl
			<<"Gender :"<<Genders[i] << "\t Checkin date :" << Dates[i] << "\tPast History :" << Pastmedicalhistory[i];
	}
}
void Searchpatient(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[], string Pastmedicalhistory[], string Diseases[], string& regid, int& patientcount) {
	bool patientfound = false;
	for (int i = 0; i < patientcount; i++)
	{
		if (regid==Regids[i])
		{
			cout << endl << "Name :" << Names[i] << "\tCnic :" << Cnics[i] << "\tReg-id :" << Regids[i] << "\tDisease :" << Diseases[i] << endl
				<< "Gender :" << Genders[i] << "\t Checkin date :" << Dates[i] << "\tpast medical history :" << Pastmedicalhistory[i];
			patientfound = true;
			break;
		}
	}
	if (!patientfound)
	{
		cout<<endl << "Patient with reg id :" << regid << " notfound";
	}
}
void Saverecord(string Names[], string Regids[], string Cnics[], string Genders[], string Dates[], string Pastmedicalhistory[], string Diseases[], const string& filename, int patientcount) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Error: Unable to open file " << filename << endl;
		return;
	}

	for (int i = 0; i < patientcount; i++) {
		file << "Name of patient: " << Names[i] << ", "
			<< "Reg id of patient: " << Regids[i] << ", "
			<< "Gender: " << Genders[i] << ", "
			<< "Checkin date: " << Dates[i] << ", "
			<< "Checkin time: " << Pastmedicalhistory[i] << ", "
			<< "Disease: " << Diseases[i] << endl;
	}

	file.close();
}

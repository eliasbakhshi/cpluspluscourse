#include "functions.hpp";


void variables_datatypes() {
	cout << "\n1. Ge exempel p� 3 primitiva datatyper i C++.";
	cout << "\n2. �r std::string en primitv datatyp ?";
	cout << "\n No";
	cout << "\n3. Vad blir resultatet av 10 / 4 i C++ ? ";
	cout << 10 / 4;
	cout << "\n4. Vad blir resultatet av 12.0 / 5 i C++ ? ";
	cout << 12.0 / 5;
	cout << "5. Vad blir det?";
	cout << "\nA : true || false ?";
	(true || false) ? cout << " Det blir true.\n" : cout << " Det blir false\n";
	cout << "\nB : true && false ?";
	(true && false) ? cout << " Det blir true.\n" : cout << " Det blir false\n";
	cout << "\nC : true && false || true ?";
	(true && false || true) ? cout << " Det blir true.\n" : cout << " Det blir false\n";
	cout << "\n6. Visa tre olika s�tt att �ka inneh�llet i en heltalsvariable med v�rdet 1." << endl;
	int e = 1;
	e = e + 1;
	cout << e << endl;
	e++;
	cout << e << endl;
	e += 1;
	cout << e << endl;
	cout << "\n7. Kan man omvandla(type cast) ett heltal till ett flyttal i C++ ?";
	// The type changes but the value shows as a int in the console.
	int heltal = 2;
	cout << "\nthe type is : " << typeid(static_cast<float>(heltal)).name() << endl;
	cout << "\nthe value is : " << static_cast<float>(heltal) << endl;


	cout << "\n8. Vad blir resultatet av static_cast<int>(5.78) (alternativt(int)5.78) ?";
	// B�da �r 5
	cout << endl << static_cast<int>(5.78) << endl;
	cout << (int)5.78 << endl;

	cout << "\n9. Vad kommer str inneh�lla efter std::string str; ?";
	std::string str;
	cout << endl << str;
	cout << "\n10. Vad betyder !(utropstecken) ?";
	// Det betyder tv�rtom
	cout << "\n11. Hur skriver man f�r att avg�ra om str�ngen i variablen str1 �r densamma som str�ngen i variablen str2 ?";
	// Med string::compare() eller ===

	cout << "\n12. Hur skriver man om man ska skapa en str�ng som ska inneh�lla ett visst best�mt antal f�rekomster av ett visst tecken, d�r tecknet finns i variablen char c och antalet finns i variablen int nrOf ? Om ex - vis nrOf inneh�ller 7 och nrOf ineh�ller 'F', ska det resultera i str�ngen \"FFFFFFF\"";
	cout << endl << std::string(7, 'F') << endl;
	cout << "\n13. Om rand() ger ett heltal som �r 0 eller st�rre.Hur kan du d� skriva f�r att f� ett heltal inom intervallet";
	cout << "\nA : [0..20]";
	int intervalStart = 0;
	int intervalEnd = 20;
	cout << endl << intervalStart + (rand() % (intervalEnd - intervalStart + 1));	
	cout << "\nB : [10..20]";
	intervalStart = 10;
	intervalEnd = 20;
	cout << endl << intervalStart + (rand() % (intervalEnd - intervalStart + 1));	
	cout << "\nC : [-10..10]";
	intervalStart = -10;
	intervalEnd = 10;
	cout << endl << intervalStart + (rand() % (intervalEnd - intervalStart + 1));

	cout << "\n14. Anv�ndaren ska mata in en str�ng som motsvarar ett registreringsnummer och som omfattar exakt 6 tecken(ex - vis ABR129).Hur skriver du f�r att inmatningen ska ske till variabeln ? Du kan anta att variabelnamnet �r regNr.";
	string regNr;
	getline(cin, regNr);

	cout << "\n15. Anv�ndaren ska mata in en str�ng som motsvarar en gatuadress vilken omfattar b�de gatans namn och nummer(ex - vis Prinsgatan 45).Hur skriver du f�r att inmatningen ska ske till variabeln ? Du kan anta att variabelnamnet �r address.";
	string address;
	getline(cin, address);

	cout << "\n16. Vad �r det f�r problem med f�ljande kodavsnitt ?";
	// Det ska tommas cin minne innan getline() ska k�ras annars sparas en tom str�ng i name variabeln.

	/*string name;
	int year;
	std::cout << "Birth year: "; 
	cin >> year;
	std::cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	std::cout << name << " was born in " << year << std::endl;*/
	
	cout << "\n17. Vad blir det f�r utskrift n�r f�ljande kodavsnitt exekveras ?";
	// Det blir "6 6"
	/*int i = 5;
	int k = i++;
	int m = ++k;
	std::cout << k << " " << m << std::endl;*/
	
	cout << "\n18. Vad blir det f�r utskrifter n�r f�ljande kodavsnitt exekveras ?";
	// Det blir "22 22.5"
	/*int i = 10;
	float f = 12.5f;
	int res = f + i;
	cout << "rrr\n";
	std::cout << res << " " << i + f << std::endl;*/

	//cout << "\n\n\nProgrammeringsuppgifter";

	cout << "\n1. Best�m totala antalet sekunder f�r 50 minuter och 25 sekunder.";
	int mins = 50;
	int secs = 25;
	const int sekPerMin = 60;
	cout << endl << "50 minuter och 25 sekunder �r : " << (mins * sekPerMin) + secs << " sekunder.";

	cout << "\n2. Best�m hur m�nga miles 15 km motsvarar. (1 mile �r 1.609344 km)";
	int kms = 15;
	const double kmPerMile = 1.609344;
	cout << endl << kms << " km is : " << (kms / kmPerMile) << "miles.";

	cout << "\n3. L�t anv�ndaren mata in 2 heltal och ber�kna och presentera produkten(multiplikation) av talen.Ex.inmatning av 6 och 4 ger resultatet 24";
	float num1 = 6;
	float num2 = 4;
	cout << endl << "6 * 4 ger resultatet " << num1 * num2;

	cout << "\n4. L�t anv�ndaren mata in 2 heltal och ber�kna och presentera kvoten(division) av talen.Ex inmatning av 10 och 4 ger resultatet 2.5";

	num1 = 10;
	num2 = 4;
	cout << endl << "10 / 4 ger resultatet  " << num1 / num2;

	cout << "\n5. L�t anv�ndaren mata in ett heltal och avg�r om heltalet �r j�mnt delbart med 7.";
	int theInput;
	cin >> theInput;
	theInput % 7 == 0 ? cout << theInput << " �r delbar med 7." : cout << theInput << " �r inte delbar med 7: ";

	cout << "\n6. Anv�ndaren matar in en starttid  och en m�lg�ngstid i timmar minuter och sekunder och programmet presenterar tiden det tog f�r att genomf�ra loppet i timmar, minuter och sekunder.Ex";
	//cout << "\nYour race time is : 1 hour 41 minutes 42 seconds";
	int startHour, startMin, startSec, goalHour, goalMin, goalSec, hours, minutes, seconds;
	// Get the start time.
	cout << "\nStart\n";
	cout << "\nHour : ";
	cin >> startHour;
	cout << "Minute : ";
	cin >> startMin;
	cout << "Second : ";
	cin >> startSec;
	// Get the goal time.
	cout << "Goal";
	cout << "Hour : ";
	cin >> goalHour;
	cout << "Minute : ";
	cin >> goalMin;
	cout << "Second : ";
	cin >> goalSec;

	// convert the all times to seconds and calculate the difference.
	startSec = (startHour * 60 * 60) + (startMin * 60) + startSec;
	goalSec = (goalHour * 60 * 60) + (goalMin * 60) + goalSec;
	seconds = goalSec - startSec;
	
	minutes = seconds / 60;
	hours = minutes / 60;

	cout << endl;
	cout << "Your race time is : " << int(hours) << " hours " << int(minutes % 60)
		<< " minutes " << int(seconds % 60) << " seconds.";


	
	cout << "\n7. G�r ett program enligt f�ljande 3 olika scenarier";
	cout << "\nLast name : Smith";
	cout << "\nFirst name : Caroline";
	cout << "\nHello, Caroline Smith!Your last name contains more letters than your first name.";
	cout << "\n************************";
	cout << "\nLast name : Smith";
	cout << "\nFirst name : Carol";
	cout << "\nHello, Carol Smith!Your last name contains the same amount of letters as your first name.";
	cout << "\n************************";
	cout << "\nLast name : Smith";
	cout << "\nFirst name : Carol Ann";
	cout << "\nHello, Carol Ann Smith!Your first name contains more letters than your last name.";

	string firstName, lastname;
	cout << endl;
	cout << "First name: ";
	cin.ignore();
	getline(cin, firstName);
	cout << "Last name: ";
	getline(cin, lastname);

	if (firstName.length() < lastname.length()) {
		cout << firstName << " " << lastname << "! Your last name contains more letters than your first name.";
	}else if (firstName.length() > lastname.length()) {
		cout << firstName << " " << lastname << "! Your first name contains more letters than your last name.";
	}else if (firstName.length() == lastname.length()) {
		cout << firstName << " " << lastname << "! Your last name contains the same amount of letters as your first name.";
	}

	cout << "\n8. L�t anv�ndaren mata in text.Best�m hur m�nga tecken som finns f�re f�rsta f�rekomsten av blank(mellanslag).Ex om  anv�ndaren matar in Hejsan svejsan idag!ska resultatet bli att det finns 6 tecken f�re f�rsta blanka.";

	string sentence = "Hejsan svejsan idag!";
	cout << sentence.find(" ");


}
#include "functions.hpp";


void variables_datatypes() {
	cout << "\n1. Ge exempel på 3 primitiva datatyper i C++.";
	cout << "\n2. Är std::string en primitv datatyp ?";
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
	cout << "\n6. Visa tre olika sätt att öka innehållet i en heltalsvariable med värdet 1." << endl;
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
	// Båda är 5
	cout << endl << static_cast<int>(5.78) << endl;
	cout << (int)5.78 << endl;

	cout << "\n9. Vad kommer str innehålla efter std::string str; ?";
	std::string str;
	cout << endl << str;
	cout << "\n10. Vad betyder !(utropstecken) ?";
	// Det betyder tvärtom
	cout << "\n11. Hur skriver man för att avgöra om strängen i variablen str1 är densamma som strängen i variablen str2 ?";
	// Med string::compare() eller ===

	cout << "\n12. Hur skriver man om man ska skapa en sträng som ska innehålla ett visst bestämt antal förekomster av ett visst tecken, där tecknet finns i variablen char c och antalet finns i variablen int nrOf ? Om ex - vis nrOf innehåller 7 och nrOf inehåller 'F', ska det resultera i strängen \"FFFFFFF\"";
	cout << endl << std::string(7, 'F') << endl;
	cout << "\n13. Om rand() ger ett heltal som är 0 eller större.Hur kan du då skriva för att få ett heltal inom intervallet";
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

	cout << "\n14. Användaren ska mata in en sträng som motsvarar ett registreringsnummer och som omfattar exakt 6 tecken(ex - vis ABR129).Hur skriver du för att inmatningen ska ske till variabeln ? Du kan anta att variabelnamnet är regNr.";
	string regNr;
	getline(cin, regNr);

	cout << "\n15. Användaren ska mata in en sträng som motsvarar en gatuadress vilken omfattar både gatans namn och nummer(ex - vis Prinsgatan 45).Hur skriver du för att inmatningen ska ske till variabeln ? Du kan anta att variabelnamnet är address.";
	string address;
	getline(cin, address);

	cout << "\n16. Vad är det för problem med följande kodavsnitt ?";
	// Det ska tommas cin minne innan getline() ska köras annars sparas en tom sträng i name variabeln.

	/*string name;
	int year;
	std::cout << "Birth year: "; 
	cin >> year;
	std::cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	std::cout << name << " was born in " << year << std::endl;*/
	
	cout << "\n17. Vad blir det för utskrift när följande kodavsnitt exekveras ?";
	// Det blir "6 6"
	/*int i = 5;
	int k = i++;
	int m = ++k;
	std::cout << k << " " << m << std::endl;*/
	
	cout << "\n18. Vad blir det för utskrifter när följande kodavsnitt exekveras ?";
	// Det blir "22 22.5"
	/*int i = 10;
	float f = 12.5f;
	int res = f + i;
	cout << "rrr\n";
	std::cout << res << " " << i + f << std::endl;*/

	//cout << "\n\n\nProgrammeringsuppgifter";

	cout << "\n1. Bestäm totala antalet sekunder för 50 minuter och 25 sekunder.";
	int mins = 50;
	int secs = 25;
	const int sekPerMin = 60;
	cout << endl << "50 minuter och 25 sekunder är : " << (mins * sekPerMin) + secs << " sekunder.";

	cout << "\n2. Bestäm hur många miles 15 km motsvarar. (1 mile är 1.609344 km)";
	int kms = 15;
	const double kmPerMile = 1.609344;
	cout << endl << kms << " km is : " << (kms / kmPerMile) << "miles.";

	cout << "\n3. Låt användaren mata in 2 heltal och beräkna och presentera produkten(multiplikation) av talen.Ex.inmatning av 6 och 4 ger resultatet 24";
	float num1 = 6;
	float num2 = 4;
	cout << endl << "6 * 4 ger resultatet " << num1 * num2;

	cout << "\n4. Låt användaren mata in 2 heltal och beräkna och presentera kvoten(division) av talen.Ex inmatning av 10 och 4 ger resultatet 2.5";

	num1 = 10;
	num2 = 4;
	cout << endl << "10 / 4 ger resultatet  " << num1 / num2;

	cout << "\n5. Låt användaren mata in ett heltal och avgör om heltalet är jämnt delbart med 7.";
	int theInput;
	cin >> theInput;
	theInput % 7 == 0 ? cout << theInput << " är delbar med 7." : cout << theInput << " är inte delbar med 7: ";

	cout << "\n6. Användaren matar in en starttid  och en målgångstid i timmar minuter och sekunder och programmet presenterar tiden det tog för att genomföra loppet i timmar, minuter och sekunder.Ex";
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


	
	cout << "\n7. Gör ett program enligt följande 3 olika scenarier";
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

	cout << "\n8. Låt användaren mata in text.Bestäm hur många tecken som finns före första förekomsten av blank(mellanslag).Ex om  användaren matar in Hejsan svejsan idag!ska resultatet bli att det finns 6 tecken före första blanka.";

	string sentence = "Hejsan svejsan idag!";
	cout << sentence.find(" ");


}
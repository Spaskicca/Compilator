#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> jednocifreni_srpski = { "", "jedan", "dva", "tri", "cetiri", "pet", "sest", "sedam", "osam", "devet" };
vector<string> jednocifreni_bugarski = { "", "edno", "dve", "tri", "cetiri", "pet", "sest", "sedem", "osem", "devet" };
vector<string> jednocifreni_engleski = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

vector<string> deset_do_devetnaest_srpski = { "deset", "jedanaest", "dvanaest", "trinaest", "cetrnaest", "petnaest", "šesnaest", "sedamnaest", "osamnest", "devetnaest" };
vector<string> deset_do_devetnaest_bugarski = { "deset", "edinadeset", "dvanadeset", "trinadeset", "cetirinadeset", "petnadeset", "sesnadeset", "sedemnadeset", "osemnadeset", "devetnadeset" };
vector<string> deset_do_devetnaest_engleski = { "ten", "eleven", "twelve","Thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };

vector<string> desetice_srpski = { "", "", "dvadeset", "trideset", "cetrdeset", "pedeset", "sezdeset", "sedamdeset", "osamdeset", "devedeset" };
vector<string> desetice_bugarski = { "", "", "dvadeset", "trideset", "cetirideset", "petdeset", "sesdeset", "sedemdeset", "osemdeset", "devetdeset" };
vector<string> desetice_engleski = { "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };

vector<string> stotine_srpski = { "", "sto", "dvesta", "trista", "cetiristo", "petsto", "ceststo", "sedamsto", "osamsto", "devetsto" };
vector<string> stotine_bugarski = { "", "sto", "dvesta", "trista", "cetiristotin", "petstotin", "sestotin", "sedemstotin", "osemstotin", "devetstotin" };
vector<string> stotine_engleski={ "","One Hundred","Two hundred","Three hundred","Four hundred","Five hundred","Six hundred","Seven hundred","Eight hundred","Nine hundred" };

vector<string> bigNumbers_srpski = { "hiljada","hiljade","jedan", "milion","miliona","jedna","milijarda","milijardi"};
vector<string> bigNumbers_bugarski = { "hilqda","hilqdi","edin","milion","milioni","edin","miliqrd","miliqrdi"};
vector<string> bigNumbers_engleski = { "thousand","thousand","one","milion","milion","one","billion","billion" };

string brojUReci(int broj, string jezik) {
    if (broj < 0) {
        cout << "minus ";
        broj = -broj;
    }

    vector<string> jednocifreni = (jezik == "srb") ? jednocifreni_srpski : (jezik == "bg") ? jednocifreni_bugarski : jednocifreni_engleski;
    vector<string> deset_do_devetnaest = (jezik == "srb") ? deset_do_devetnaest_srpski : (jezik == "bg") ? deset_do_devetnaest_bugarski : deset_do_devetnaest_engleski;
    vector<string> desetice = (jezik == "srb") ? desetice_srpski : (jezik == "bg") ? desetice_bugarski : desetice_engleski;
    vector<string> stotine = (jezik == "srb") ? stotine_srpski : (jezik == "bg") ? stotine_srpski : stotine_engleski;
    vector<string> bigNumbers = (jezik == "srb") ? bigNumbers_srpski : (jezik == "bg") ? bigNumbers_bugarski : bigNumbers_engleski;
 

    if (broj == 0) {
        cout << jednocifreni[0] << endl;
        return "";
    }


    std::string rezultat = "";

    if (broj / 1000000000 > 0) {
        if (broj / 1000000000 == 1)
            rezultat += bigNumbers[5] + " " + bigNumbers[6] += " ";
        else
            rezultat += brojUReci(broj / 1000000000, jezik) + " " + bigNumbers[7] + " ";

        rezultat += brojUReci(broj %= 1000000000, jezik);

        return rezultat;
    }

    if (broj / 1000000 > 0) {
        if (broj / 1000000 == 1)
            rezultat += bigNumbers[2] +" "+ bigNumbers[3] += " ";
        else
            rezultat += brojUReci(broj / 1000000, jezik) + " " + bigNumbers[4] + " ";

        rezultat += brojUReci(broj %= 1000000, jezik);
        return rezultat;
    }

    if (broj / 1000 > 0) {
        if (broj / 1000 == 1)
            rezultat += bigNumbers[0] +=" ";
        else 
            rezultat += brojUReci(broj / 1000, jezik) + " "+ bigNumbers [1]+ " ";

        rezultat+=brojUReci( broj %= 1000,jezik);
        return rezultat;

    }

    if (broj / 100 > 0) {
        rezultat += stotine[broj / 100] + " ";
        broj %= 100;
    }

    if (broj >= 10 && broj <= 19) {
        rezultat += deset_do_devetnaest[broj - 10] + " ";
    }
    else {
        if (broj / 10 > 0) {
            rezultat += desetice[broj / 10] + " ";
        }
        if (broj % 10 > 0) {
            rezultat += jednocifreni[broj % 10] ;
        }
    }

    return rezultat;
}
bool isThisNumber(string input)  { 
    string acceptableChars = "0123456789.";
    for (int i = 0; i < input.length(); i++)
    {
        if (acceptableChars.find(input.substr(i, 1)) == string::npos)
            return false;
    }
    return true;
}

int main() {
    string broj;
    string jezik;

    cout << "Unesite broj: ";
    cin >> broj;
    if (!isThisNumber(broj)) {
        cout << "Bad input data";

        return 0;
    }
        
    int value = atoi(broj.c_str());
    cout << "Izaberite jezik (srb/bg/en): ";
    cin >> jezik;

    if (value > 10000000000 || value < -100000) {
        if (jezik == "srb") {
            cout << "Broj je izvan opsega" << endl;
        }
        else if (jezik == "bg") {
            cout << "Брой е извън обхвата" << endl; 
        }
        else {
            cout << "Number is out of range" << endl;
        }
        return 0;
    }

    cout << brojUReci(value, jezik) << endl;

    return 0;
}
#include <iostream>
#include  "headerFiles/Date.hpp"
#include  "headerFiles/Prescription.hpp"
#include <fstream>
#include <sstream>

int main(){
    json data;
    Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, std::vector<Medication>());
    test_prescription.addMedicationRecord(Medication("Apap", 130, 2650));
    test_prescription.addMedicationRecord(Medication("Ibuprofen", 360, 1024));
    std::ofstream foo("../jsonFiles/Prescription.json");
    data = test_prescription.returnPrescriptionJson();
    foo << std::setw(4) << data << std::endl;
    foo.close();

    std::vector<Prescription> prescList{test_prescription};
    prescList.push_back(Prescription(346, Date(25, Months(2), 2004), Doctor{"Julian", "Nowak"}, Patient{"Nikodem", "Kowalski", 987654321}, std::vector<Medication>{Medication("Apap", 200, 400), Medication("Ibuprofen", 400, 2048)}));
    prescList.push_back(Prescription(347, Date(25, Months(2), 2004), Doctor{"Michal", "Wisniewski"}, Patient{"Jakub", "Wojcik", 987654321}, std::vector<Medication>{Medication("Rutinoscorbin", 100, 1000), Medication("Vitamn D", 500, 500)}));
    writePrescriptionListJson(Pharmacist{"Anna", "Kowalczyk", Time(0, 1, 30)}, Date(31, Months(12), 2004), Time(23, 59, 0), prescList, std::ofstream("../jsonFiles/PrescriptionList.json"));
}
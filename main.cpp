#include <iostream>
#include  "headerFiles/Date.hpp"
#include  "headerFiles/Prescription.hpp"
#include <fstream>


int main(){
    json test;
    test["test"] = "test";
    Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, std::vector<Medication>());
    test_prescription.addMedicationRecord(Medication("Apap", 130, 2650));
    test_prescription.addMedicationRecord(Medication("Ibuprofen", 360, 1024));
    test["prescription"] = test_prescription.returnPrescriptionJson();
    std::ofstream o("../jsonFiles/Prescription.json");
    o << std::setw(4) << test << std::endl;
}
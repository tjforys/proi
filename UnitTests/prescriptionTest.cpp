#include "gtest/gtest.h"
#include "../headerFiles/Prescription.hpp"

using std::invalid_argument;
using std::vector;
TEST(medicationTest, invalidInitTest){
    EXPECT_THROW({
       Medication test_med = Medication("Example Drug", 1000, -50);
    }, invalid_argument);
    EXPECT_THROW({
       Medication test_med = Medication("Example Drug", -1000, 50);
    }, invalid_argument);
}

TEST(medicationTest, initGetterTest){
    Medication test_med = Medication("Example Drug", 1000, 699);
    EXPECT_EQ("Example Drug", test_med.getName());
    EXPECT_EQ(1000, test_med.getActiveSubstaneContent());
    EXPECT_EQ(699, test_med.getPriceInGr());
}

TEST(medicationTest, singularSetterTest){
    Medication test_med = Medication("Example Drug", 1000, 699);
    test_med.setName("Example Drug 2");
    test_med.setActiveSubstanceContent(500);
    test_med.setPriceInGr(999);
    EXPECT_EQ("Example Drug 2", test_med.getName());
    EXPECT_EQ(500, test_med.getActiveSubstaneContent());
    EXPECT_EQ(999, test_med.getPriceInGr());
}

TEST(medicationTest, fullSetterTest){
    Medication test_med = Medication("Example Drug", 1000, 699);
    test_med.setMedication("Example Drug 3", 600, 299);
    EXPECT_EQ("Example Drug 3", test_med.getName());
    EXPECT_EQ(600, test_med.getActiveSubstaneContent());
    EXPECT_EQ(299, test_med.getPriceInGr());
}

TEST(medicationTest, invalidSetterTest){
    EXPECT_THROW({
       Medication test_med = Medication("Example Drug", 1000, 50);
       test_med.setActiveSubstanceContent(-100);
    }, invalid_argument);
    EXPECT_THROW({
       Medication test_med = Medication("Example Drug", 1000, 50);
       test_med.setPriceInGr(-300);
    }, invalid_argument);
}

TEST(prescriptionTest, invalidInitTest){
    EXPECT_THROW({
       Prescription test_prescription = Prescription(-345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, vector<Medication>());
    }, invalid_argument);
    EXPECT_THROW({
       Prescription test_prescription = Prescription(345, Date(-25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, vector<Medication>());
    }, invalid_argument);
    EXPECT_THROW({
       Prescription test_prescription = Prescription(345, Date(25, Months(2), -2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, vector<Medication>());
    }, invalid_argument);
    EXPECT_THROW({
       Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", -123456789}, vector<Medication>());
    }, invalid_argument);
    EXPECT_THROW({
       Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 1234567}, vector<Medication>());
    }, invalid_argument);
}

TEST(prescriptionTest, initGettersTest){
    Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, vector<Medication>());    
    EXPECT_EQ(345, test_prescription.getPrescriptionNumber());
    EXPECT_EQ(Date(25, Months(2), 2004), test_prescription.getIssueDate());
    EXPECT_EQ("Jan", test_prescription.getDoctor().doctorName);
    EXPECT_EQ("Kowalski", test_prescription.getDoctor().doctorSurname);
    EXPECT_EQ("Jacek", test_prescription.getPatient().patientName);    
    EXPECT_EQ("Nowak", test_prescription.getPatient().patientSurname);
    EXPECT_EQ(123456789, test_prescription.getPatient().patientPesel);
    EXPECT_EQ(vector<Medication>{}, test_prescription.getMedicationList());
}

TEST(prescriptionTest, singleSetterTest){
    Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 987654321}, vector<Medication>());    
    test_prescription.setPrescriptionNumber(500);
    test_prescription.setIssueDate(Date(20, Months(3), 2006));
    test_prescription.setDoctorName("Jacek");
    test_prescription.setPatientName("Jan");
    test_prescription.setPatientPESELNumber(987654321);
    test_prescription.setMedicationList(vector<Medication>{Medication("ex", 10, 30)});
    EXPECT_EQ(500, test_prescription.getPrescriptionNumber());
    EXPECT_EQ(Date(20, Months(3), 2006), test_prescription.getIssueDate());
    EXPECT_EQ("Jacek", test_prescription.getDoctor().doctorName);
    EXPECT_EQ("Kowalski", test_prescription.getDoctor().doctorSurname);
    EXPECT_EQ("Jan", test_prescription.getPatient().patientName);    
    EXPECT_EQ("Nowak", test_prescription.getPatient().patientSurname);
    EXPECT_EQ(987654321, test_prescription.getPatient().patientPesel);
    EXPECT_EQ(vector<Medication>{Medication("ex", 10, 30)}, test_prescription.getMedicationList());
    }

TEST(prescriptionTest, fullSetterTest){
    Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, vector<Medication>());    
    test_prescription.setPrescription(500, Date(20, Months(3), 2006), Doctor{"Jacek", "Kowalski"}, Patient{"Jan", "Nowak", 987654321}, vector<Medication>{Medication("ex", 10, 30)});
    EXPECT_EQ(500, test_prescription.getPrescriptionNumber());
    EXPECT_EQ(Date(20, Months(3), 2006), test_prescription.getIssueDate());
    EXPECT_EQ("Jacek", test_prescription.getDoctor().doctorName);
    EXPECT_EQ("Kowalski", test_prescription.getDoctor().doctorSurname);
    EXPECT_EQ("Jan", test_prescription.getPatient().patientName);    
    EXPECT_EQ("Nowak", test_prescription.getPatient().patientSurname);
    EXPECT_EQ(987654321, test_prescription.getPatient().patientPesel);
    EXPECT_EQ(vector<Medication>{Medication("ex", 10, 30)}, test_prescription.getMedicationList());
}

TEST(prescriptionTest, addRecordTest){
    Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, vector<Medication>{Medication("Apap", 200, 300)});    
    test_prescription.addMedicationRecord(Medication("Ibuprofen", 100, 1000));
    bool check_equal = vector<Medication>{Medication("Apap", 200, 300), Medication("Ibuprofen", 100, 1000)} == test_prescription.getMedicationList();
    EXPECT_TRUE(check_equal);
}

TEST(prescriptionTest, removeRecordTest){
    Prescription test_prescription = Prescription(345,
    Date(25, Months(2), 2004),
    Doctor{"Jan",
    "Kowalski"},
    Patient{"Jacek",
    "Nowak",
    123456789},
    vector<Medication>{Medication("Apap", 200, 300), Medication("Ibuprofen", 100, 1000)});    
    test_prescription.removeMedicationRecord(1);
    EXPECT_EQ(vector<Medication>{Medication("Apap", 200, 300)}, test_prescription.getMedicationList());
    test_prescription.removeMedicationRecord(0);
    EXPECT_EQ(vector<Medication>{}, test_prescription.getMedicationList());
}


TEST(prescriptionTest, returnJsonTest){
    Prescription test_prescription = Prescription(345, Date(25, Months(2), 2004), Doctor{"Jan", "Kowalski"}, Patient{"Jacek", "Nowak", 123456789}, std::vector<Medication>{Medication("Apap", 130, 2650)});
    json data = test_prescription.returnPrescriptionJson();
    EXPECT_EQ(data["issueDate"], "25/2/2004");
    EXPECT_EQ(data["doctor"]["name"], "Jan");
    EXPECT_EQ(data["doctor"]["surname"], "Kowalski");    
    EXPECT_EQ(data["patient"]["name"], "Jacek");
    EXPECT_EQ(data["patient"]["surname"], "Nowak");
    EXPECT_EQ(data["patient"]["pesel"], 123456789);    
    EXPECT_EQ(data["medicationList"][0]["name"], "Apap");  
    EXPECT_EQ(data["medicationList"][0]["priceInGr"], 2650);
    EXPECT_EQ(data["medicationList"][0]["activeSubstanceContent"], 130);
    EXPECT_EQ(data["prescriptionNumber"], 345);
}

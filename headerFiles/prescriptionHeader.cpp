#include "prescriptionHeader.hpp"
#include "dateHeader.hpp"
#include <iostream>

//Medication class
Medication::Medication(string medName, int subContent, int price){
    name = medName;
    if (subContent<0){
        throw std::invalid_argument("negative substance content value");
    }
    else active_substance_content = subContent;
    if (price<0){
        throw std::invalid_argument("negative price value");
    }
    else price_in_gr = price;
}  


string Medication::getName() const{
    return name;
}


unsigned int Medication::getActiveSubstaneContent() const{
    return active_substance_content;
}


unsigned int Medication::getPriceInGr() const{
    return price_in_gr;
}


void Medication::setName(string newName){
    name = newName; 
}


void Medication::setActiveSubstanceContent(int newContent){
    if (newContent<0){
        throw std::invalid_argument("negative substance content value while setting");
    }
    else active_substance_content = newContent;
}


void Medication::setPriceInGr(int newPrice){
    if (newPrice<0){
        throw std::invalid_argument("negative price value while setting");
    }
    else price_in_gr = newPrice;
} 


void Medication::setMedication(string newName, int newContent, int newPrice){
    name = newName;
    if (newContent<0){
        throw std::invalid_argument("negative substance content value while setting");
    }
    else active_substance_content = newContent;
    if (newPrice<0){
        throw std::invalid_argument("negative price value while setting");
    }
    else price_in_gr = newPrice;
}


//Prescription class
Prescription::Prescription(
    int prescNumber,
    Date issDate, 
    string docName, 
    string docSurname, 
    string patName,
    string patSurname,
    int pesel, 
    vector<Medication> newList)
    {
    setPrescription(
    prescNumber,
    issDate, 
    docName, 
    docSurname, 
    patName,
    patSurname,
    pesel, 
    newList);
}


unsigned int Prescription::getPrescriptionNumber() const{
    return prescriptionNumber;
}


Date Prescription::getIssueDate() const{
    return issueDate;
}


string Prescription::getDoctorName() const{
    return doctorName;
}


string Prescription::getDoctorSurname() const{
    return doctorSurname;
}

    
string Prescription::getPatientName() const{
    return patientName;
}

   
string Prescription::getPatientSurname() const{
    return patientSurname;
}

    
unsigned int Prescription::getPatientPESELNumber() const{
    return patientPESELNumber;
}


vector<Medication> Prescription::getMedicationList() const{
    return medicationList;
}


void Prescription::setPrescriptionNumber(int newNumber){
    if (newNumber<0) throw std::invalid_argument("negative prescription number");
    else prescriptionNumber = newNumber;
}


void Prescription::setIssueDate(Date newDate){
    issueDate = newDate;
}


void Prescription::setDoctorName(string newName){
    doctorName = newName;
}


void Prescription::setDoctorSurname(string newSurname){
    doctorSurname = newSurname;
}


void Prescription::setPatientName(string newName){
    patientName = newName;
}


void Prescription::setPatientSurname(string newSurname){
    patientSurname = newSurname;
}


void Prescription::setPatientPESELNumber(int newPesel){
    if (newPesel<0 or std::to_string(newPesel).size()!=9) throw std::invalid_argument("invalid pesel");
        else patientPESELNumber =newPesel;
}


void Prescription::setMedicationList(vector<Medication> newList){
    medicationList = newList;
}


void Prescription::setPrescription(
    int prescNumber,
    Date issDate, 
    string docName, 
    string docSurname, 
    string patName,
    string patSurname,
    int pesel, 
    vector<Medication> newList)
    {
    setPrescriptionNumber(prescNumber);
    setIssueDate(issDate);
    setDoctorName(docName);
    setDoctorSurname(docSurname);
    setPatientName(patName);
    setPatientSurname(patSurname);
    setPatientPESELNumber(pesel);
    setMedicationList(newList);
}


void Prescription::addMedicationRecord(Medication newMedication){
    medicationList.push_back(newMedication);
}


void Prescription::removeMedicationRecord(int index){
    medicationList.erase(medicationList.begin()+index);
}

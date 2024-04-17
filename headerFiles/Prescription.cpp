#include "Prescription.hpp"
#include "Date.hpp"
#include <iostream>
#include <stdexcept>
#include <map>
//Medication class
Medication::Medication(std::string medName, int subContent, int price){
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


std::string Medication::getName() const{
    return name;
}


unsigned int Medication::getActiveSubstaneContent() const{
    return active_substance_content;
}


unsigned int Medication::getPriceInGr() const{
    return price_in_gr;
}


void Medication::setName(std::string newName){
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


void Medication::setMedication(std::string newName, int newContent, int newPrice){
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
    Doctor doc,
    Patient pat, 
    std::vector<Medication> newList)
    {
    setPrescription(
    prescNumber,
    issDate, 
    doc,
    pat,
    newList);
}


unsigned int Prescription::getPrescriptionNumber() const{
    return prescriptionNumber;
}


Date Prescription::getIssueDate() const{
    return issueDate;
}


Doctor Prescription::getDoctor() const{
    return doctor;
}

    
Patient Prescription::getPatient() const{
    return patient;
}


std::vector<Medication> Prescription::getMedicationList() const{
    return medicationList;
}


void Prescription::setPrescriptionNumber(int newNumber){
    if (newNumber<0) throw std::invalid_argument("negative prescription number");
    else prescriptionNumber = newNumber;
}


void Prescription::setIssueDate(Date newDate){
    issueDate = newDate;
}


void Prescription::setDoctorName(std::string newName){
    doctor.doctorName = newName;
}


void Prescription::setDoctorSurname(std::string newSurname){
    doctor.doctorSurname = newSurname;
}


void Prescription::setPatientName(std::string newName){
    patient.patientName = newName;
}


void Prescription::setPatientSurname(std::string newSurname){
    patient.patientSurname = newSurname;
}


void Prescription::setPatientPESELNumber(int newPesel){
    if (newPesel<0 or std::to_string(newPesel).size()!=9) throw std::invalid_argument("invalid pesel");
        else patient.patientPesel = newPesel;
}


void Prescription::setMedicationList(std::vector<Medication> newList){
    medicationList = newList;
}


void Prescription::setPrescription(
    int prescNumber,
    Date issDate, 
    Doctor doc, 
    Patient pat, 
    std::vector<Medication> newList)
    {
    setPrescriptionNumber(prescNumber);
    setIssueDate(issDate);
    setDoctorName(doc.doctorName);
    setDoctorSurname(doc.doctorSurname);
    setPatientName(pat.patientName);
    setPatientSurname(pat.patientSurname);
    setPatientPESELNumber(pat.patientPesel);
    setMedicationList(newList);
}


void Prescription::addMedicationRecord(Medication newMedication){
    medicationList.push_back(newMedication);
}


void Prescription::removeMedicationRecord(int index){
    medicationList.erase(medicationList.begin()+index);
}


json Prescription::returnPrescriptionJson(){
    json data;
    data["prescriptionNumber"] = prescriptionNumber;
    data["doctor"] = json{{"name", doctor.doctorName}, {"surname", doctor.doctorSurname}};
    data["patient"] = json{{"name", patient.patientName},{"surname", patient.patientSurname}, {"pesel", patient.patientPesel}};
    data["medicationList"] = json::array();
    for(auto x: medicationList){
        data["medicationList"].push_back(json{{"name", x.getName()},
         {"activeSubstanceContent", x.getActiveSubstaneContent()},
         {"priceInGr", x.getPriceInGr()}});
    }
    return data;
}
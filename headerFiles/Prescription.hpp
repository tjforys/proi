#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Date.hpp"



class Medication{
    std::string name;
    unsigned int active_substance_content;
    unsigned int price_in_gr;
public:
    Medication(std::string, int, int);
    //getters
    std::string getName() const;
    unsigned int getActiveSubstaneContent() const;
    unsigned int getPriceInGr() const;
    //setters
    void setName(std::string);
    void setActiveSubstanceContent(int);
    void setPriceInGr(int);
    void setMedication(std::string, int ,int);
    
friend bool operator==(const Medication& lhs, const Medication& rhs){
    return (lhs.name == rhs.name and lhs.active_substance_content == rhs.active_substance_content and lhs.price_in_gr == rhs.price_in_gr);
}
};

struct Patient{
    std::string patientName;
    std::string patientSurname;
    unsigned int patientPesel;
    public:
    Patient(std::string name, std::string surname, int pesel){
        patientName = name;
        patientSurname = surname;
        if (pesel >= 0) patientPesel = pesel;
        else throw std::invalid_argument("negative pesel");
    }
    Patient(){}
};

struct Doctor{
    std::string doctorName;
    std::string doctorSurname;
};

class Prescription{
    unsigned int prescriptionNumber;
    Date issueDate;
    Doctor doctor;
    Patient patient;
    std::vector <Medication> medicationList;
public:
    Prescription(int, Date, Doctor, Patient, std::vector<Medication>);
    //getters
    unsigned int getPrescriptionNumber() const;
    Date getIssueDate() const;
    Doctor getDoctor() const;
    Patient getPatient() const;
    std::vector<Medication> getMedicationList() const;
    //setters
    void setPrescriptionNumber(int);
    void setIssueDate(Date);
    void setDoctorName(std::string);
    void setDoctorSurname(std::string);
    void setPatientName(std::string);
    void setPatientSurname(std::string);
    void setPatientPESELNumber(int);
    void setMedicationList(std::vector<Medication>);
    void setPrescription(int, Date, Doctor, Patient, std::vector<Medication>);
    //other
    void addMedicationRecord(Medication);
    void removeMedicationRecord(int);
};

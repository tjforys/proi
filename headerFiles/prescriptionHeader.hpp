#pragma once
#include <string>
#include <vector>
#include "dateHeader.hpp"
using std::string;
using std::vector;


class Medication{
    string name;
    unsigned int active_substance_content;
    unsigned int price_in_gr;
public:
    Medication(string, int, int);
    //getters
    string getName() const;
    unsigned int getActiveSubstaneContent() const;
    unsigned int getPriceInGr() const;
    //setters
    void setName(string);
    void setActiveSubstanceContent(int);
    void setPriceInGr(int);
    void setMedication(string, int ,int);
    
friend bool operator==(const Medication& lhs, const Medication& rhs){
    return (lhs.name == rhs.name and lhs.active_substance_content == rhs.active_substance_content and lhs.price_in_gr == rhs.price_in_gr);
}
};

class Prescription{
    unsigned int prescriptionNumber;
    Date issueDate;
    string doctorName;
    string doctorSurname;
    string patientName;
    string patientSurname;
    unsigned int patientPESELNumber;
    vector <Medication> medicationList;
public:
    Prescription(int, Date, string, string, string, string, int, vector<Medication>);
    //getters
    unsigned int getPrescriptionNumber() const;
    Date getIssueDate() const;
    string getDoctorName() const;
    string getDoctorSurname() const;
    string getPatientName() const;
    string getPatientSurname() const;
    unsigned int getPatientPESELNumber() const;
    vector<Medication> getMedicationList() const;
    //setters
    void setPrescriptionNumber(int);
    void setIssueDate(Date);
    void setDoctorName(string);
    void setDoctorSurname(string);
    void setPatientName(string);
    void setPatientSurname(string);
    void setPatientPESELNumber(int);
    void setMedicationList(vector<Medication>);
    void setPrescription(int, Date, string, string, string, string, int, vector<Medication>);
    //other
    void addMedicationRecord(Medication);
    void removeMedicationRecord(int);
};

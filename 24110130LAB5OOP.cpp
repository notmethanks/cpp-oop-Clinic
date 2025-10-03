#include <bits/stdc++.h>
using namespace std;

class Appointment;
class Doctor;

class Patient {
protected:
    string id, name;
    int age;
    vector<string> history;
public:
    Patient(string _id="", string _name="", int _age=0) : id(_id), name(_name), age(_age) {}

    string getId() { return id; }
    string getName() { return name; }

    virtual void addHistory(string record) {
        history.push_back(record);
    }

    virtual void display() {
        cout << "Patient [" << id << "] " << name << ", Age: " << age << endl;
        cout << "History: ";
        for (size_t i=0;i<history.size();i++) cout << history[i] << "; ";
        cout << endl;
    }

    virtual void scheduleAppointment() {
        cout << name << " can schedule appointment as needed." << endl;
    }
};

class ChronicPatient : public Patient {
    string condition;
    string lastCheckup;
public:
    ChronicPatient(string _id="", string _name="", int _age=0, string _cond="", string _last="")
        : Patient(_id,_name,_age), condition(_cond), lastCheckup(_last) {}

    void display() {
        cout << "Chronic Patient [" << id << "] " << name << ", Age: " << age 
             << ", Condition: " << condition << ", Last check-up: " << lastCheckup << endl;
    }

    void scheduleAppointment() override {
        cout << name << " (Chronic) must schedule appointment every 3 months." << endl;
    }
};

class Appointment {
    string date, time, reason, status;
    string patientId, doctorId;
public:
    Appointment(string d="", string t="", string r="", string pid="", string did="")
        : date(d), time(t), reason(r), status("Scheduled"), patientId(pid), doctorId(did) {}

    void setStatus(string s) { status = s; }

    void display() {
        cout << "Appointment: " << date << " " << time << ", Reason: " << reason
             << ", Patient: " << patientId << ", Doctor: " << doctorId 
             << ", Status: " << status << endl;
    }

    string getPatientId(){ return patientId; }
    string getDoctorId(){ return doctorId; }
};

class Doctor {
    string id, name, specialty;
    vector<Appointment> appointments;
public:
    Doctor(string _id="", string _name="", string _spec="") : id(_id), name(_name), specialty(_spec) {}

    string getId(){ return id; }
    string getName(){ return name; }

    void assignAppointment(Appointment ap) {
        appointments.push_back(ap);
    }

    void updateStatus(int idx, string s) {
        if (idx >=0 && idx < (int)appointments.size()) appointments[idx].setStatus(s);
    }

    void display() {
        cout << "Doctor ["<<id<<"] "<<name<<" | Specialty: "<<specialty<<endl;
        cout << "Appointments:"<<endl;
        for(size_t i=0;i<appointments.size();i++){
            cout<<"  "; appointments[i].display();
        }
    }
};

class Clinic {
    vector<Patient*> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
public:
    void addPatient(Patient* p){ patients.push_back(p); }
    void addDoctor(Doctor d){ doctors.push_back(d); }

    void showPatients(){
        for(size_t i=0;i<patients.size();i++) patients[i]->display();
    }
    void showDoctors(){
        for(size_t i=0;i<doctors.size();i++) doctors[i].display();
    }
    void showAppointments(){
        for(size_t i=0;i<appointments.size();i++) appointments[i].display();
    }

    void schedule(string pid, string did, string d, string t, string r){
        bool foundP=false, foundD=false;
        for(auto p:patients) if(p->getId()==pid) { foundP=true; p->scheduleAppointment(); }
        for(auto &doc:doctors) if(doc.getId()==did) { foundD=true; }
        if(foundP && foundD){
            Appointment ap(d,t,r,pid,did);
            appointments.push_back(ap);
            for(auto &doc:doctors) if(doc.getId()==did) doc.assignAppointment(ap);
            cout<<"Appointment scheduled successfully."<<endl;
        } else cout<<"Invalid patient or doctor ID."<<endl;
    }
};

int main(){
    Clinic clinic;
    int choice;
    do{
        cout<<"\n=== CLINIC MENU ===\n";
        cout<<"1. Add Patient\n2. Add Chronic Patient\n3. Add Doctor\n4. Show Patients\n5. Show Doctors\n6. Schedule Appointment\n7. Show Appointments\n0. Exit\nChoose: ";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            string id,name; int age;
            cout<<"Enter Patient ID: "; getline(cin,id);
            cout<<"Enter Name: "; getline(cin,name);
            cout<<"Enter Age: "; cin>>age; cin.ignore();
            clinic.addPatient(new Patient(id,name,age));
        } else if(choice==2){
            string id,name,cond,last; int age;
            cout<<"Enter Patient ID: "; getline(cin,id);
            cout<<"Enter Name: "; getline(cin,name);
            cout<<"Enter Age: "; cin>>age; cin.ignore();
            cout<<"Enter Condition: "; getline(cin,cond);
            cout<<"Enter Last Checkup: "; getline(cin,last);
            clinic.addPatient(new ChronicPatient(id,name,age,cond,last));
        } else if(choice==3){
            string id,name,spec;
            cout<<"Enter Doctor ID: "; getline(cin,id);
            cout<<"Enter Name: "; getline(cin,name);
            cout<<"Enter Specialty: "; getline(cin,spec);
            clinic.addDoctor(Doctor(id,name,spec));
        } else if(choice==4){
            clinic.showPatients();
        } else if(choice==5){
            clinic.showDoctors();
        } else if(choice==6){
            string pid,did,d,t,r;
            cout<<"Enter PatientID: "; getline(cin,pid);
            cout<<"Enter DoctorID: "; getline(cin,did);
            cout<<"Enter Date: "; getline(cin,d);
            cout<<"Enter Time: "; getline(cin,t);
            cout<<"Enter Reason: "; getline(cin,r);
            clinic.schedule(pid,did,d,t,r);
        } else if(choice==7){
            clinic.showAppointments();
        }
    }while(choice!=0);
    return 0;
}

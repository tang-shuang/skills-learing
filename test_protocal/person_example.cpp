#include <iostream>
#include <fstream>
#include <string>
#include "person.pb.h"  

using namespace std;
using namespace tutorial;

void SerializePerson(const string& filename) {
    Person person;
    person.set_name("John Doe");
    person.set_id(1234);
    person.set_email("johndoe@example.com");

    Person::PhoneNumber* phone1 = person.add_phones();
    phone1->set_number("555-4321");
    phone1->set_type(Person::HOME);

    Person::PhoneNumber* phone2 = person.add_phones();
    phone2->set_number("555-5555");
    phone2->set_type(Person::WORK);

    ofstream output(filename, ios::binary);
    if (!person.SerializeToOstream(&output)) {
        cerr << "Failed to write person to file." << endl;
        return;
    }
    output.close();
    cout << "Person serialized to " << filename << endl;
}

void DeserializePerson(const string& filename) {
    ifstream input(filename, ios::binary);
    if (!input) {
        cerr << "Failed to open file " << filename << endl;
        return;
    }

    Person person;
    if (!person.ParseFromIstream(&input)) {
        cerr << "Failed to parse person from file." << endl;
        return;
    }
    input.close();

    cout << "Name: " << person.name() << endl;
    cout << "ID: " << person.id() << endl;
    cout << "Email: " << person.email() << endl;
    for (const auto& phone : person.phones()) {
        cout << "Phone: " << phone.number() << " (";
        switch (phone.type()) {
            case Person::MOBILE:
                cout << "Mobile";
                break;
            case Person::HOME:
                cout << "Home";
                break;
            case Person::WORK:
                cout << "Work";
                break;
        }
        cout << ")" << endl;
    }
}

int main() {
    const string filename = "person.dat";

    SerializePerson(filename);

    DeserializePerson(filename);

    return 0;
}

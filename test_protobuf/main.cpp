#include <iostream>
#include <fstream>
#include "person.pb.h"  // 生成的 Protobuf 头文件

void SaveToFile(const tutorial::Person& person, const std::string& filename) {
    std::ofstream output(filename, std::ios::binary);
    if (!person.SerializeToOstream(&output)) {
        std::cerr << "Failed to write person data." << std::endl;
    }
}

tutorial::Person LoadFromFile(const std::string& filename) {
    tutorial::Person person;
    std::ifstream input(filename, std::ios::binary);
    if (!person.ParseFromIstream(&input)) {
        std::cerr << "Failed to read person data." << std::endl;
    }
    return person;
}

int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;  

    tutorial::Person person;
    person.set_name("Alice");
    person.set_age(25);
    person.add_hobbies("Reading");
    person.add_hobbies("Cycling");

    SaveToFile(person, "person_data.bin");

    tutorial::Person loaded_person = LoadFromFile("person_data.bin");
    
    std::cout << "Name: " << loaded_person.name() << std::endl;
    std::cout << "Age: " << loaded_person.age() << std::endl;
    std::cout << "Hobbies: ";
    for (const auto& hobby : loaded_person.hobbies()) {
        std::cout << hobby << " ";
    }
    std::cout << std::endl;

    google::protobuf::ShutdownProtobufLibrary();  
    return 0;
}


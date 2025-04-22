#include <tinyxml2.h>
#include <iostream>

using namespace tinyxml2;
using namespace std;

int main() {
    XMLDocument doc;
    
    XMLDeclaration* decl = doc.NewDeclaration();
    doc.InsertFirstChild(decl);
    
    XMLElement* root = doc.NewElement("Employees");
    doc.InsertEndChild(root);
    
    XMLElement* employee = doc.NewElement("Employee");
    employee->SetAttribute("id", "001");
    
    XMLElement* name = doc.NewElement("Name");
    name->SetText("John Doe");
    employee->InsertEndChild(name);
    
    XMLElement* position = doc.NewElement("Position");
    position->SetText("Software Engineer");
    employee->InsertEndChild(position);
    
    root->InsertEndChild(employee);
    
    doc.SaveFile("employees.xml");
    
    XMLDocument readDoc;
    readDoc.LoadFile("employees.xml");
    
    XMLElement* pRoot = readDoc.FirstChildElement("Employees");
    if (pRoot) {
        XMLElement* pEmployee = pRoot->FirstChildElement("Employee");
        while (pEmployee) {
            cout << "Employee ID: " << pEmployee->Attribute("id") << endl;
            
            XMLElement* pName = pEmployee->FirstChildElement("Name");
            if (pName) {
                cout << "Name: " << pName->GetText() << endl;
            }
            
            pEmployee = pEmployee->NextSiblingElement("Employee");
        }
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

class Student {
public:
  Student(const std::string& firstName, const std::string& lastName, const std::string& address)
      : firstName(firstName), lastName(lastName), address(address) {}

  std::string getStreet() const {
    size_t startPos = address.find_first_of("0123456789");
    size_t endPos = address.find_last_of("0123456789");
    return address.substr(startPos, endPos - startPos + 1);
  }

  std::string getFullName() const {
    return firstName + " " + lastName;
  }
  
  static std::vector<std::string> getStudentsOnSameStreet(const std::vector<Student>& students, const std::string& street) {
    std::vector<std::string> result;

    for (const auto& student : students) {
      if (student.getStreet() == street) {
        result.push_back(student.getFullName());
      }
    }

    return result;
  }

private:
  std::string firstName;
  std::string lastName;
  std::string address;
};

int main() {
  Student student1("John", "Smith", "Street 10");
  Student student2("Mary", "Johnson", "Street 10");
  Student student3("Peter", "Wilson", "Street 20");
  Student student4("Anna", "Brown", "Street 5");

  std::vector<Student> students = {student1, student2, student3, student4};

  std::string streetToSearch = "Street";
  std::vector<std::string> studentsOnSameStreet = Student::getStudentsOnSameStreet(students, streetToSearch);

  std::cout << "Students living on " << streetToSearch << ":" << std::endl;
  for (const auto& studentName : studentsOnSameStreet) {
    std::cout << studentName << std::endl;
  }

  return 0;
}

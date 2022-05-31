#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <clocale>

#include "LinkedList.h"

struct Student
{
    std::string m_firstName;
    std::string m_lastName;
    std::string m_middleName;
};

LinkedList<Student>* readStudentsFile(std::string fname) {
	std::ifstream f(fname);

	if (!f.is_open()) throw "Unable to open file";

	LinkedList<Student> *students = new LinkedList<Student>;

	while (!f.eof()) {
		Student tmp;
		f >> tmp.m_lastName >> tmp.m_firstName >> tmp.m_middleName;
		students->pushBack(tmp);
	}

	f.close();

	return students;
}

void copyStudents(std::string from, std::string to) {
	LinkedList<Student> *students = readStudentsFile(from);
	std::ofstream f(to);
	if (!f.is_open()) throw "Unable to open file";
	while (students->getLength()) {
		Student tmp = students->popFront();
		f << tmp.m_firstName << " " << tmp.m_middleName << " " << tmp.m_lastName << std::endl;
	}

	f.close();
	delete students;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	std::string from;
	std::cout << "Введите название файла из которого нужно копировать" << std::endl;
	getline(std::cin, from);

	std::string to;
	std::cout << "Введите название файла, в который будут копированы данные" << std::endl;
	getline(std::cin, to);

	copyStudents(from, to);

	return 0;
}

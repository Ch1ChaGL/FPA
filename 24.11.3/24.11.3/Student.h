#include <string>

#pragma once
struct Student
{
	std::string FIO;
	int  n_z;
	float opl;
};
Student fill(Student student);
void print(Student student);
void fillArray(Student *Array);
void printArray(Student *array);
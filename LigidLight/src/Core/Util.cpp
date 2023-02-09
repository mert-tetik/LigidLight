#include <iostream>

#include "Util.hpp"

#include <string>
#include <fstream>
 
 
glm::vec3 Util::vec3RGBscaleTo1(glm::vec3 i){
    i/=255.f;
    return i;
}
std::string Util::readFile(const char* path) {
	std::string fullText;
	std::fstream my_file;
	my_file.open(path, std::ios::in);
	if (my_file.is_open()) {
		char mychar;
		while (my_file) {
			mychar = my_file.get();
			if((int)mychar <= 127 && (int)mychar >= 0) //extract non-ascii characters
				fullText += mychar;
		}
	}
	my_file.close();
	return fullText;
}
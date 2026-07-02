#include "Theone.hpp"

void find_replace(std::fstream &file, std::fstream &new_file, std::string to_find, std::string to_replace) {
	if (to_find.empty())
		return;
	std::string content;
	std::string line;
	while (std::getline(file, line)) {
		content += line;
		if (!file.eof())
			content += '\n';
	}
	std::string::size_type pos = 0;
	while ((pos = content.find(to_find, pos)) != std::string::npos) {
		content.erase(pos, to_find.length());
		content.insert(pos, to_replace);
		pos += to_replace.length();
	}
	new_file << content;
}

/*
 * ATTRIBUTE PARSER
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

class Tag {
	private:
	string tag_name;
	map<string, string> att_val;
	vector<string> child_tags;
	public:
	Tag(const string& tag);
	~Tag();
	add_attribute(const string& attr_name, const string& value);
};

Tag::Tag(const string& tag) {
	this->tag_name = tag;
	// TO DELETE for debug only
	cout << "Tag with name " << tag << " was created" << endl;
}

Tag::add_attribute(const string& attr_name, const string& value) {
	this->att_val.insert(pair<const string&, const string&>(attr_name, value));
	cout << "Added attribute " << attr_name << " with value: " << att_val[attr_name] << endl;
}

// TO DELETE for debug only
Tag::~Tag() {
	cout << "Tag: " << this->tag_name << " destroyed!" << endl;
}

bool is_opening_tag(string line) {
	if(line.substr(0, 2) == "</")
		return false;
	else if(line[0] == '<')
		return true;
	return false;
}

void parse_line(string line) {
	stringstream ss(line);
	string word, att_name, value;
	Tag* last_tag_ptr;
	while(ss >> word) {
		if(is_opening_tag(word)) {
			Tag tag = Tag(word.substr(1));
			while(ss >> word && word[0] != '>') {
				att_name = word;
				ss >> word;
				if (word[0] == '=') {
					ss >> word;
					if(word.back() == '>') {
						value = word.substr(1, word.length() - 3); // remove "\">"
					} else {
						value = word.substr(1, word.length() - 2); // remove "\""
					}
					tag.add_attribute(att_name, value);					
				} else {
					tag.add_attribute(att_name, "");
				}
			}
		} else {
			
		}
	}
}

int main() {
	ifstream htmlStream("html_file.txt");
	string line;
	int html_lines, querry_lines;

	if (htmlStream.is_open()) {
		htmlStream >> html_lines >> querry_lines;
		for(int i = 0; i < html_lines; i++) {
			getline(htmlStream, line);
			parse_line(line);
		}
	} else {
		cerr << "Could not open the file" << endl;
	}
}
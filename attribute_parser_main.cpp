#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;

class Tag {
	private:
	string tag_name;
	map<string, string> att_val;
	public:
	Tag(const string& tag_name);
	~Tag();
	add_attr(const string& attr, const string& val);
};

Tag::Tag(const string& tag_name) {
	this->tag_name = tag_name;
	cout << "Tag : " << this->tag_name << " was CREATED!" << endl;
}

Tag::~Tag() {
	cout << "~Tag: " << this->tag_name << " was DESTROYED!" << endl;
}

Tag::add_attr(const string& attr, const string& val) {
	this->att_val.insert(pair<const string&, const string&>(attr, val));
	cout << "Added attribute " << attr << " with the value: " << this->att_val[attr] << endl;
}

int main() {
	int html_lines, querry_lines; // not using
	ifstream html_file("html_file.txt");
	stringstream ss;
	string line, word, attribute, value;
	vector<Tag> tags;
	bool eol = false;
	if(html_file.is_open()) {
		// To be decided if I use word by word or line by line
		html_file >> html_lines;
		html_file >> querry_lines;
		getline(html_file, line);
		for(int i = 0; i < html_lines; i++) {
			getline(html_file, line);
			ss.str("");
			ss.clear();
			ss << line;
			ss >> word;
			if(word.substr(0,2) == "</") {
				cout << "end of tag" << endl;
			} else {
				Tag tag = Tag(word.substr(1));
				while(ss >> word) {
					attribute = word;
					ss >> word;
					ss >> word;
					if(word.back() == '>') {
						value = word.substr(1, word.length() - 3);
					} else {
						value = word.substr(1, word.length() - 2);
					}
					tag.add_attr(attribute, value);
				}
				tags.push_back(tag);
			}
		}
	} else {
		cerr << "Could not open the file";
		return -1;
	}
}
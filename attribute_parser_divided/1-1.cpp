// First step create all the tags from the html code

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

class Tag {
	private:
	string tag_name;
	map<string, string> attr_val;
	bool open_tag_status;
	vector<Tag*> child_tags;
	
	private:
	string remove_decoration(string&);
	
	public:
	Tag(const string&);
	void add_attr_value(const string&, string&);
	string get_tag_name();
	void add_tag_child(Tag*);
	void set_open_status(bool);
	bool get_open_status();
	string get_value(const string&);
	void display_children();
	vector<Tag*> get_children();
};

Tag::Tag(const string& tag) {
	this->tag_name = tag;
	this->open_tag_status = true;
	cout << "TAG CREATED: " << this->tag_name << endl;
}

string Tag::remove_decoration(string& value) {
	if(value.back() == '>') {
		return value.substr(1, value.length()-3);
	} else {
		return value.substr(1, value.length()-2);
	}
}

void Tag::add_attr_value(const string& attr, string& value) {
	value = remove_decoration(value);
	this->attr_val.insert(pair<string, string>(attr, value));
	cout << "Attribute : -" << attr << "- created with the value : -" << this->attr_val[attr] << "-" << endl;
}

string Tag::get_tag_name() {
	return this->tag_name;
}

void Tag::add_tag_child(Tag* tag) {
	cout << "Added the tag: *" << tag->get_tag_name() << "* as child to the tag " << this->tag_name << endl; 
	this->child_tags.push_back(tag);
}

void Tag::set_open_status(bool val) {
	this->open_tag_status = val;
}
bool Tag::get_open_status() {
	return this->open_tag_status;
}

string Tag::get_value(const string& attr) {
	string value;
	value = this->attr_val[attr];
}

void Tag::display_children() {
	for(auto child : child_tags) {
		cout << "Tag " << this->tag_name << " has the folowing children " << child->get_tag_name() << " ";
	}
	cout << endl;
}

vector<Tag*> Tag::get_children() {
	return this->child_tags;
}


int main() {
	ifstream file("html_file.txt");
	int html_lines, querry_lines;
	string line, word, attribute, value;
	stringstream ss;
	vector<Tag> tags;
	bool closed = false;
	
	file >> html_lines;
	file >> querry_lines;
	getline(file, line); // go to next line
	if(file.is_open()) {
		// parser
		for(int i = 0; i < html_lines; i++) {
			getline(file, line);
			ss.clear();
			ss.str(string()); // empty string
			ss << line;
			ss >> word;
			
			if(word.substr(0, 2) == "</") {
				//cout << "end tag" << endl;
				string closing_tag = word.substr(2, word.length()-1);
				auto closed_tag_pos = find_if(tags.begin(), tags.end(), 
				[&closing_tag](Tag& obj) {return obj.get_tag_name() == closing_tag;});
				closed_tag_pos->set_open_status(false);
			} else {
				if(word.back() != '>'){
					Tag tag = Tag(word.substr(1));
					if(tag.get_open_status()) {
						if(tags.size() != 0) {
							tags.back().add_tag_child(&tag);
						} else {
							tags.push_back(tag);
						}
					}
					
					while(getline(ss, word, ' ')) {
						getline(ss, word, ' ');
						//ss >> word;
						attribute = word;
						ss >> word;
						ss >> word;
						value = word;
						tag.add_attr_value(attribute, value);
					}
					closed = false;
				} else {
					Tag tag = Tag(word.substr(1, word.length()-1));
					closed = false;
				}
			}
		}
		
		// querry
		for(int i = 0; i < querry_lines; i++) {
			Tag *tag_display;
			int point_pos;
			string tag1, final_tag;
			attribute = "";
			getline(file, line);
			cout << "queryy line : " << line << endl;
			ss.clear();
			ss.str(string()); // empty string
			ss << line;
			getline(ss, word, '~');
			while((point_pos = word.find('.')) != string::npos) {
				tag1 = word.substr(0, point_pos);
				cout << "tag1 = " << tag1 << endl;
				word.erase(0, point_pos + 1);
				final_tag = word;
				cout << "FINAL TAG = " << final_tag << endl;
				auto tag1_pos = find_if(tags.begin(), tags.end(), 
				[&tag1](Tag& obj) {return obj.get_tag_name() == tag1;});
				for(auto child : tag1_pos->get_children()) {
					cout << " xxxxxxx : " << child->get_tag_name() << endl;
					if(child->get_tag_name() == final_tag) {
						tag_display = child;
					}
				}
			}
			ss >> attribute;
			cout << "attribute = " << attribute << endl;
			cout << tag_display->get_value(attribute) << endl;
		}
	} else {
		cout << "Could not open the file";
	}
}
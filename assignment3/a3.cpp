// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Chaeri Kang>
// St.# : <301425923>
// Email: <chaeri_kang@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"    //
#include "List_base.h"     // These are the only permitted #includes!
#include <iostream>        //
#include <string>          // Don't #include anything else.
#include <vector>          //
#include <cassert>

using namespace std;

class Bulleted_list: public List_base {
  private:
    vector<string> lst;
    string bullet;
    string indent;

  public:
    Bulleted_list()
    :lst(0), bullet("- "), indent("")
    {}

    void add_to_start(const string& s){
      lst.insert(lst.begin(), s);
    }

    void add_to_end(const string& s){
      lst.push_back(s);
    }

    string to_str() const{
      string str;

      for (int i = 0; i < lst.size(); i++){
        str += indent;
        str += bullet;
        str += lst[i];
        str += "\n";
      }
      return str;
    }

    void set_indent(int num_spaces){
      indent = "";
      for (int i = 0; i < num_spaces; i++){
        indent += " ";
      }
    }

    string get_indent() const{
      return indent;
    }

    void set_bullet(string new_bullet){
      bullet = new_bullet;
    }

    string get_bullet() const{
      return bullet;
    }

    void reverse_order(){
      reverse(lst.begin(), lst.end());
    }

    string to_html_str() const{
      string html_str;

      html_str += "<ul>\n";
      for (int i = 0; i < lst.size(); i++){
        html_str += "  <li>";
        html_str += lst[i];
        html_str += "</li>\n";
      }
      html_str += "</ul>\n";
      return html_str;
    }

    int size() const{
      return lst.size();
    }

    string get(int i) const{
      if (i < 0 || i >= lst.size()) cmpt::error("out of bounds");
      return lst[i];
    }

};

class Numbered_list: public List_base {
  private:
    vector<string> lst;
    string separate;
    string indent;
    int counter;
    int rev;

  public:

public:
    Numbered_list()
    :lst(0), counter(1), separate(". "), indent(""), rev(0)
    {}

    void add_to_start(const string& s){
      lst.insert(lst.begin(), s);
    }

    void add_to_end(const string& s){
      lst.push_back(s);
    }

    string to_str() const{
      string str;
      if (rev % 2 == 0) {
        int count = counter;
        for (int i = 0; i < lst.size(); i++){
          str += indent;
          str += to_string(count);
          str += separate;
          str += lst[i]; 
          str += "\n";
          count++;
        }
      }
      if (rev % 2 == 1) {
        int count = counter + lst.size() - 1;
        for (int i = 0; i < lst.size(); i++){
          str += indent;
          str += to_string(count);
          str += separate;
          str += lst[i];
          str += "\n";
          count--;
        }
      }
      return str;
    }

    void set_indent(int num_spaces){
      indent = "";
      for (int i = 0; i < num_spaces; i++){
        indent += " ";
      }
    }

    string get_indent() const{
      return indent;
    }

    void set_num_sep(string new_separate){
      separate = new_separate;
    }

    string get_num_sep() const{
      return separate;
    }

    void set_start_num(int start_num){
      if (start_num < 0){
        counter = 0;
      }
      else{
        counter = start_num;
      }
    }

    int get_start_num(){
      return counter;
    }

    void reverse_order(){
      rev++;
      reverse(lst.begin(), lst.end());
    }

    string to_html_str() const{
      string html_str;
      if (rev % 2 == 0) {
        html_str += "<ol>\n";
        for (int i = 0; i < lst.size(); i++){
          html_str += "  <li>";
          html_str += lst[i];
          html_str += "</li>\n";
        }
        html_str += "</ol>\n";  
      }
      if (rev % 2 == 1) {
        html_str += "<ol reversed>\n";
        for (int i = 0; i < lst.size(); i++){
          html_str += "  <li>";
          html_str += lst[i];
          html_str += "</li>\n";
        }
        html_str += "</ol>\n";         
      }
      return html_str;
    }

    int size() const{
      return lst.size();
    }

    string get(int i) const{
      if (i < 0 || i >= lst.size()) cmpt::error("out of bounds");
      return lst[i];
    }

};

void demo1() {
    Bulleted_list lst;

    lst.add_to_end("oranges");
    lst.add_to_end("pears");
    lst.add_to_end("grapes");
    lst.add_to_start("apples");

    cout << "\n";
    cout << lst.to_str();

    lst.set_indent(3);
    cout << "\n";
    cout << lst.to_str();

    lst.set_indent(0);
    lst.set_bullet("** ");
    cout << "\n";
    cout << lst.to_str();

    lst.set_bullet("- ");
    lst.reverse_order();
    cout << "\n";
    cout << lst.to_str();

    lst.reverse_order();
    cout << "\n";
    cout << lst.to_html_str();
}

void demo2() {
    Numbered_list lst;

    lst.add_to_end("oranges");
    lst.add_to_end("pears");
    lst.add_to_end("grapes");
    lst.add_to_start("apples");

    cout << lst.to_str();

    lst.set_num_sep(") ");
    cout << "\n";
    cout << lst.to_str();

    lst.set_start_num(3);
    cout << "\n";
    cout << lst.to_str();

    lst.set_start_num(1);
    lst.reverse_order();
    cout << "\n";
    cout << lst.to_str();

    lst.set_start_num(3);
    cout << "\n";
    cout << lst.to_str();

    lst.reverse_order();
    cout << "\n";
    cout << lst.to_html_str();

    lst.reverse_order();
    cout << "\n";
    cout << lst.to_html_str();
}

int main() {
  cout << "demo1 output: \n";
  demo1();
  cout << "\n";
  cout << "demo2 output: \n";
  demo2();
}



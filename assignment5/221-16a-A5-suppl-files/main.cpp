///////////////////////////////////
/// Name: Matthew Stevens       ///
/// Username: Mattizrawr        ///
/// Section Number: 503         ///
/// email: mattizrawr@tamu.edu  ///
///////////////////////////////////

#include <iostream> 
#include <cstdlib>
#include <string> 
#include <cstdio>
#include <fstream>
#include <regex>

using namespace std;
const int TABLE_SIZE = 100;

class HashNode{
  public:
  int key, value;
  HashNode* next;
    HashNode(int key, int value){
      this->key = key;
      this->value = value;
      this->next = NULL;
    }
};

class HashMap{
  private:
    HashNode **htable;
  public:
    HashMap(){
      htable = new HashNode*[TABLE_SIZE];
      for (int i=0; i < TABLE_SIZE; ++i)
        htable[i] = NULL;
    }

    int HashFunc(int key){
      return key % TABLE_SIZE;
    }

    void Insert(int key, int value){
      int hash_val = HashFunc(key);
      HashNode* prev = NULL;
      HashNode* entry = htable[hash_val];
      while(entry != NULL){
        prev = entry;
        entry = entry->next;
      }
      if (entry == NULL){
        entry = new HashNode(key, value);
        if (prev == NULL){
          htable[hash_val] = entry;
        } else{
          prev->next = entry;
          } 
        }
        else{
          entry->value = value;
        }
      }

    void Search(int key, ofstream &outfile){
      int hash_val = HashFunc(key);
      HashNode* entry = htable[hash_val];
      while (entry != NULL){
        if (entry->key == key)
          outfile << entry->value << ",";
        entry = entry->next;
      }
      outfile << endl;
    }
};

int main(){
  HashMap hash;
  int key, value;
  string input, keyString, valueString;
  ifstream myfile;
  ofstream outfile;
  smatch match;

  //open input file
  myfile.open("input.csv");

  if(myfile.fail()){
    cout << "No file" << endl;
  }
  while(!myfile.eof()){
    	//gets line
	getline(myfile, input);
        regex r1(".*,.*,([0-9]{9}),([0-9]*)");
    if (regex_search(input, match, r1)){
      keyString = match[1];
      valueString = match[2];
    }
      //change string to int value
      key = atoi(keyString.c_str());
      value = atoi(valueString.c_str());
      hash.Insert(key, value);
    }
    myfile.close();

    myfile.open("roster.csv");
      if(myfile.fail()){
        cout << "No File" << endl;
      }
    

    outfile.open("update_roster.csv");
    if(outfile.fail()){
      cout << "No File" << endl;
    }

    while(getline(myfile, input)){
      regex r2 ("(.*),(.*),([0-9]{9}),([0-9]*)");
      if(regex_search(input, match, r2))
          keyString = match[3];
      key = atoi(keyString.c_str());
      string whole = match[0];

      outfile << whole;
      hash.Search(key, outfile);
    }
    outfile.close();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Folder; // forward declaration of Folder so it compiles
class Document {
public:
  Document(string name, int id, Folder* folder)
      : name(name), idNumber(id), folder(folder) {}
  virtual void setFolder(Folder* folder) {
    this->folder = folder;
  }
  virtual void print() {
    cout << "Document id: " << idNumber
       << " name: " << name << endl;
  }
protected:
  string name;
  int idNumber;
  // Pointer to a mentor, could be NULL if no mentor
  Folder* folder;
};

class Folder : public Document {
public:
  Folder(string name, int id, Folder* parent) : Document(name, id, parent) {} 
  virtual void print() {
    cout << "Folder: id: " << idNumber << " name: " << name << endl;
    for (int i = 0; i < documents.size(); i++) {
      documents.at(i)->print();
    }
  }
  vector<Document*> getDocuments() {
    return documents;
  }
  void addDocument(Document* doc) {
    doc->setFolder(this);
    documents.push_back(doc);
  }
private:
  vector<Document*> documents;
};

int main() {
  /*
  {
    Document* d = new Document("input.txt", 1, NULL);
    Folder* f = new Folder("myDir", 2, NULL);

    vector<Document*> v;
    v.push_back(d);
    v.push_back(f);
    for (unsigned int i = 0; i < v.size(); i++) {
      v[i]->print();
    }  
  }
  */
  
  {
    Folder* root = new Folder("/", 1, NULL);
    Folder* home = new Folder("home", 2, root);
    root->addDocument(home);
    Folder* user = new Folder("student", 3, home);
    home->addDocument(user);
    Document* resume = new Document("resume.txt", 4, user);
    Document* prog = new Document("program.cpp", 5, user);
    user->addDocument(resume);
    user->addDocument(prog);
    
    root->print();
  }
}
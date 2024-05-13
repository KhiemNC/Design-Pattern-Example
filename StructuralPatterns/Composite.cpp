#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Component
class Data {
    public:
    virtual void display(int depth = 0) = 0;
    virtual void add(Data* data) { throw "Not supported"; }
    virtual void remove(Data* data) { throw "Not supported"; }
    virtual int count() = 0;
};

// Leaf
class File : public Data {
    private:
    string name;
    
    public:
    File(string name) { this->name = name; }
    
    void display(int depth = 0) override {
        for (int i = 0; i < depth; ++i) { cout << "-"; }
        cout << "File: " << name << endl;
    }
    int count() override { return 1; }
};

// Composite
class Folder : public Data {
    private:
    string name;
    vector<Data*> children;
    
    public:
    Folder(string name) { this->name = name; }
    
    void display(int depth = 0) override {
        for (int i = 0; i < depth; ++i) { cout << "-"; }
        cout << "Folder: " << name << endl;
        for (auto child : children) {
            child->display(depth + 2);
        }
    }
    
    void add(Data* data) override { children.push_back(data); }
    
    void remove(Data* data) override {
        for (auto it = children.begin(); it != children.end(); ++it) {
            if (*it == data) {
                children.erase(it);
                return;
            }
        }
    }

    int count() override {
        int total = 0;
        for (auto child : children) {
            total += child->count();
        }
        return total;
    }
};

int main(int argc, char* argv[]) {
    Data* root = new Folder("Root");
    Data* folder1 = new Folder("Folder1");
    Data* folder2 = new Folder("Folder2");
    Data* file1 = new File("File1");
    Data* file2 = new File("File2");
    Data* file3 = new File("File3");
    
    root->add(folder1);
    root->add(folder2);
    root->add(file3);
    folder1->add(file1);
    folder2->add(file2);
    
    root->display();
    cout << "Total files: " << root->count() << endl;
    
    delete root;
    delete folder1;
    delete folder2;
    delete file1;
    delete file2;
    delete file3;
    return 0;
}

/* Output: */
/*
Folder: Root
Folder: Folder1
File: File1
Folder: Folder2
File: File2
File: File3
Total files: 3
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

// Component Interface
class FileSystemComponent {
public:
    virtual void display(int depth = 0) = 0; // Pure virtual function
    virtual ~FileSystemComponent() {}
};

// Leaf: File
class File : public FileSystemComponent {
    std::string name;
public:
    File(const std::string& name) : name(name) {}
    void display(int depth = 0) override {
        std::cout << std::string(depth, '-') << "File: " << name << std::endl;
    }
};

// Composite: Directory
class Directory : public FileSystemComponent {
    std::string name;
    std::vector<FileSystemComponent*> components;
public:
    Directory(const std::string& name) : name(name) {}
    void add(FileSystemComponent* component) {
        components.push_back(component);
    }
    void remove(FileSystemComponent* component) {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }
    void display(int depth = 0) override {
        std::cout << std::string(depth, '-') << "Directory: " << name << std::endl;
        for (auto& component : components) {
            component->display(depth + 2);
        }
    }
    ~Directory() {
        for (auto component : components) {
            delete component;
        }
    }
};


int main() {
    Directory* root = new Directory("root");
    root->add(new File("file1.txt"));
    root->add(new File("file2.txt"));

    Directory* subdir = new Directory("subdir");
    subdir->add(new File("file3.txt"));
    root->add(subdir);

    Directory* subsubdir = new Directory("subsubdir");
    subsubdir->add(new File("file4.txt"));
    subdir->add(subsubdir);

    root->display();
    
    delete root; // This will recursively delete all components

    return 0;
}


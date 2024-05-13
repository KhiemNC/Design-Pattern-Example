#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Command
class Command {
    public:
    virtual void execute() = 0;
};

// Receiver
class Document {
    private:
    string content;
    
    public:
    Document(string content) { this->content = content; }
    void open() { cout << "Document opened: " << content << endl; }
    void close() { cout << "Document closed: " << content << endl; }
    void copy() { cout << "Document copied: " << content << endl; }
    void cut() { cout << "Document cut: " << content << endl; }
    void paste() { cout << "Document pasted: " << content << endl; }
};

// ConcreteCommand
class OpenCommand : public Command {
    private:
    Document* document;
    
    public:
    OpenCommand(Document* document) { this->document = document; }
    void execute() override { document->open(); }
};
class CloseCommand : public Command {
    private:
    Document* document;
    
    public:
    CloseCommand(Document* document) { this->document = document; }
    void execute() override { document->close(); }
};
class CopyCommand : public Command {
    private:
    Document* document;
    
    public:
    CopyCommand(Document* document) { this->document = document; }
    void execute() override { document->copy(); }
};
class CutCommand : public Command {
    private:
    Document* document;
    
    public:
    CutCommand(Document* document) { this->document = document; }
    void execute() override { document->cut(); }
};
class PasteCommand : public Command {
    private:
    Document* document;
    
    public:
    PasteCommand(Document* document) { this->document = document; }
    void execute() override { document->paste(); }
};

// Invoker
class Editor {
    private:
    vector<Command*> commands;
    
    public:
    void execute(Command* command) {
        commands.push_back(command);
        command->execute();
    }
    void undo() {
        if (commands.empty()) {
            cout << "No commands to undo" << endl;
            return;
        }
        Command* command = commands.back();
        commands.pop_back();
        cout << "Undoing command: ";
        command->execute();
    }
};

int main(int argc, char* argv[]) {
    Document document("Document1");
    Editor editor;

    editor.execute(new OpenCommand(&document));
    editor.execute(new CopyCommand(&document));

    editor.undo();
    return 0;
}

/* Output: */
/*
Document opened: Document1
Document copied: Document1
Undoing command: Document copied: Document1
*/
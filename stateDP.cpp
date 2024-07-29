#include <iostream>
#include <string>

// State Interface
class DocumentState {
public:
    virtual void edit() = 0;
    virtual void review() = 0;
    virtual void publish() = 0;
    virtual ~DocumentState() {}
};

// Concrete States
class DraftState : public DocumentState {
public:
    void edit() override {
        std::cout << "Document is in Draft. You can edit the document.\n";
    }
    void review() override {
        std::cout << "Document is in Draft. Send the document for review.\n";
    }
    void publish() override {
        std::cout << "Document is in Draft. Cannot publish the document directly.\n";
    }
};

class ModerationState : public DocumentState {
public:
    void edit() override {
        std::cout << "Document is under Moderation. Editing is restricted.\n";
    }
    void review() override {
        std::cout << "Document is under Moderation. Review is in progress.\n";
    }
    void publish() override {
        std::cout << "Document is under Moderation. Cannot publish yet.\n";
    }
};

class PublishedState : public DocumentState {
public:
    void edit() override {
        std::cout << "Document is Published. Editing is locked.\n";
    }
    void review() override {
        std::cout << "Document is Published. Review is not applicable.\n";
    }
    void publish() override {
        std::cout << "Document is Published. Already published.\n";
    }
};

// Context Class
class Document {
    DocumentState* state;
public:
    Document(DocumentState* initialState) : state(initialState) {}
    void setState(DocumentState* newState) {
        state = newState;
    }
    void edit() {
        state->edit();
    }
    void review() {
        state->review();
    }
    void publish() {
        state->publish();
    }
};

// Client Code
int main() {
    DocumentState* draft = new DraftState();
    DocumentState* moderation = new ModerationState();
    DocumentState* published = new PublishedState();

    Document doc(draft);
    doc.edit();
    doc.review();
    doc.publish();

    doc.setState(moderation);
    doc.edit();
    doc.review();
    doc.publish();

    doc.setState(published);
    doc.edit();
    doc.review();
    doc.publish();

    delete draft;
    delete moderation;
    delete published;

    return 0;
}


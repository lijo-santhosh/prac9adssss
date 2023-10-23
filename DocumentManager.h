#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <string>

class Document {
public:
    Document() = default;  // Default constructor

    Document(const std::string& name, int id, int license_limit)
        : name(name), id(id), license_limit(license_limit), borrowed_copies(0) {}

    std::string name;
    int id;
    int license_limit;
    int borrowed_copies;
};

class DocumentManager {
public:
    void addDocument(const std::string& name, int id, int license_limit);
    void addPatron(int patronID);
    int search(const std::string& name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);

private:
    std::unordered_map<int, Document> docMap;
    std::unordered_set<int> patrons;
};

#endif  // DOCUMENTMANAGER_H

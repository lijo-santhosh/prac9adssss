#include "DocumentManager.h"

void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    Document document(name, id, license_limit);
    docMap[id] = document;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(const std::string& name) {
    for (auto it = docMap.begin(); it != docMap.end(); ++it) {
        if (it->second.name == name) {
            return it->first;
        }
    }
    return 0;  // Document not found
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.count(patronID) == 0) {
        return false;
    }

    auto it = docMap.find(docid);
    if (it != docMap.end()) {
        Document& document = it->second;
        if (document.borrowed_copies < document.license_limit) {
            document.borrowed_copies++;
            return true;
        }
    }

    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if (patrons.count(patronID) == 0) {
        return;
    }

    auto it = docMap.find(docid);
    if (it != docMap.end()) {
        Document& document = it->second;
        if (document.borrowed_copies > 0) {
            document.borrowed_copies--;
        }
    }
}

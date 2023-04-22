#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Note.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Notebook
{
private:
    std::string notebookName;
    std::vector<Note*> notes;
    Note* currentNote = nullptr;
public:
    Notebook();
    Notebook(string name);
    void setNotebookName(const string name);
    string getNotebookName() const;
    void addNote(Note*);
    void deleteNoteByNoteName(const string name);
    std::vector<Note*> getAllNotes() const;
    void setCurrentNoteByNoteName(const string name);
    Note* getCurrentNote() const;
};

#endif // NOTEBOOK_H

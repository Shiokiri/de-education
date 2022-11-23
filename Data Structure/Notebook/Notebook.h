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
    string notebookName;
    vector<Note*> notes;
public:
    Notebook();
};

#endif // NOTEBOOK_H

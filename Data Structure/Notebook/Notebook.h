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
    Notebook(string name);
    // 设置笔记本名称
    void setNotebookName(const string name);
    // 获取笔记本名称
    string getNotebookName() const;

    // 添加笔记
    void addNote(Note*);

    // 通过笔记名称删除笔记
    void deleteNoteByNoteName(const string name);

    // 获取所有笔记
    vector<Note*> getAllNotes() const;
};

#endif // NOTEBOOK_H

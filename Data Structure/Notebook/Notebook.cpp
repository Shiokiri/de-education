#include "Notebook.h"

Notebook::Notebook() {}
Notebook::Notebook(string name):
    notebookName(name) {}
// 设置笔记本名称
void Notebook::setNotebookName(const string name)
{
    notebookName = name;
}
// 获取笔记本名称
string Notebook::getNotebookName() const
{
    return notebookName;
}

// 添加笔记
void Notebook::addNote(Note* note)
{
    notes.push_back(note);
}

// 通过笔记名称删除笔记
void Notebook::deleteNoteByNoteName(const string name)
{
    for(auto note = notes.begin(); note != notes.end(); )
    {
        if((*note)->getNoteName() == name)
        {
            note = notes.erase(note);
        }
        else
        {
            note++;
        }
    }
}

// 获取所有笔记
vector<Note*> Notebook::getAllNotes() const
{
    return notes;
}

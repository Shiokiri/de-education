#include "Note.h"

Note::Note(){}
Note::Note(string name):
    noteName(name) {}
Note::Note(string name, string text):
    noteName(name),
    text(text) {}
// 获取笔记名称
string Note::getNoteName() const
{
    return this->noteName;
}
// 设置笔记名称
void Note::setNoteName(const string name)
{
    this->noteName = name;
}
// 获取笔记文本
string Note::getText() const
{
    return this->text;
}
// 设置笔记文本
void Note::setText(const string text)
{
    this->text = text;
}

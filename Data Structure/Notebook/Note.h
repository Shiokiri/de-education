#ifndef NOTE_H
#define NOTE_H

#include <string>

using std::string;

class Note
{
private:
    string noteName;
    string text;
public:
    Note();
    Note(string name);
    Note(string name, string text);
    // 获取笔记名称
    string getNoteName() const;
    // 设置笔记名称
    void setNoteName(const string name);
    // 获取笔记文本
    string getText() const;
    // 设置笔记文本
    void setText(const string text);
};

#endif // NOTE_H

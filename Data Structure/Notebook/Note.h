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
    string getNoteName() const;
    void setNoteName(const string name);
    string getText() const;
    void setText(const string text);
};

#endif // NOTE_H

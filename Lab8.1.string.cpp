// Lab 8.1 (standard C++ functions for string)
// Пошук та заміна символів у літерному рядку
// Варіант 28

// Дано літерний рядок, який містить послідовність символів
// s[0], ..., s[n], ...
// 1.   Вияснити, чи є серед цих символів всі букви,
//      що входять в слово "while".
// 2.   Замінити кожну групу букв "while" парою зірочок "**".

#include <iostream>
#include <string>

using namespace std;

bool IsAllLettersPresent(const string s, const string letters);
string Change(string& s);

int main()
{
    const string letters = "while";   // букви для перевірки

    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    if (IsAllLettersPresent(str, letters))
        cout << "All letters of \"while\" are present" << endl;
    else
        cout << "Not all letters of \"while\" are present" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}

// чи є в рядку s усі символи з рядка letters
bool IsAllLettersPresent(const string s, const string letters)
{
    for (size_t k = 0; k < letters.length(); k++)
        if (s.find(letters[k]) == string::npos)
            return false;

    return true;
}

// заміна кожної групи букв "while" парою зірочок "**"
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("while", pos)) != string::npos)
    {
        s.replace(pos, 5, "**");
        pos += 2;                      // пропускаємо вставлені зірочки
    }

    return s;
}

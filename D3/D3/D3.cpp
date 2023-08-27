#include <iostream>
#include<string>
#include<fstream>
using namespace std;
//#define number1
//#define number2
//#define number3
//#define number4
int main() {
    setlocale(LC_ALL, "rus");
    ifstream in("input.txt");
    ofstream out("output.txt");
    if (!in.is_open()) {
        cout << "The file could not be opened" << endl;
    }
#ifdef number1
    std::string str;
    std::string lastLine;

    while (getline(in, str)) {
        if (!str.empty()) {
            lastLine = str;
        }
    }

    in.clear();  
    in.seekg(0); 

    while (getline(in, str)) {
        if (str != lastLine) {
            out << str << std::endl;
        }
    }

    in.close();
    out.close();
#endif 

#ifdef number2
    std::string str;
    size_t maxLength = 0;

    while (std::getline(in, str)) {
        maxLength = max(maxLength, str.length());
    }
    in.close();
    cout << "maxLength = " << maxLength<< endl;
#endif

#ifdef number3
 
    string word;
    cout << "word: ";
    cin >> word;

    int count = 0;
    string str;
    while (getline(in, str)) {
        int pos = 0;
        while ((pos = str.find(word, pos)) != std::string::npos) {
            count++;
            pos += word.length(); 
        }
    }

    in.close();

    cout << "Слово " << word << " встречается " << count << " раз(а)." << endl;

#endif

#ifdef number4
    if (!in.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    string searchWord, replacementWord;
    cout << "Введите слово для поиска: ";
    cin >> searchWord;
    cout << "Введите слово для замены: ";
    cin >> replacementWord;

    string str;
    while (std::getline(in, str)) {
        size_t pos = 0;
        while ((pos = str.find(searchWord, pos)) != std::string::npos) {
            str.replace(pos, searchWord.length(), replacementWord);
            pos += replacementWord.length(); 
        }
        out << str << endl;
    }

    in.close();
    out.close();

#endif 

}
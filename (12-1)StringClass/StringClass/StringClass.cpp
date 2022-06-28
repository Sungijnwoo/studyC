#include <iostream>
#include <cstring>
using namespace std;

class String {
    private:
        int len;
        char * str;
    public:
        String() {
            cout << "String()" << endl;
            len = 0;
            str = NULL;
        }

        String(const char * s) {
            cout << "String(const char * s)" << endl;
            len = strlen(s) + 1;
            str = new char[len];
            strcpy(str, s);
        }
        
        String(const String& s) {
            cout << "String(const String& s" << endl;
            len = s.len;
            str = new char[len];
            strcpy(str, s.str);
        }

        ~String() {
            cout << "~String()" << endl;
            if(str!=NULL)
                delete []str;
        }

        String& operator= (const String& s) {
            cout << "operator=" << endl;
            if (str!=NULL)
                delete []str;
            len = s.len;
            str = new char[len];
            strcpy(str, s.str);
            return *this;
        }

        String& operator+= (const String& s) {
            cout << "operator+=" << endl;
            len += (s.len-1);
            char * tempstr = new char[len];
            strcpy(tempstr, str);
            strcat(tempstr, s.str);

            if(str != NULL)
                delete []str;
            str = tempstr;
            return *this;
        }

        bool operator== (const String& s) {
            cout << "operator==" << endl;
            return strcmp(str, s.str) ? false : true;
        }

        String operator+ (const String& s) {
            cout << "operator+" << endl;
            char* tempstr = new char[len+s.len-1];
            strcpy(tempstr, str);
            strcat(tempstr, s.str);

            String temp(tempstr);
            delete []tempstr;
            return temp;
        }

        friend ostream& operator<< (ostream& os, const String& s);
        friend istream& operator>> (ostream& os, String& s);
};


ostream& operator<< (ostream& os, const String& s) {
    cout << "operator<<" << endl;
    os << s.str;
    return os;
}

istream& operator>> (istream& is, String& s) {
    cout << "operator>>" << endl;
    char str[100];
    is>>str;
    s = String(str);
    return is;
}

int main(void) {
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    cout << str1 << endl;
    if (str1 == str3)
        cout << "Same String" << endl;
    else
        cout << "Different String" << endl;

    String str4;
    cout << "input string: " ;
    cin >> str4;
    cout << "input string: " << str4 << endl;
    return 0;
}
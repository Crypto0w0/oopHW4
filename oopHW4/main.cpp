#include <iostream>
using namespace std;

class myString{
    char* str;
    unsigned long length;
    static int objects;
public:
    myString(){
        str = new char[80];
        length = 0;
        objects++;
    }
    myString(int size){
        length = size;
        str = new char[length + 1];
    }
    myString(char* userstr){
        strcpy(str, userstr);
        length = strlen(str);
    }
    ~myString(){
        delete[] str;
    }
    myString(myString&& obj){
        str = obj.str;
        obj.str = nullptr;
        length = obj.length;
    }
    myString& operator=(myString&& obj){
        if (!(this == &obj)){
            if (obj.str == nullptr){
                str = nullptr;
                length = obj.length;
                obj.length = 0;
                return *this;
                }
            if (str != nullptr){
                delete[] str;
            }
            str = obj.str;
            obj.str = nullptr;
            length = obj.length;
            obj.length = 0;
            }
        return *this;
    }
    myString(initializer_list<char> obj){
        length = 0;
        for (auto el : obj){
            str[length] = el;
            length++;
        }
    }
    void Init(){
        char buf[80];
        cout << "Enter a string: ";
        cin.getline(buf, 80);
        if (str != nullptr){
            cout << str << " delete!!!\n";
            delete[] str;
        }
        str = new char[strlen(buf)+ 1];
        strcpy(str, buf);
        
        length = strlen(str);
    }
    void Print(){
        cout << str;
    }
    void MyStrcpy(myString& obj){
        str = new char[strlen(obj.str)+ 1];
        strcpy(str, obj.str);
        length = strlen(str);
    }
    bool MyStrStr(const char* userstr){
        int i = 0;
        int current = 0;
        while(true){
            if (current - 1 == strlen(userstr)){
                return true;
            }
            else if (current == 0 && length == i){
                return false;
            }
            if(userstr[i] != str[current]){
                i++;
                current = 0;
            }
            else if (userstr[i] == str[current]){
                current++;
                i++;
            }
        }
    }
    int MyChr(char c){
        for (int i = 0; i < length; i++){
            if (str[i] == c) return i;
            else i++;
        }
        return -1;
    }
    unsigned long MyStrLen(){
        return length;
    }
    void MyStrCat(myString& b){
        char* buf = new char[b.length + length];
        int i = 0;
        int j = 0;
        while (i <= strlen(buf)){
            if (i != length) buf[i] = str[i];
            else {
                if (j != b.length) buf[i] = b.str[j];
                else break;
            }
        }
    }
    void MyDelChr(char c){
        for (int i = 0; i < length; i++){
            if (str[i] == c){
                str[i] = ' ';
                i++;
            }
            else i++;
        }
    }
    int MyStrCmp(myString &b){
        //-1 – первая строка меньше чем вторая
        //1 – первая больше чем вторая
        //0 – строки равны!
        if (length == b.length) return 0;
        else if (length < b.length) return -1;
        else if (length > b.length) return 1;
        else return -2;
    }
    static void ShowObjects();
};

void myString::ShowObjects(){
    cout << objects;
}
int myString::objects = 0U;

int main() {
    myString s;
    s.Init();
    myString d;
    d.Init();
    s = d;
    s.Print();
    
    char c[] = {'H', 'e', 'l', 'l', 'o'};
    myString st(c);
    st.Print();
}

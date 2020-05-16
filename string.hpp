#ifndef _LU_STRING_H
#define _LU_STRING_H
#include <iostream>

namespace left{
class string{
private:
    char* _data;
    int strlen(const char*)const;
    void strcpy(char*,const char*);
public:
    string(const char* data = 0);
    string(const string&);
    ~string();
    char* data()const{
        return _data;
    }
    string& operator=(const string&);
    
    int length () const{
        return strlen(_data);
    };
};

string::string(const char* data){
    if(data){
        _data = new char[strlen(data)+1];
        strcpy(_data,data);
    }else{
        _data = new char[1];
        *_data = '\0';
    }
}
string::string(const string& str){
    _data = new char[strlen(str._data)+1];
    strcpy(_data,str._data);
}
string& string::operator=(const string& str){
    if(_data=str._data){
        return *this;
    }
    delete[] _data;
    _data = new char[strlen(str._data)+1];
    strcpy(_data,str._data);
    return *this;
}

string::~string(){
    delete[] _data;
}
int string::strlen (const char * chr)const{
    for(int i=0;;++i){
        if(chr[i]=='\0'){
            return i;
        }
    }
    return 0;
}
void string::strcpy(char* ndata,const char* odata){
    for(int i=0;;++i){
        ndata[i] = odata[i];
        if(odata[i]=='\0'){
            break;
        }
    }
}  
}
std::ostream& operator<<(std::ostream& os,const left::string& str){
    return os<<'"'<<str.data()<<'"';
}
#endif
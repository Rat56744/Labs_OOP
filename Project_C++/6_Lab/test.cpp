#include <iostream>
using std::string, std::cout;

class Error:public std::exception
{
private:
    string str;
public:
    string get_str()const{return str;}
    
    Error(string err):str(err){};
    
    Error& operator=(const Error& a){
        str = a.get_str();
        return *this;}

    const char* what() const noexcept override {return str.c_str();}
};

bool is_alphanumeric_string(const string& str) {
  for (size_t i=0; i<str.size();++i) {
    int a = static_cast<int>(static_cast<unsigned char>(str[i]));
    if(a == 208 || a == 209){            
        throw Error("Вы ввели кирилицу! Непозволительная роскошь!");
        return false;
    }
    if (!std::isalnum(str[i])) {
      return false;
    }}
  return true;
}

int main()
{
    std::string str = "kjlsdf";
    std::cout << "Размер строки: "<<str.size();
    try{
        if(!is_alphanumeric_string(str))
        {throw Error("В ведённой строке присутствуют символы кроме цифр и букв!\n");}
    }
    catch(std::length_error&){cout << "Вы ввели слишком много символов! Поле переполнено!\n";
        cout << "Повторите ввод: ";}
    catch(Error& e){cout << "Ошибка: "<< e.what()<<'\n';
        cout << "Повторите ввод: ";}
    is_alphanumeric_string(str);
    // for(int i=0; i<str.size()-1;++i){
    //     std::cout << "Первый байт: " << static_cast<int>(static_cast<unsigned char>(str[i])) <<" "<< "Второй байт: " << static_cast<int>(static_cast<unsigned char>(str[i+1]))<<" ";
    //     ++i;
    // }
    // std::cin >> c;
    // int a = c;
    // std::cout << "Буква в цифрах: "<< a<<std::endl;
}
#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
// проверка, чтобы строка состояла только из прописных букв
bool isValid(const string& s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec; 
    std::wstring ws = codec.from_bytes(s); 
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::wstring wA = codec.from_bytes(numAlpha);
    for(int i = 0; i < ws.size(); i++) {
        if (wA.find(ws[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    string key;
    string text;
    unsigned op;
    
	while(true){
		cout<<"Введите ключ: ";
		cin>>key;
		if (isValid(key)) {
			cout<<"Ключ загружен, продолжаем...\n";
			break;
			
    }else{
		cout<<"Неправильный формат ключа\n";
	}
	}
    
    modAlphaCipher cipher(key);
    do {
        cout<<"Шифр готов. Выберите операцию (0-выход, 1-зашифрование, 2-расшифрование): ";
        cin>>op;
        if (op > 2) {
            cout<<"Некорректная операция\n";
        } else if (op >0) {
            cout<<"Шифр готов. Введите текст: ";
            cin>>text;
            if (isValid(text)) {
                if (op==1) {
                    cout<<"Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else {
                    cout<<"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                cout<<"Операция отклонена. Неправильный формат текста\n";

            }
        }
    } while (op!=0);
    return 0;
}

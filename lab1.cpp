#include <iostream>
#include <string>
using namespace std; 

class Events {
private: 
    string type;
    int box;
    
public:
    Events(string t, int b) {
        type = t;
        box = b;
    }
    
    void outputTo() {
        cout << "Тип мероприятия: " << type << endl;
        cout << "Вместимость: " << box << endl;
    }
    
    string get_type() {
        return type;
    }
    
    void set_type(string t) {
        type = t;
    }
    
    int get_box() {
        return box;
    }
    
    void set_box(int b) {
        box = b;
    }
};

int main() {
    Events Theatre("Опера", 1000);
    Events *Concert = new Events("Симфонический концерт", 500);

    Theatre.outputTo();
    Concert->outputTo();
    
    Theatre.set_box(Theatre.get_box() + 100);

    cout << "Вместимость театра: " << Theatre.get_box() << "\n";
    cout << "Вместимость концерта: " << Concert->get_box() << endl;

    Theatre.outputTo();
    Concert->outputTo();
    
    delete Concert;
    return 0;
}
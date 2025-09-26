#include <iostream>
#include <cmath>
using namespace std;

class Parallelogram {
private:
    double a;
    double b;
    double alfa; 

public:
    Parallelogram(double sideA, double sideB, double angle) : a(sideA), b(sideB), alfa(angle) {}
    void outputTo() {
        cout << "Сторона a: " << a << endl;
        cout << "Сторона b: " << b << endl;
        cout << "Угол alfa: " << alfa << "°" << endl;
        cout << "-----------------------------" << endl;
    }
    bool isSquare() {
        return (a == b) && (alfa == 90.0);
    }
    bool isRectangle() {
        return (alfa == 90.0);
    }
    double get_a() {
        return a;
    }
    void set_a(double sideA) {
        a = sideA;
    }
    double get_b() {
        return b;
    }
    void set_b(double sideB) {
        b = sideB;
    }
    double get_alfa() {
        return alfa;
    }
    void set_alfa(double angle) {
        alfa = angle;
    }
};
int main() {
    int N;
    cout << "Введите количество параллелограммов: ";
    cin >> N;

    Parallelogram** parallelograms = new Parallelogram*[N];
    for (int i = 0; i < N; i++) {
        double a, b, alfa;
        cout << "\nПараллелограмм " << i + 1 << ":" << endl;
        cout << "Введите сторону a: ";
        cin >> a;
        cout << "Введите сторону b: ";
        cin >> b;
        cout << "Введите угол alfa (в градусах): ";
        cin >> alfa;

        parallelograms[i] = new Parallelogram(a, b, alfa);
    }

    int k1 = 0;
    int k2 = 0; 

    cout << "\nРЕЗУЛЬТАТЫ АНАЛИЗА:" << endl;
    cout << "====================" << endl;

    for (int i = 0; i < N; i++) {
        cout << "\nПараллелограмм " << i + 1 << ":" << endl;
        parallelograms[i]->outputTo();
        
        if (parallelograms[i]->isSquare()) {
            cout << "Это КВАДРАТ" << endl;
            k1++;
        } else if (parallelograms[i]->isRectangle()) {
            cout << "Это ПРЯМОУГОЛЬНИК" << endl;
            k2++;
        } else {
            cout << "Это обычный параллелограмм" << endl;
        }
        cout << "-----------------------------" << endl;
    }
    cout << "\nИТОГОВАЯ СТАТИСТИКА:" << endl;
    cout << "====================" << endl;
    cout << "Количество квадратов (k1): " << k1 << endl;
    cout << "Количество прямоугольников (k2): " << k2 << endl;
    cout << "Всего параллелограммов: " << N << endl;

    for (int i = 0; i < N; i++) {
        delete parallelograms[i];
    }
    delete[] parallelograms;
    return 0;
}
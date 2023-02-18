#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<int, double> memory;
map<std::string, int> memoryMapping = {make_pair("M1", 1), make_pair("M2", 2), make_pair("M3", 3), make_pair("M4", 4)};

double readNumber() {
    string num;
    cin >> num;
    if (num == "pi") {
        return 3.14;
    } else if (num == "e") {
        return 2.71;
    }
    if (memoryMapping[num] > 0 && memoryMapping[num] < 5) {
        return memory[memoryMapping[num]];
    } else {
        return stod(num);
    }
}

void saveNumber(double num) {
    cout << num << endl;
    int save;
    cout << "Save result? enter 1 (yes) or 0 (no)" << endl;
    cin >> save;
    if (save == 1) {
        int addr;
        cout << "choose memory address(1,2,3 or 4) or -1 to cancel" << endl;
        cin >> addr;
        if (addr < 0) {
            return;
        }
        if (memoryMapping[to_string(addr)] < 5) {
            string memoryAddr = 'M' + to_string(addr);
            memory[memoryMapping[memoryAddr]] = num;
        } else {
            cout << "error";
            saveNumber(num);
        }
    }
}

double operate(double value1, double value2, char op) {
    switch (op) {
        case '+':
            return value1 + value2;
        case '-':
            return value1 - value2;
        case '/':
            return value1 / value2;
        case '*':
            return value1 * value2;
        default:
            return 0;
    }
}

void task1() {
    double num1;
    double num2;
    char op;
    cout << "enter number 1" << endl;
    num1 = readNumber();
    cout << "enter number 2" << endl;
    num2 = readNumber();
    cout << "enter operator +, -, / or *" << endl;
    cin >> op;
    double result = operate(num1, num2, op);
    saveNumber(result);
}

void task2() {
    double num1;
    string op;
    cout << "enter number" << endl;
    num1 = readNumber();
    cout << "enter sin/cos/tan/cotan" << endl;
    cin >> op;
    map<std::string, int> mapping;
    mapping["cos"] = 1;
    mapping["sin"] = 2;
    mapping["tan"] = 3;
    mapping["cotan"] = 4;
    double result = 0;
    switch (mapping[op]) {
        case 1:
            result = cos(num1);
            break;
        case 2:
            result = sin(num1);
            break;
        case 3:
            result = tan(num1);
            break;
        case 4:
            result = pow(tan(num1), -1);
            break;
        default:
            cout << "error no such operation";
            break;
    }
    saveNumber(result);
    cout << endl;
}

void task3() {
    int num1;
    int num = 0;
    int delta;
    char op;
    cout << "enter operator: < > | & ~ ^" << endl;
    cin >> op;
    cout << "enter number" << endl;
    num1 = (int) readNumber();
    if (op != '~') {
        cout << "enter delta" << endl;
        cin >> delta;
    }
    switch (op) {
        //   ^
        case '^':
            num = num1 ^ delta;
            cout << num;
            break;
            //        >>
        case '<':
            num = num1 << delta;
            cout << num;
            break;
            //        >>
        case '>':
            num = num1 >> delta;
            cout << num;
            break;
//        not
        case '~':
            num = ~num1;
            cout << num;
            break;
//        or
        case '|':
            num = num1 | delta;
            cout << num;
            break;
//            and
        case '&':
            num = num1 & delta;
            cout << num;
            break;
        default:
            cout << "error";
            break;
    }
    saveNumber(num);
}

void task4() {
    double num1;
    double p;
    cout << "enter number" << endl;
    num1 = readNumber();
    cout << "enter power" << endl;
    cin >> p;
    double result = pow(num1, p);
    cout << result << endl;
    saveNumber(result);
}

void task5() {
    double num1;
    double res;
    int i;
    cout << "enter number" << endl;
    num1 = readNumber();
    res = 1;
    for (i = 1; i <= num1; i++) {
        res = res * i;
    }
    cout << res << endl;
}

void task6() {
    double num1;
    cout << "enter number\n";
    num1 = readNumber();
    double result = std::log(num1);
    cout << result;
    saveNumber(result);
}

int nod(int n1, int n2) {
    int div;
    if (n1 == n2) return n1;
    int d = n1 - n2;
    if (d < 0) {
        d = -d;
        div = nod(n1, d);
    } else
        div = nod(n2, d);
    return div;
}

int nok(int n1, int n2) {
    return n1 * n2 / nod(n1, n2);
}

void task7() {
    int num1;
    int num2;
    cout << "enter number 1\n";
    num1 = (int) readNumber();
    cout << "enter number 2\n";
    num2 = (int) readNumber();
    map<std::string, int> mapping;
    mapping["nok"] = 1;
    mapping["nod"] = 2;
    string op;
    cout << "nok or nod?" << endl;
    cout << op;
    double result = 0;
    switch (mapping[op]) {
        case 1:
            result = nod(num1, num2);
            break;
        case 2:
            result = nok(num1, num2);
            break;
        default:
            cout << "error";
            break;
    }
    saveNumber(result);
}

char digit(int num) {
//    преобразование числа
    switch (num) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        case 16:
            return 'G';
        case 17:
            return 'H';
        case 18:
            return 'I';
        case 19:
            return 'J';
        case 20:
            return 'K';
        case 21:
            return 'L';
        case 22:
            return 'M';
        case 23:
            return 'N';
        case 24:
            return 'O';
        case 25:
            return 'P';
        case 26:
            return 'Q';
        case 27:
            return 'R';
        case 28:
            return 'S';
        case 29:
            return 'T';
        case 30:
            return 'U';
        case 31:
            return 'V';
        case 32:
            return 'W';
        case 33:
            return 'X';
        case 34:
            return 'Y';
        case 35:
            return 'Z';
        default:
            return '-';
    }
}

int convert(int num, int p, char *s) {
//    вычисление остатка
    int rest = num % p;
//    получение частного
    num /= p;
//    если частное равно 0, то число переведено в другую СЧ(рекурсия закончилась)
    if (num == 0) {
//        запись 1 числа в массив
        s[0] = digit(rest);
        return 1;
    }
//    рекурсивно вызываем перевод
    int k = convert(num, p, s);
    s[k] = digit(rest);
    k++;
    return k;
}

void task9() {
    int num1;
    char s[100] = {};
    int p;
    cout << "enter number: " << endl;
    num1 = (int) readNumber();
    cout << "Enter the base of the number: " << endl;
    cin >> p;
    double result = convert(num1, p, s);
    cout << s;
    saveNumber(result);
}

void task10() {
    double num1;
    int n;
    double s;
    cout << "enter length\n";
    cin >> num1;
    cout << "enter number of sides\n";
    cin >> n;
    s = (n * num1 * num1) / (4 * std::tan((180 * (3.14 / 180)) / n));
    cout << s;
    saveNumber(s);
}

void task11() {
    std::cout << "Enter A, B, C:\n";
    double A = 0.0, B = 0.0, C = 0.0;
    std::cin >> A >> B >> C;
    double x1, x2;
    if ((B * B - 4 * A * C) >= 0 && A != 0) {
        x1 = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
        std::cout << "x1 = " << x1 << std::endl;
        x2 = (-B - sqrt(B * B - 4 * A * C) / (2 * A));
        std::cout << "x2 = " << x2 << std::endl;
    } else if (A == 0)
        std::cout << (-1) * (C / B) << std::endl;
    else
        std::cout << "No roots\n";
}

void task12() {
    int l = 0, r = 0, num;
    cout << "Enter range:\n";
    cin >> l >> r;
    num = rand() % (abs(l) + r);
    cout << num;
    saveNumber(num);
}

//const int N = 3;

// Получение матрицы без i-й строки и j-го столбца
void getMatr(double **A, double **P, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
            if (kj == j) dj = 1;
            P[ki][kj] = A[ki + di][kj + dj];
        }
    }
}

// Рекурсивное вычисление определителя
double determinant(double **A, int m) {
    int i, j, k, n;
    double d;
    auto **p = new double *[m];
    for (i = 0; i < m; ++i)
        p[i] = new double[m];
//    p = new double *[m];
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            p[i][j] = 0.0;
    d = 0;
    k = 1; //(-1) в степени i
    n = m - 1;
    if (m < 1) cout << "Определитель вычислить невозможно";
    if (m == 1) {
        d = A[0][0];
        return (d);
    }
    if (m == 2) {
        d = A[0][0] * A[1][1] - (A[1][0] * A[0][1]);
        return (d);
    }
    if (m > 2) {
        for (i = 0; i < m; i++) {
            getMatr(A, p, i, 0, m);
            d = d + k * A[i][0] * determinant(p, n);
            k = -k;
        }
    }
    return (d);
}

void kramer() {
    cout << "enter matrix size" << endl;
    int N;
    cin >> N;
    auto **A = new double *[N];
    for (int i = 0; i < N; ++i)
        A[i] = new double[N];
    double B[N];
//            {
//                    160, 12, 60,
//                    40, 25, -330,
//                    30, 50, -110
//            };

//            {
//                    81,
//                    60,
//                    90
//            };
//заполнение двухмерной матрицы (построчно)
    cout << "enter matrix A" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
//    заполнение матрицы с правой частью уравнений
    cout << "enter matrix B" << endl;
    for (int i = 0; i < N; i++)
        cin >> B[i];
//    вычисление определителя матрицы
    double detA = determinant(A, N);
    double X[N];
    auto **T = new double *[N];
    for (int i = 0; i < N; ++i)
        T[i] = new double[N];
    int n;
    int i, j;
    for (n = 0; n < N; n++) {
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                T[i][j] = A[i][j];

        for (j = 0; j < N; j++)
            T[j][n] = B[j];

        X[n] = determinant(T, N) / detA;
    }
    for (i = 0; i < N; i++)
        printf("X[%d] = %.4f\t", i, X[i]);
    cout << endl;
}

int main() {
    for (int i = 0; i < 4; ++i) {
        memory[i] = 0;
    }
    string task;
    map<std::string, int> mapping;
    mapping["1"] = 1;
    mapping["2"] = 2;
    mapping["3"] = 3;
    mapping["4"] = 4;
    mapping["5"] = 5;
    mapping["6"] = 6;
    mapping["7"] = 7;
    mapping["9"] = 9;
    mapping["10"] = 10;
    mapping["11"] = 11;
    mapping["12"] = 12;
    mapping["13"] = 13;
    mapping["14"] = 14;
    while (true) {
        cout << "Choose what to do:" << endl;
        cout << "1) Perform arithmetic calculations (addition, subtraction, etc.)\n"
                "2) Perform trigonometric calculations (sin, cos, etc.)\n"
                "3) Perform bitwise logical calculations (bitwise and, bitwise OR etc.)\n"
                "4) Calculate the power of the number\n"
                "5) Calculate the factorial\n"
                "6) Calculate the natural logarithm\n"
                "7) Find the NOC and NOD of two numbers\n"
                "8) Work with mathematical constants (e, π, etc.)\n"
                "9) Be able to convert a number from a user\n"
                "-defined number system to another (both can be arbitrary, but\n"
                "less than 48-ch)\n"
                "10) Find the area of a regular n-gon on a given side\n"
                "11) Find the roots of the quadratic equation by the given coefficients\n"
                "12) Be able to generate a pseudo-random number in a user-defined range\n"
                "13) Solving matrix\n"
                "14) Exit" << endl;
        cin >> task;
        int value = mapping[task];
        if (value == 14) {
            break;
        }
        switch (mapping[task]) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
                break;
            case 9:
                task9();
                break;
            case 10:
                task10();
                break;
            case 11:
                task11();
                break;
            case 12:
                task12();
                break;
            case 13:
                kramer();
                break;
            default:
                break;
        }
    }
    return 0;
}


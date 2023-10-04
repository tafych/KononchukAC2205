#include <iostream>
#include <vector>
#include<string>
#include<cmath>
#include <fstream>
#include<sstream>
using namespace std;
void intCheck(int& intt, int min, int max)
{
    while (!(std::cin >> intt) or intt > max or intt < min) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
}
void posFloatCheck(float& floatt)
{
    while (!(std::cin >> floatt) or floatt < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
}
void floatCheck(float& floatt)
{
    while (!(std::cin >> floatt)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
}
void boolCheck(bool& booll)
{
    while (!(std::cin >> booll)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
}
struct pipe
{
    string Name;
    float Length;
    float Diameter;
    bool InMaintenance;
};
struct KS
{
    string Name;
    int AllMachines;
    int WorkingMachines;
    float Productivity;
    float Efficiency() {
        return pow(WorkingMachines * Productivity, 0.66);
    }
};
vector<pipe> pipes;
vector<KS> KSs;
vector<int> HLP;
vector<int> HLK;
bool toDelP(pipe p){
    return find(HLP.begin(), HLP.end(), stoi(p.Name)) != HLP.end();
}
bool toDelK(KS k) {
    return find(HLK.begin(), HLK.end(), stoi(k.Name)) != HLK.end();
}
void highLightPinp() {
    cout << "Which ones?" << endl;
    string word;
    int beg, end;
    char s[255];
    cin.getline(s, 255, '!');
    stringstream ss(s);
    while (ss >> word) {
        if (word == "i") {
            if (!(ss >> beg)) {
                cout << "Input incorrect." << endl;
                HLP.clear();
                break;
            };
            if (!(ss >> end) or beg > end) {
                cout << "Input incorrect." << endl;
                HLP.clear();
                break;
            };
            if (end > pipes.size()) {
                cout << "Input incorrect." << endl;
                HLP.clear();
                break;
            };
            for (int i = beg;i < end + 1;i++) {
                HLP.push_back(i);
            };
        }
        else {
            try {
                if (stoi(word)>pipes.size()-1) {
                    cout << "Input incorrect." << endl;
                    HLP.clear();
                    break;
                }
                else {
                    HLP.push_back(stoi(word));
                }
            }
            catch (...) {
                cout << "Input incorrect." << endl;
                HLP.clear();
                break;
            };
        };
    }
}
void highLightKinp() {
    cout << "Which ones?" << endl;
    string word;
    int beg, end;
    char s[255];
    cin.getline(s, 255, '!');
    stringstream ss(s);
    while (ss >> word) {
        if (word == "i") {
            if (!(ss >> beg)) {
                cout << "Input incorrect." << endl;
                HLK.clear();
                break;
            };
            if (!(ss >> end) or beg > end) {
                cout << "Input incorrect." << endl;
                HLK.clear();
                break;
            };
            if (end > KSs.size()) {
                cout << "Input incorrect." << endl;
                HLK.clear();
                break;
            };
            for (int i = beg;i < end + 1;i++) {
                HLK.push_back(i);
            };
        }
        else {
            try {
                if (stoi(word) > KSs.size() - 1) {
                    cout << "Input incorrect." << endl;
                    HLK.clear();
                    break;
                }
                else {
                    HLK.push_back(stoi(word));
                }
            }
            catch (...) {
                cout << "Input incorrect." << endl;
                HLK.clear();
                break;
            };
        };
    }
}
//1
void addPipe(vector<pipe>& vec, string n, float l, float d, bool m)
{
    pipe newPipe{n,l,d,m};
    vec.push_back(newPipe);
}
void addPipes() {
    cout << "How many: ";
    int amo;
    intCheck(amo, 0, 2147483647);
    for (int i = 0;i < amo;i++) {
        addPipe(pipes, to_string(pipes.size()), 0, 0, 0);
    }
}
//2
void addKS(vector<KS>& vec, string n, float am, float wm, float p)
{
    KS newKS{n,am,wm,p};
    vec.push_back(newKS);
}
void addKSs() {
    cout << "How many: ";
    int amo;
    intCheck(amo, 0, 2147483647);
    for (int i = 0;i < amo;i++) {
        addKS(KSs, to_string(KSs.size()), 0, 0, 0);
    }
}
void menu()
{
    cout << "1 - add pipe\n" << "2 - add KS\n" << "3 - show all\n" << "4 - edit pipe\n" << "5 - edit KS\n" << "6 - save\n" << "7 - load\n" << "8 - highlite and delete pipes\n" << "9 - highlite and delete KSs\n" << "Input 0 or any non-integer to exit\n\nInput option:";
}
//3
void oAll() {
    cout << "All Pipes:\n";
    for (int i = 0; i < pipes.size(); i++) {
        cout << "Name: " << pipes[i].Name << "; Length: " << pipes[i].Length << "; Diameter: " << pipes[i].Diameter << "; Under Maintenace: " << pipes[i].InMaintenance << endl;
    };
    cout << "All KSs:\n";
    for (int i = 0; i < KSs.size(); i++) {
        cout << "Name: " << KSs[i].Name << "; All Machines: " << KSs[i].AllMachines << "; Working Machines: " << KSs[i].WorkingMachines << "; Machine Productivity: " << KSs[i].Productivity << "; KS Efficiency:" << KSs[i].Efficiency() << endl;
    };
}
//4
void rePipe() {
    bool m;
    float l, d;
    cout << "Length: ";
    posFloatCheck(l);
    cout << "Diameter: ";
    posFloatCheck(d);
    cout << "Under Maintenance: ";
    boolCheck(m);
    for (int i=0;i < HLP.size();i++) {
        pipes[HLP[i]].Length = l;
        pipes[HLP[i]].Diameter = d;
        pipes[HLP[i]].InMaintenance = m;
    };
}
//5
void reKS() {
    float am,wm,p;
    cout << "All Machines: ";
    posFloatCheck(am);
    cout << "Working Machines: ";
    posFloatCheck(wm);
    cout << "Machine Productivity: ";
    floatCheck(p);
    for (int i = 0;i < HLK.size();i++) {
        KSs[HLK[i]].AllMachines = am;
        KSs[HLK[i]].WorkingMachines = wm;
        KSs[HLK[i]].Productivity = p;
    };
}
//6
void sAll() {
    cout << "Input File Name (with .txt extension): ";
    string fname;
    cin >> fname;
    ofstream saveFile(fname);
    saveFile << pipes.size() << ' ';
    for (int i = 0;i < pipes.size();i++) {
        saveFile << pipes[i].Name << ' ' << pipes[i].Length << ' ' << pipes[i].Diameter << ' ' << pipes[i].InMaintenance << ' ';
    }
    saveFile << KSs.size() << ' ';
    for (int i = 0;i < KSs.size();i++) {
        saveFile << KSs[i].Name << ' ' << KSs[i].AllMachines << ' ' << KSs[i].WorkingMachines << ' ' << KSs[i].Productivity << ' ';
    }
    saveFile.close();
}
//7
void lAll() {
    string fname;
    pipes.clear();
    KSs.clear();
    cout << "Input File Name (with .txt extension): ";
    cin >> fname;
    ifstream loadFile(fname);
    int amo;
    vector<string> nums;
    loadFile >> amo;
    string n;
    float f1, f2, f3;
    bool b;
    for (int i = 0;i < amo;i++) {
        loadFile >> n >> f1 >> f2 >> b;
        addPipe(pipes, n, f1, f2, b);
    }
    loadFile >> amo;
    for (int i = 0;i < amo;i++) {
        loadFile >> n >> f1 >> f2 >> f3;
        addKS(KSs, n, f1, f2, f3);
    }
}
int main()
//8
//9
{
    int option = 15;
    while (option != 0) {
        cout << "-----~~~~===#(0)#===~~~~-----\n";
        menu();
        cin >> option;
        switch (option) {
            //1 - Добавить пустую трубу 
        case 1:
        {
            addPipes();
        }
        break;
        //2 - Добавить пустую КС
        case 2:
        {
            addKSs();
        }
        break;
        //3 - Вывести все элементы
        case 3:
        {
            oAll();
        }
        break;
        //4 - Редактировать трубу
        case 4:
        {
            highLightPinp();
            rePipe();
        }
        break;
        //5 - Редактировать КС
        case 5:
        {
            highLightKinp();
            reKS();
        }
        break;
        //6 - Сохранить всё
        case 6:
        {
            sAll();}
        break;
        //7 - Загрузить
        case 7:
        {
            lAll();}
        break;
        case 8:
        {
            HLP.clear();
            highLightPinp();
            vector<pipe>::iterator it;
            it = remove_if(pipes.begin(), pipes.end(), toDelP);
            pipes.erase(it, pipes.end());
        }
        break;
        case 9:
        {
            HLK.clear();
            highLightKinp();
            vector<KS>::iterator it;
            it = remove_if(KSs.begin(), KSs.end(), toDelK);
            KSs.erase(it, KSs.end());
        }
        break;
        }
    }
}
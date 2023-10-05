#include <iostream>
#include <vector>
#include<string>
#include<cmath>
#include <fstream>
#include<sstream>
#include<algorithm>
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
    HLP.clear();
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
    sort(HLP.begin(), HLP.end());
    auto last = unique(HLP.begin(), HLP.end());
    HLP.erase(last, HLP.end());
}
void highLightKinp() {
    HLK.clear();
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
    sort(HLK.begin(), HLK.end());
    auto last = unique(HLK.begin(), HLK.end());
    HLK.erase(last, HLK.end());
}
void menu()
{
    cout << "1 - add pipe\n" << "2 - add KS\n" << "3 - show highlited\n" << "4 - highlight pipes\n" << "5 - highlite KSs\n" << "6 - edit highlited pipes\n" << "7 - edit highlited KSs\n" << "8 - delete highlited pipes\n" << "9 - delete highlited KSs\n" << "Input 0 or any non-integer to exit\n\nInput option:";
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
        addPipe(pipes, to_string(pipes.size()), 10, 10, 0);
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
        addKS(KSs, to_string(KSs.size()), 10, 10, 10);
    }
}
//3
void oAll() {
    cout << "Pipes:\n";
    for (int i = 0; i < HLP.size(); i++) {
        cout << "Name: " << pipes[HLP[i]].Name << "; Length: " << pipes[HLP[i]].Length << "; Diameter: " << pipes[HLP[i]].Diameter << "; Under Maintenace: " << pipes[HLP[i]].InMaintenance << endl;
    };
    cout << "KSs:\n";
    for (int i = 0; i < HLK.size(); i++) {
        cout << "Name: " << KSs[HLK[i]].Name << "; All Machines: " << KSs[HLK[i]].AllMachines << "; Working Machines: " << KSs[HLK[i]].WorkingMachines << "; Machine Productivity: " << KSs[HLK[i]].Productivity << "; KS Efficiency:" << KSs[HLK[i]].Efficiency() << endl;
    };
}
//4
void HLPipes() {
    HLP.clear();
    int opti;
    cout << "1 - all pipes\n2 - choose by name\n3 - choose by maintenance\n";
    intCheck(opti, 1, 3);
    switch (opti) {
    case 1:
    {
        for (int i = 0;i < pipes.size();i++) {
            HLP.push_back(i);
        }
    }
    break;
    case 2:
    {
        highLightPinp();
    }
    break;
    case 3:
    {
        cout << "In Maintenance?\n";
        bool im;
        boolCheck(im);
        for (int i = 0;i < pipes.size();i++) {
            if (pipes[i].InMaintenance == im) {
                HLP.push_back(i);
            }
        }
    }
    break;
    }
}
//5
void HLKSs() {
    HLK.clear();
    int opti;
    cout << "1 - all KSs\n2 - choose by name\n3 - choose by % of machines working\n";
    intCheck(opti, 1, 3);
    switch (opti) {
    case 1:
    {
        for (int i = 0;i < KSs.size();i++) {
            HLK.push_back(i);
        }
    }
    break;
    case 2:
    {
        highLightKinp();
    }
    break;
    case 3:
    {
        cout << "% of machines working (higher or equal): \n";
        float pom;
        posFloatCheck(pom);
        if (pom < 0 or pom>100) {
            posFloatCheck(pom);
        }
        for (int i = 0;i < KSs.size();i++) {
            float del = (KSs[i].WorkingMachines / KSs[i].AllMachines) * 100;
            if (del >= pom) {
                HLK.push_back(i);
            }
        }
    }
    break;
    }
}
//6

void rePipe() {
    bool m;
    float l, d;
    cout << "Length: ";
    posFloatCheck(l);
    cout << "Diameter: ";
    posFloatCheck(d);
    cout << "Under Maintenance: ";
    boolCheck(m);
    for (int i = 0;i < HLP.size();i++) {
        pipes[HLP[i]].Length = l;
        pipes[HLP[i]].Diameter = d;
        pipes[HLP[i]].InMaintenance = m;
    };
}
//7
void reKS() {
    float am, wm, p;
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
//8
void delHLP() {
    vector<pipe>::iterator it;
    it = remove_if(pipes.begin(), pipes.end(), toDelP);
    pipes.erase(it, pipes.end());
    for (int i = 0;i < pipes.size();i++) {
        pipes[i].Name = to_string(i);
    }
    HLP.clear();
}
//9
void delHLK() {
    vector<KS>::iterator it;
    it = remove_if(KSs.begin(), KSs.end(), toDelK);
    KSs.erase(it, KSs.end());
    for (int i = 0;i < KSs.size();i++) {
        KSs[i].Name = to_string(i);
    }
    HLK.clear();
}
//10
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
//11
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
        //3 - Вывести выделенные элементы
        case 3:
        {
            oAll();
        }
        break;
        //4 - Выделить нужные трубы
        case 4:
        {
            HLPipes();
        }
        break;
        //5 - Выделить нужные КС
        case 5:
        {
            HLKSs();
        }
        break;
        //6 - Редактировать выделенные трубы
        case 6:
        {
            rePipe();
            ;}
        break;
        //7 - Редактировать выделенные КС
        case 7:
        {
            reKS();
            ;}
        break;
        //8 - удалить выделенные трубы
        case 8:
        {
            delHLP();
        }
        break;
        //9 - удалить выделенные КС
        case 9:
        {
            delHLK();
        }
        break;
        //10 - сохранить всё
        case 10:
        {
            sAll();
        }
            break;
        //11 - загрузить всё
        case 11:
        {
            lAll();
        }
            break;
        }
    }
}
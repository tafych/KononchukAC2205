#include <iostream>
#include <vector>
#include<string>
#include<cmath>
#include <fstream>
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
//1
void addPipe(vector<pipe>& vec, string n, float l, float d, bool m)
{
    pipe newPipe{n,l,d,m};
    vec.push_back(newPipe);
}
//2
void addKS(vector<KS>& vec, string n, float am, float wm, float p)
{
    KS newKS{n,am,wm,p};
    vec.push_back(newKS);
}
void menu()
{
    cout << "1 - add pipe\n" << "2 - add KS\n" << "3 - show all\n" << "4 - edit pipe\n" << "5 - edit KS\n" << "6 - save\n" << "7 - load\n" << "Input 0 or any non-integer to exit\n\nInput option:";
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
    int i;
    cout << "Pipe #: ";
    intCheck(i, -1, pipes.size() - 1);
    cout << "Length: ";
    posFloatCheck(pipes[i].Length);
    cout << "Diameter: ";
    posFloatCheck(pipes[i].Diameter);
    cout << "Under Maintenance: ";
    boolCheck(pipes[i].InMaintenance);
}
//5
void reKS() {
    int i;
    cout << "KS #: ";
    intCheck(i, -1, KSs.size() - 1);
    cout << "All Machines: ";
    intCheck(KSs[i].AllMachines, -1, 20);
    cout << "Working Machines: ";
    intCheck(KSs[i].WorkingMachines, -1, KSs[i].AllMachines);
    cout << "Machine Productivity: ";
    floatCheck(KSs[i].Productivity);
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
{
    int option = 10;
    while (option != 0) {
        cout << "-----~~~~===#(0)#===~~~~-----\n";
        menu();
        cin >> option;
        switch (option) {
            //1 - Добавить пустую трубу 
        case 1:
        {
            addPipe(pipes, to_string(pipes.size()), 0, 0, 0);}
        break;
        //2 - Добавить пустую КС
        case 2:
        {
            addKS(KSs, to_string(KSs.size()), 0, 0, 0);}
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
            rePipe();
        }
              break;
              //5 - Редактировать КС
        case 5: 
        {
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
        }
    }
}
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
void addPipe(vector<pipe>& vec, string n, float l, float d, bool m)
{
    pipe newPipe;
    newPipe.Name = n;
    newPipe.Length = l;
    newPipe.Diameter = d;
    newPipe.InMaintenance = m;
    vec.push_back(newPipe);
}
void addKS(vector<KS>& vec, string n, float am, float wm, float p)
{
    KS newKS;
    newKS.Name = n;
    newKS.AllMachines = am;
    newKS.WorkingMachines = wm;
    newKS.Productivity = p;
    vec.push_back(newKS);
}
void menu()
{
    cout << "1 - add pipe\n" << "2 - add KS\n" << "3 - show all\n" << "4 - edit pipe\n" << "5 - edit KS\n" << "6 - save\n" << "7 - load\n" << "Input 0 or any non-integer to exit\n\nInput option:";
}
//1 добавить трубу
//2 добавить кс
//3 все объекты
//4 редактировать трубу
//5 редактировать кс
//6 сохранить
//7 загрузить
//0 выход
int main()
{
    vector<pipe> pipes;
    vector<KS> KSs;
    pipe np;
    pipe dp;
    KS nK;
    int option = 10, i;
    string fname;
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
        case 2: {
            addKS(KSs, to_string(KSs.size()), 0, 0, 0);}
              break;
              //3 - Вывести все элементы
        case 3: {
            cout << "All Pipes:\n";
            for (int i = 0; i < pipes.size(); i++) {
                cout << "Name: " << pipes[i].Name << "; Length: " << pipes[i].Length << "; Diameter: " << pipes[i].Diameter << "; Under Maintenace: " << pipes[i].InMaintenance << endl;
            };
            cout << "All KSs:\n";
            for (int i = 0; i < KSs.size(); i++) {
                cout << "Name: " << KSs[i].Name << "; All Machines: " << KSs[i].AllMachines << "; Working Machines: " << KSs[i].WorkingMachines << "; Machine Productivity: " << KSs[i].Productivity << "; KS Efficiency:" << KSs[i].Efficiency() << endl;
            };}
              break;
              //4 - Редактировать трубу
        case 4: {
            cout << "Pipe #: ";
            intCheck(i, -1, pipes.size() - 1);
            cout << "Length: ";
            posFloatCheck(pipes[i].Length);
            cout << "Diameter: ";
            posFloatCheck(pipes[i].Diameter);
            cout << "Under Maintenance: ";
            boolCheck(pipes[i].InMaintenance);
        }
              break;
              //5 - Редактировать КС
        case 5: {
            cout << "KS #: ";
            intCheck(i, -1, KSs.size() - 1);
            cout << "All Machines: ";
            intCheck(KSs[i].AllMachines, -1, 20);
            cout << "Working Machines: ";
            intCheck(KSs[i].WorkingMachines, -1, KSs[i].AllMachines);
            cout << "Machine Productivity: ";
            floatCheck(KSs[i].Productivity);
        }
              break;
              //6 - Сохранить всё
        case 6: {
            cout << "Input File Name (with .txt extension): ";
            cin >> fname;
            ofstream saveFile(fname);
            saveFile << pipes.size() << endl;
            for (int i = 0;i < pipes.size();i++) {
                saveFile << pipes[i].Name << endl << pipes[i].Length << endl << pipes[i].Diameter << endl << pipes[i].InMaintenance << endl;
            }
            saveFile << KSs.size() << endl;
            for (int i = 0;i < KSs.size();i++) {
                saveFile << KSs[i].Name << endl << KSs[i].AllMachines << endl << KSs[i].WorkingMachines << endl << KSs[i].Productivity << endl;
            }
            saveFile.close();}
              break;
              //7 - Загрузить
        case 7: {
            pipes.clear();
            KSs.clear();
            cout << "Input File Name (with .txt extension): ";
            cin >> fname;
            ifstream loadFile(fname);
            string line;
            getline(loadFile, line);
            int numOfPipes = stoi(line);
            for (int i = 0;i < numOfPipes;i++) {
                getline(loadFile, line);
                np.Name = line;
                getline(loadFile, line);
                np.Length = stof(line);
                getline(loadFile, line);
                np.Diameter = stof(line);
                getline(loadFile, line);
                np.InMaintenance = !!stoi(line);
                pipes.push_back(np);
            }
            getline(loadFile, line);
            int numOfKSs = stoi(line);
            for (int i = 0;i < numOfKSs;i++) {
                getline(loadFile, line);
                nK.Name = line;
                getline(loadFile, line);
                nK.AllMachines = stoi(line);
                getline(loadFile, line);
                nK.WorkingMachines = stoi(line);
                getline(loadFile, line);
                nK.Productivity = stof(line);
                KSs.push_back(nK);
            }
            loadFile.close();}
              break;
        }
    }
}
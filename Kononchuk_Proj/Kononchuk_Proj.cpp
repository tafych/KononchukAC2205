#include <iostream>
#include <vector>
#include<string>
#include<cmath>
#include <fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<map>

using namespace std;
void slog() {}
void logg(char const* func, char const* tosay, long line) {
    cerr <<tosay<<" " << func << " at " << line << endl;
    slog();
}
#define slog() logg(__func__,"Entered",__LINE__)
#define elog() logg(__func__,"Exited",__LINE__)
void intCheck(int& intt, int min, int max)
{
    slog();
    while (!(std::cin >> intt) or intt > max or intt < min) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    elog();
}
void posFloatCheck(float& floatt)
{
    slog();
    while (!(std::cin >> floatt) or floatt < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
    elog();
}
void floatCheck(float& floatt)
{
    slog();
    while (!(std::cin >> floatt)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
    elog();
}
void boolCheck(bool& booll)
{
    slog();
    while (!(std::cin >> booll)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please re-enter.\n";
    }
    elog();
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
//bool toDelP(vector<int>& HLP, pipe p) {
//    return find(HLP.begin(), HLP.end(), stoi(p.Name)) != HLP.end();
//}
//bool toDelK(vector<int>& HLK, KS k) {
//    return find(HLK.begin(), HLK.end(), stoi(k.Name)) != HLK.end();
//}
void highLightPinp(vector<pipe> pipes, vector<int>& HLP) {
    slog();
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
                if (stoi(word) > pipes.size() - 1) {
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
    elog();
}
void highLightKinp(vector<KS> KSs, vector<int>& HLK) {
    slog();
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
    elog();
}
void menu()
{
    slog();
    cout << "1 - add pipe\n"
        << "2 - add KS\n"
        << "3 - add unique pipe\n"
        << "4 - add unique KS\n"
        << "5 - show highlited\n"
        << "6 - highlight pipes\n"
        << "7 - highlite KSs\n" 
        <<"8 - edit highlited pipes\n"
        << "9 - edit highlited KSs\n"
        << "10- delete highlited pipes\n" 
        << "11 - delete highlited KSs\n" 
        << "Input 0 to exit\n\nInput option:";
    elog();
}
//1
void addPipe(vector<pipe>& vec, string n, float l, float d, bool m)
{
    slog();
    pipe newPipe{ n,l,d,m };
    vec.push_back(newPipe);
    elog();
}
void addPipes(vector<pipe>& pipes) {
    slog();
    cout << "How many: ";
    int amo;
    intCheck(amo, 0, 2147483647);
    for (int i = 0;i < amo;i++) {
        addPipe(pipes, to_string(pipes.size()), 10, 10, 0);
    }
    elog();
}
void addSpecialPipe(vector<pipe>& pipes) {
    slog();
    float l, d;
    bool m;
    cout << "Length: " << endl;
    posFloatCheck(l);
    cout << "Diameter: " << endl;
    posFloatCheck(d);
    cout << "In maintenance: " << endl;
    boolCheck(m);
    addPipe(pipes, to_string(pipes.size()), l, d, m);
    elog();
}
//2
void addKS(vector<KS>& vec, string n, float am, float wm, float p)
{
    slog();
    KS newKS{ n,am,wm,p };
    vec.push_back(newKS);
    elog();
}
void addKSs(vector<KS>& KSs) {
    slog();
    cout << "How many: ";
    int amo;
    intCheck(amo, 0, 2147483647);
    for (int i = 0;i < amo;i++) {
        addKS(KSs, to_string(KSs.size()), 10, 10, 10);
    }
    elog();
}
void addSpecialKS(vector<KS>& KSs) {
    slog();
    float am, wm,p;
    cout << "All machines: " << endl;
    posFloatCheck(am);
    cout << "Working machines: " << endl;
    posFloatCheck(wm);
    cout << "Productivity: " << endl;
    posFloatCheck(p);
    addKS(KSs, to_string(KSs.size()), am, wm, p);
    elog();
}
/*
void connectKSs(vector<KS>& KSs, vector<node>& nodes, int n1, int n2) {
    if (find(nodes.begin(), nodes.end(), n1) == nodes.end()) {
        nodes.push_back(n1);
    }
    //  find(vec.begin(), vec.end(), item) != vec.end()
}
*/
//3
void oAll(vector<pipe>& pipes, vector<KS>& KSs, vector<int>& HLP, vector<int>& HLK) {
    slog();
    cout << "Pipes:\n";
    for (int i = 0; i < HLP.size(); i++) {
        cout << "Name: " << pipes[HLP[i]].Name << "; Length: " << pipes[HLP[i]].Length << "; Diameter: " << pipes[HLP[i]].Diameter << "; Under Maintenace: " << pipes[HLP[i]].InMaintenance << endl;
    };
    cout << "KSs:\n";
    for (int i = 0; i < HLK.size(); i++) {
        cout << "Name: " << KSs[HLK[i]].Name << "; All Machines: " << KSs[HLK[i]].AllMachines << "; Working Machines: " << KSs[HLK[i]].WorkingMachines << "; Machine Productivity: " << KSs[HLK[i]].Productivity << "; KS Efficiency:" << KSs[HLK[i]].Efficiency() << endl;
    };
    elog();
}
//4
void HLPipes(vector<pipe> pipes,vector<int>& HLP) {
    slog();
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
        highLightPinp(pipes,HLP);
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
    elog();
}
//5
void HLKSs(vector<KS> KSs,vector<int>& HLK) {
    slog();
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
        highLightKinp(KSs,HLK);
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
    elog();
}
//6

void rePipe(vector<pipe>& pipes, vector<int>& HLP) {
    slog();
    bool m;
    //float l, d;
    /*cout << "Length: ";
    posFloatCheck(l);
    cout << "Diameter: ";
    posFloatCheck(d);*/
    cout << "Under Maintenance: ";
    boolCheck(m);
    for (int i = 0;i < HLP.size();i++) {
        //pipes[HLP[i]].Length = l;
        //pipes[HLP[i]].Diameter = d;
        pipes[HLP[i]].InMaintenance = m;
    };
    elog();
}
//7
void reKS(vector<KS>& KSs, vector<int>& HLK) {
    slog();
    //float am, wm, p;
    float wm;
    //cout << "All Machines: ";
    //posFloatCheck(am);
    cout << "Working Machines: ";
    posFloatCheck(wm);
    //cout << "Machine Productivity: ";
    //floatCheck(p);
    for (int i = 0;i < HLK.size();i++) {
        //KSs[HLK[i]].AllMachines = am;
        KSs[HLK[i]].WorkingMachines = wm;
        //KSs[HLK[i]].Productivity = p;
    };
    elog();
}
//8
void delHLP(vector<pipe>& pipes, vector<int>& HLP) {
    slog();
    vector<pipe>::iterator it;
    it = remove_if(pipes.begin(), pipes.end(), [=](pipe p){
        return find(HLP.begin(), HLP.end(), stoi(p.Name)) != HLP.end();
        });
    pipes.erase(it, pipes.end());
    for (int i = 0;i < pipes.size();i++) {
        pipes[i].Name = to_string(i);
    }
    HLP.clear();
    elog();
}
//9
void delHLK(vector<KS>& KSs, vector<int>& HLK) {
    slog();
    vector<KS>::iterator it;
    it = remove_if(KSs.begin(), KSs.end(), [=](KS k) {
        return find(HLK.begin(), HLK.end(), stoi(k.Name)) != HLK.end();
        });
    KSs.erase(it, KSs.end());
    for (int i = 0;i < KSs.size();i++) {
        KSs[i].Name = to_string(i);
    }
    HLK.clear();
    elog();
}
//10
void sAll(vector<pipe>& pipes, vector<KS>& KSs) {
    slog();
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
    elog();
}
//11
void lAll(vector<pipe>& pipes, vector<KS>& KSs) {
    slog();
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
    elog();
}

void createCons(vector<vector<int>>& cons, vector<KS>& KSs) {
    vector<int> dd;
    for (int i = 0;i < KSs.size(); i++) {
        dd.push_back(0);
    }
    for (int i = 0;i < KSs.size(); i++) {
        cons.push_back(dd);
    }
}

void connect(vector<vector<int>>& cons, int oKS, int iKS, int pipe) {

}

int main()
{
    freopen("log.txt", "w", stderr);
    vector<pipe> pipes;
    vector<KS> KSs;
    vector<int> HLP;
    vector<int> HLK;
    vector<vector<int>> connections;
    int option = 15;
    while (option != 0) {
        cout << "-----~~~~===#(0)#===~~~~-----\n";
        menu();
        intCheck(option,0,14);

        switch (option) {
        case 0:
        {
            cout << "Are you sure you want to exit? Not saved data will be lost" << endl << "Y - Yes, anything else - No" << endl;
            string ans = "";
            cin >> ans;
            if (ans != "Y") { option = 15; };
        }
        break;
        //1 - Добавить пустую трубу 
        case 1:
        {
            addPipes(pipes);
        }
        break;
        //2 - Добавить пустую КС
        case 2:
        {
            addKSs(KSs);
        }
        break;
        //3 - Добавить непустую трубу
        case 3:
        {
            addSpecialPipe(pipes);
        }
        break;
        //4 - Добавить непустую КС
        case 4:
        {
            addSpecialKS(KSs);
        }
        break;
        //3 - Вывести выделенные элементы
        case 5:
        {
            oAll(pipes, KSs, HLP, HLK);
        }
        break;
        //4 - Выделить нужные трубы
        case 6:
        {
            HLPipes(pipes, HLP);
        }
        break;
        //5 - Выделить нужные КС
        case 7:
        {
            HLKSs(KSs, HLK);
        }
        break;
        //6 - Редактировать выделенные трубы
        case 8:
        {
            rePipe(pipes, HLP);
            ;}
        break;
        //7 - Редактировать выделенные КС
        case 9:
        {
            reKS(KSs, HLK);
            ;}
        break;
        //8 - удалить выделенные трубы
        case 10:
        {
            delHLP(pipes, HLP);
        }
        break;
        //9 - удалить выделенные КС
        case 11:
        {
            delHLK(KSs, HLK);
        }
        break;
        //10 - сохранить всё
        case 12:
        {
            sAll(pipes, KSs);
        }
        break;
        //11 - загрузить всё
        case 13:
        {
            lAll(pipes, KSs);
        }
        break;

        case 14:
            createCons(connections, KSs);
        }
    }
}
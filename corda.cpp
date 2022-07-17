#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <string>

using namespace std;

char ch; //current pressed character
int i = 0; //global incrementor
INPUT ip; //text simulation handle.
string path; //path to %localappdata%
ifstream fin; //^^^^^^^^^^^^^^^^^^^^^
struct{
    char ch[40];
    char str[200];
}f[200];

//FUNCTION TO CHECK IF A KEY IS PRESSED
//1 - key is pressed
//0 - key is not pressed
int KeyPress(char ch){
    if(GetAsyncKeyState(ch) < 0) return 1;
    else return 0;
}

//wanted to make this a function, but that destroys the sync(whatever that means)
#define KeyToggle(x) GetKeyState(x)>0

//FINALLY MANAGED AT LEAST SOMETHING WITH CHORDS
//Visually unappeling, but gets the job done.
void Input(char ch[40], char str[200]){
    int keystate = 0;
    for(int i=1;KeyPress(ch[i-1]) && i<=strlen(ch);i++){
        if(i == strlen(ch)){
            ip.ki.wVk = VK_BACK;
            for(int j=0;j<strlen(ch);j++){
                SendInput(1, &ip, sizeof(INPUT));
                Sleep(50);
            }
            ip.ki.wVk = 0;
            for(int j=0;j<strlen(str);j++){
                ip.ki.wScan = str[j];
                SendInput(1, &ip, sizeof(INPUT));
            }
            ip.ki.wScan = ' ';
            SendInput(1, &ip, sizeof(INPUT));
            keystate = 1;
        }
    }
    while(keystate){
        for(int i=1;!KeyPress(ch[i-1]) && i<=strlen(ch);i++){
            if(i == strlen(ch)){
                keystate = 0;
            }
        }
    }
}

int main(int argc, char ** argv){
    ip.type = INPUT_KEYBOARD;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    if(argc > 1){
        cout << "The program has started.\n";
        cout << "Press INSERT to toggle on/off.\n";
        //messy std::string stuff to read from %localappdata%
        path = getenv("localappdata");
        path += "\\corda\\";
        path += argv[1];
        path += ".txt";
        fin.open(path.c_str(), ios::out | ios::app);

        for(/*Global Incrementor*/ i=0;i<10;i++){
            fin.get(f[i].ch, 40);
            fin.get();
            fin.get(f[i].str, 200);
            fin.get();
        }
        while(1){
            for(int j=0;j<i && KeyToggle(VK_INSERT);j++){
                // cout << f[j].ch << "\t" << f[j].str << "\n";
                // getch();
                Input(f[j].ch, f[j].str);
            }
        }
    }
    return 0;
}
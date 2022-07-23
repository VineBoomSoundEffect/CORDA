#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <string>

using namespace std;

char ch; //current pressed character
int i = 0; //global incrementor
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
//currently struggling with chords that have the same keys 
void Input(char ch[40], char str[200]){
    int keystate = 0;
    for(int i=1;KeyPress(ch[i-1]) && i<=strlen(ch);i++){
        if(i == strlen(ch) && KeyPress(VK_TAB)){
            INPUT ip[strlen(str)];
            for(int j=0;j<strlen(ch)+1;j++){
            	ip[j].type = INPUT_KEYBOARD;
            	ip[j].ki.dwFlags = KEYEVENTF_UNICODE;
            	ip[j].ki.wVk = VK_BACK;
            }
            SendInput(strlen(ch)+1, ip, sizeof(INPUT));
            for(int j=0;j<strlen(str);j++){
            	ip[j].type = INPUT_KEYBOARD;
            	ip[j].ki.dwFlags = KEYEVENTF_UNICODE;
            	ip[j].ki.wVk = 0;
                ip[j].ki.wScan = str[j];
            }
            SendInput(strlen(str), ip, sizeof(INPUT));
            ip[0].ki.wScan = ' ';
            SendInput(1, &ip[0], sizeof(INPUT));
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
            for(int j=0;j<i;j++){
                // cout << f[j].ch << "\t" << f[j].str << "\n";
                if(KeyPress(VK_TAB)) cout << "asdf\n";
                Input(f[j].ch, f[j].str);
            }
            Sleep(10); //fixes performance issues, deleting this results in 100% cpu usage.
			//i am aware that the more complex a txt file becomes, the less responsive the app will feel.
			//but i can't do anything about it.
        }
    }
    return 0;
}
//ISSUSE: same lettered chords dont work
//fixed 100% cpu usage when idle, although it will still go up if a chord is pressed

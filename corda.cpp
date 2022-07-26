//CORDA by Teodor Pomohaci, aka VineBoomSoundEffect on GitHub
//This software is distributed under the MIT licence. Basically:
// - you can do whatever you want with this
// - even use it commercially if you want
// - just don't say you own it
// - if you do use it, I'd appreciate if you gave me credit :)
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <string>
using namespace std;

ifstream fin;
string path; //path to localappdata
struct eg{
	char ch[40];
	char str[300];
}f[200]; //the chords and words will be stored here
int k = 0; //global incrementor, useful for knowing how many chord-output pairs are there

int main(int argc, char ** argv){
	cout << "The program has started.\n";
	if(argc >= 1){
		//messy read from localappdata/corda
		path = getenv("localappdata");
		path += "\\corda\\";
		path += argv[1];
		path += ".txt";
		fin.open(path.c_str(), ios::out | ios::app);
		//get the chords and respective outputs and store them
		for(k=0;fin.get(f[k].ch, 40);k++){
			fin.get();
			fin.get(f[k].str, 300);
			fin.get();
		}
		while(1){
			//loop through each chord-output pair
			for(int i=0;i<k && GetAsyncKeyState(VkKeyScan('`'));i++){
				int keystate = 0;
				for(int j=1;j<=strlen(f[i].ch) && GetAsyncKeyState(VkKeyScan(f[i].ch[j-1]));j++){
					if(j == strlen(f[i].ch)){
						INPUT ip[strlen(f[i].str)];
						//delete the characters from the chord
						for(int l=0;l<=strlen(f[i].ch);l++){
							ip[l].type = INPUT_KEYBOARD;
							ip[l].ki.dwFlags = KEYEVENTF_UNICODE;
							ip[l].ki.wVk = 0;
							ip[l].ki.wScan = 8;
						}
						//then, simulate the output
						SendInput(strlen(f[i].ch)+1, ip, sizeof(INPUT));
						for(int l=0;l<strlen(f[i].str);l++){
							ip[l].type = INPUT_KEYBOARD;
							ip[l].ki.dwFlags = KEYEVENTF_UNICODE;
							ip[l].ki.wVk = 0;
							ip[l].ki.wScan = f[i].str[l];
						}
						SendInput(strlen(f[i].str), ip, sizeof(INPUT));
						//then add a space 
						ip[0].ki.wScan = ' ';
						SendInput(1, &ip[0], sizeof(INPUT));
						keystate = 1;
					}
				}
				//wait until all keys have been unpressed
				while(keystate){
					for(int j=1;j<=strlen(f[i].ch) && !GetAsyncKeyState(VkKeyScan(f[i].ch[j-1]));j++){
						if(j == strlen(f[i].ch)) keystate = 0;
					}
				}
			}
			Sleep(10); //for better performance, otherwise the cpu is always at 100%
		}
	}
	return 0;
}
// Created by akkiisfrommars on 17/10/2023
// MacOS only!!!

#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

int main() {
    
    cout << "ISO Burner (Beta)" << endl;
    cout << "Created by akkiisfrommars" << endl;
    cout << "------------------------" << endl;
    cout << "Loading available volumes...";
    sleep(3);
    
    
    cout << endl << endl;
    string avlvol = "diskutil list";
    system(avlvol.c_str());
    
    string isofile, usbpath, choice;
    
    cout << endl << "USB Path: ";
    cin >> usbpath;
    
    cout << "ISO file Path: ";
    cin >> isofile;
    
    cout << "WARNING: ARE YOU SURE YOU WANT TO PROCEED? (y/N) ";
    cin >> choice;
    
    if(choice == "y") {
        cout << "Proceeding..." << endl;
        
        // unmounting the disk
        string umount = "sudo diskutil unmountDisk " + usbpath;
        int umountResult = system(umount.c_str());
        
        if (umountResult != 0) {
            cerr << "Error unmounting disk " << usbpath << endl;
            return 1;
        }
        
        // wait time to abort
        cout << "Waiting 5 Seconds before continuing" << endl;
        cout << "Press (ctrl + z) to abort" << endl;
        sleep(6);
        
        
        // dd command
        string ddCommand = "sudo dd if=" + isofile + " of=" + usbpath + " bs=4M status=progress";
        
        int result = system(ddCommand.c_str());
        
        if (result == 0) {
            cout << "ISO burned successfully to " << usbpath << endl;
        } else {
            cerr << "Error burning ISO to " << usbpath << endl;
        }
    }
}
   

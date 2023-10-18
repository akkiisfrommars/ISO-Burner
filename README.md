# ISO-Burner
ISO-Burner is a simple command-line applicaton to burn ISOs to a USB drive.
It is fast and efficient and works out of the box on macOS. 
Made in C++ by akkiisfrommars.


How to compile ISO-Burner yourself?

macOS:
1) Make sure clang or g++ is installed.
2) Download the .cpp file and save it in a directory (ex: Desktop)
3) open the terminal and go the the said direcotry 
          $ cd Desktop/
4) type the following command to compile the code and create the executable file.
          $ clang++ iso.cpp -o iso
                   or
          $ g++ -o iso iso.cpp
5) To run the executable, type the following command.
          $ ./iso



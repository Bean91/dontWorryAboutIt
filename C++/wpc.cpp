#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    char fullPath[MAX_PATH];
    GetFullPathName("agh.bmp", MAX_PATH, fullPath, NULL); // Convert relative path to absolute

    bool result = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)fullPath, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    if (result) {
        cout << "hope you like your new wallpaper bozo" << endl;
    } else {
        cout << "Failed to change wallpaper. Error code: " << GetLastError() << endl;
    }

    return 0;
}
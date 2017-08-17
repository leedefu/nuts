#include <stdio.h>
#include <stddef.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <wchar.h>
#include <errno.h>
#include <unistd.h>
#include <utime.h>
#include <sys/types.h>
#include <syscall.h>
#include <stdint.h>
#include <bits/wordsize.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

#define VERSION_HEADER  "Manifest-Version"
#define CREATOR_HEADER  "Created-By"
#define NAME_HEADER  "Name"
#define DIGEST_HEADER  "SHA1-Digest"
#define VERSION  "1.0"
#define CREATOR  "NGI-Platform"
#define MANIFEST_PATH_NAME  "MANIFEST"
#define MANIFEST_FILE_NAME  "MANIFEST.MF"
#define SIGNATURE_FILE_NAME  "MANIFEST.SF"
#define PUBKEY_FILE_NAME  "MANIFEST.RSA"


/*------------------------------------------*/
class a1
{
    // virtual void func();
};

class b1 : public virtual a1
{
    // virtual void func();
};
/*------------------------------------------*/

#define READ_FROM_FILE 0 

struct A {
    int a;
    int b;
};

int main(int argc, char* argv[])
{
    int c = 100;
    A * p = (A*)(((char*)&c) - offsetof(A, b));
    printf("p->b=[%d]\n", p->b);
    printf("&p->b=[%p]\n", &p->b);
    printf("&p->b=[0x%llx]\n", &p->b);

    // printf("((A*)0)->b =[%d]\n", ((A*)0)->b);
    printf("&(((A*)0)->b) =[%p]\n", &(((A*)0)->b));


return 0;

    char cc = 0xff;
    unsigned char ucc = (unsigned char)cc;
    int abc = (int)ucc;
    printf("abc=%d\n", abc);

    int iii = 0;
    memcpy(&iii, &cc, 1);

    int ii = static_cast<int>(cc);
    unsigned int uii = (unsigned int)cc;

    printf("cc=%d\n", cc);
    printf("ii=%d\n", ii);
    printf("uii=%d\n", uii);
    printf("iii=%d\n", iii);
    printf("0xff=%d\n", 0xff);

// Here return.......................................................
return 0;
    int len = strlen(argv[0]);
    printf("strlen(argv[0]):%d\n", strlen(argv[0]));
    memset(argv[0], 0, len);
    memcpy(argv[0], "abc", 3);
    sleep(3);
    printf("pid:%d\n", getpid());


// Here return.......................................................
return 0;

    char* array[] = {"213", "456", "789"};
    int size = sizeof(array);

    printf("array size=%d\n", size);
    printf("sizeof char*=%d\n", sizeof(char*));


#if READ_FROM_FILE
    ifstream fin("MANIFEST.MF");
    if (!fin) {
        printf("error open file\n");
        return 1;
    }
#else

    FILE* fp = fopen("MANIFEST.MF", "rb");
    fseek(fp, 0, SEEK_END);
    int iContentSize = ftell(fp);
    printf("MANIFES.MF size=%d\n", iContentSize);

    rewind(fp);
    char* pContent = new char[iContentSize];
    fread(pContent, iContentSize, 1, fp);

    std::istringstream fin;
    fin.rdbuf()->pubsetbuf(pContent, iContentSize);

#endif

    std::map<std::string, std::string> m_digestMap;

    string buffer;
    string header;
    string content;
    string dHeader;
    string dContent;

    while (getline(fin, buffer)) {
        if (buffer == "" || buffer == "\r") {
            continue;
        }
        if (std::string::npos == buffer.find(':')) {
            cout << "manifest syntax error 1" << endl;
            return 1;
        }
        if (buffer.find(':') != buffer.rfind(':')) {
            cout << "manifest syntax error 2" << endl;
            return 1;
        }
        if (buffer[buffer.length() - 1] == '\r') {
            buffer = buffer.substr(0, buffer.length() - 1);
        }
        header = buffer.substr(0, buffer.find(':'));
        content = buffer.substr(buffer.find(':') + 2);
        if ((header.length() == 0) || content.length() == 0) {
            cout << "manifest syntax error 3" << endl;
            return 1;
        }
        //cout << header << "\t" << content << endl;
        if (header == VERSION_HEADER) {
            continue;
        }
        else if (header == CREATOR_HEADER) {
            continue;
        }
        else if (header == NAME_HEADER) {
            //NCLOGD("[Digest Scan] : %s\n", content.c_str());
            if (!getline(fin, buffer)) {
                cout << "manifest syntax error 2" << endl;
                return 1;
            }
            if (buffer == "" || buffer == "\r") {
                continue;
            }
            if (std::string::npos == buffer.find(':')) {
                cout << "manifest syntax error 1" << endl;
                return 1;
            }
            if (buffer.find(':') != buffer.rfind(':')) {
                cout << "manifest syntax error 2" << endl;
                return 1;
            }
            if (buffer[buffer.length() - 1] == '\r') {
                buffer = buffer.substr(0, buffer.length() - 1);
            }
            dHeader = buffer.substr(0, buffer.find(':'));
            dContent = buffer.substr(buffer.find(':') + 2);
            if ((header.length() == 0) || content.length() == 0) {
                cout << "manifest syntax error 3" << endl;
                return 1;
            }
            //cout << "\t" << dHeader << "\t" << dContent << endl;
            if (dHeader == DIGEST_HEADER) {
                m_digestMap.insert(
                        map<string, string>::value_type(content, dContent));
            }
            else {
                cout << "manifest syntax error 3" << endl;
                return 1;
            }
        }
        else {
            cout << "manifest syntax error 4" << endl;
            return 1;
        }
    }

#if READ_FROM_FILE
    fin.close();
#endif

    cout <<"DigestMap size: "<< m_digestMap.size()<<endl;
    m_digestMap.size();

    if (m_digestMap.size() != 0) {
        for (map<string, string>::iterator mit = m_digestMap.begin(); mit != m_digestMap.end(); ++mit) {
            cout<<"[key  ] : "<< mit->first <<endl;
            cout<<"[value] : "<< mit->second<<endl<<endl;
        }
    }

    return 0;

#if 0
    /*Test for std::string substr*/
    std::string strHardkey("nutshell.hardkey_back");
    //strHardkey = strHardkey.substr(0, 20);
    //printf("strHardkey.substr(0,20) = (%s) \n", strHardkey.c_str());

    std::string hardkey_str = strHardkey;
    std::transform(hardkey_str.begin(), hardkey_str.end(),
            hardkey_str.begin(), ::tolower);

    printf("tolower hardkey_str = (%s) \n", hardkey_str.c_str());

    //const std::string::value_type trim_chars[] = { ' ' }; // wrong
    const std::string::value_type trim_chars[] = " ";  // right
    const std::string::size_type first_good_char = hardkey_str.find_first_not_of(trim_chars);
    printf("trim_chars = [%c]\n", trim_chars[0]);
    printf("first_good_char = %lu\n", first_good_char);
    const std::string::size_type last_good_char = hardkey_str.find_last_not_of(trim_chars);
    printf("last_good_char = %lu\n", last_good_char);
    printf("last_good_char  - first_good_char + 1 = %lu\n", last_good_char - first_good_char + 1);
    hardkey_str = hardkey_str.substr(first_good_char, last_good_char - first_good_char + 1);
    //std::string temphardkey_str = hardkey_str.substr(first_good_char, last_good_char - first_good_char + 1);
    // printf("temphardkey_str = (%s) \n", temphardkey_str.c_str());
    //hardkey_str = temphardkey_str;
    printf("hardkey_str = (%s) \n", hardkey_str.c_str());
    if (hardkey_str == "nutshell.hardkey_back") {
        printf("same....\n");
    }
    else {
        printf("Different!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!\n");
    }

    return 0;
#endif


    std::string str1 = "2015-09-25-11-59-02";
    std::string str2 = "2015-08-25-12-59-02";
    if (str1.compare(str2) < 0) {
        printf("%s.compare(%s) < 0\n", str1.c_str(), str2.c_str());
    }
    else if (str1.compare(str2) > 0) {
        printf("%s.compare(%s) > 0\n", str1.c_str(), str2.c_str());
    }
    else {
        printf("%s.compare(%s) = 0\n", str1.c_str(), str2.c_str());
    }

    if (str1 < str2) {
        printf("%s < %s \n", str1.c_str(), str2.c_str());
    }
    else if (str1 > str2) {
        printf("%s > %s \n", str1.c_str(), str2.c_str());
    }
    else {
        printf("%s = %s \n", str1.c_str(), str2.c_str());
    }
#if 0
    float ff = 1.0;
    printf("ff=%f.\n", ff);
#endif

#if 0
    printf("sizeof(a1) = %d \n", sizeof(a1));
    // result 1


    printf("sizeof(b1) = %d \n", sizeof(b1));
    // result 8
#endif
    
    // buffer
    unsigned char data[12] = { 0 };

    {
        // write 
        std::string strDir("0f03ed");

        int32_t id = 10;
        int32_t flag = 1;
        int32_t dir = std::stoi(strDir, 0, 16);
        // int32_t dir = ::atoi(strDir.c_str());
        printf("\n------write--------------------\n");
        printf("id=%d, flag=%d, dir=%06x, strDir=%s\n", id, flag, dir, strDir.c_str());
        printf("------write--------------------\n\n");
        
        memcpy(data, &id, sizeof(id));
        memcpy(data + sizeof(id), &flag, sizeof(flag));
        memcpy(data + sizeof(id) + sizeof(flag), &dir, sizeof(dir));
    }

    {
        // read 

        int32_t id = 0;
        int32_t flag = 0;
        int32_t dir = 0;
        
        memcpy(&id, data, sizeof(id));
        memcpy(&flag, data + sizeof(id), sizeof(flag));
        memcpy(&dir, data + sizeof(id) + sizeof(flag), sizeof(dir));

        char strDir[8] = {0};
        snprintf(strDir, 8, "%06x", dir);
        // std::string strDir = std::to_string(dir);

        printf("\n------read--------------------\n");
        printf("id=%d, flag=%d, dir=%06x, strDir=%s\n", id, flag, dir, strDir);
        printf("------read--------------------\n\n");
    }



    return 0;
}

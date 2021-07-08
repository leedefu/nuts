#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/sha.h> // sha1
#include <openssl/evp.h> // base64
#include "sc_sha1.h"

bool isfile(const char* filepath)
{
    struct stat st;
    if (0 == stat(filepath, &st)) {
        if (S_ISREG(st.st_mode)) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("+++++++++++++++++++++++++\n");
        printf("usage: \n ./sha1_tool inputfile outputfile\n");
        printf("+++++++++++++++++++++++++\n");
        return -1;
    }

    if (!isfile(argv[1])) {
        printf("%s dose not exist or is not a regular file.\n", argv[1]);
        return -2;
    }

    FILE* pFile = fopen(argv[1], "rb");
    if (NULL == pFile) {
        printf("%s open failed.\n", argv[1]);
        return -3;
    }
    fseek(pFile, 0, SEEK_END);
    long len = ftell(pFile);
    rewind(pFile);
    char* content = new char[len];
    if (NULL == content) {
        fclose(pFile);
        pFile = NULL;
        return -4;
    }
    fread((void*)content, (size_t)(sizeof(char)), len, pFile);

    fclose(pFile);
    pFile = NULL;

    unsigned char* out = NULL;
    unsigned int out_size = 0;

    security::sc_sha1 cSha;
    bool ret = cSha.do_sha1(content, len, &out, out_size);
    if (!ret) {
        printf("sha1 failed.\n");
        return -5;
    }

    FILE* pOutFile = fopen(argv[2], "wb");
    if (NULL == pOutFile) {
        delete[] out;
        out = NULL;
        printf("create file %s failed.\n", argv[2]);
        return -6;
    }
    fwrite((void*)out, (size_t)(sizeof(char)), out_size, pOutFile);
    fclose(pOutFile);

    delete[] out;
    out = NULL;
    return 0;

#if 0
    if (argc != 2 || strlen(argv[1]) == 0) {
        printf("-----------------------------\n");
        printf("usage: \n        ./MD5_tool filepath\n");
        printf("-----------------------------\n");
        return 0;
    }

    unsigned char digest[MD5_DIGEST_LENGTH] = { 0 };        
    MD5_CTX context;             
    MD5_Init(&context);

    if (isfile(argv[1])) {
        int bytes = 0;
        unsigned char data[DATA_TRUNK_SIZE] = { 0 };
        FILE* pFile = fopen(argv[1], "rb");
        if (NULL != pFile) {
            while ((bytes = fread(data, 1, DATA_TRUNK_SIZE, pFile)) != 0) {
                MD5_Update(&context, data, bytes); 
            }
            fclose(pFile);
        }
        else {
            printf("open %s fail.\n", argv[1]);
            return 0;
        }
    }
    else {
        printf("%s is not a regular file.\n", argv[1]);
        return 0;
    }

    MD5_Final(digest, &context);

    char out[MD5_STRING_LENGTH + 1] = { 0 };  
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {          
        snprintf(&(out[i * 2]), 3, "%02x", (unsigned int) digest[i]);                                                         
    }

    printf("%s\n", out);

#endif
}

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/md5.h>

#define DATA_TRUNK_SIZE 1024 
#define MD5_STRING_LENGTH 32 

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
    return 0;
}

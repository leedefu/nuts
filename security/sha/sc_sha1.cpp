#include "sc_sha1.h"
#include<openssl/sha.h>

namespace security
{

sc_sha1::sc_sha1()
{
}

sc_sha1::~sc_sha1()
{
}

bool sc_sha1::do_sha1(const char* input, unsigned int input_size, unsigned char** output, unsigned int& output_size)
{
    if (NULL == input) {
        return false;
    }
    if (0 == input_size) {
        return false;
    }
    if (NULL == output) {
        return false;
    }

    // sha
    SHA_CTX ctx;
    int ret = SHA1_Init(&ctx);
    if (0 == ret) {
        return false;
    }

    ret = SHA1_Update(&ctx, input, input_size);
    if (0 == ret) {
        return false;
    }

    *output = new unsigned char[SHA_DIGEST_LENGTH];
    ret = SHA1_Final((*output), &ctx);
    if (0 == ret) {
        delete[] *output;
        *output = NULL;
        return false;
    }
    output_size = SHA_DIGEST_LENGTH;

    return true;
}

}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>
#include <curl/easy.h>

// desc: download webpage and save webpath to local file

FILE* fp = NULL;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)  
{
    int written = fwrite(ptr, size, nmemb, (FILE *)fp);
    return written;
}
         

int main(int argc, char* argv[])
{
    printf("catch_webpage\n");

    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);  
    curl=curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);  

    fp = fopen(argv[2],"w");
    if(NULL == fp) {
        curl_easy_cleanup(curl);
        exit(1);
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);  
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    sync();
    exit(0);
    return 0;
}

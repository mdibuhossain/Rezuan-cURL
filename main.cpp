#include <iostream>
#include <curl/curl.h>
using namespace std;

int main()
{
    string biin, url = "https://lookup.binlist.net/";
    cout << "BIIN: ";
    cin >> biin;
    url += biin;
    cout << endl;

    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
/*
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "X-RapidAPI-Host: binlist.p.rapidapi.com");
    headers = curl_slist_append(headers, "X-RapidAPI-Key: a0fe9d8a77msh60f6bede699b2fcp10000ajsneb844a28b51c");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    */
    curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 0L);

    CURLcode ret = curl_easy_perform(hnd);
    if(ret!=CURLE_OK)
    {
        fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(ret));
    }
    else
    {
        cout  << ret;
    }
    return 0;
}

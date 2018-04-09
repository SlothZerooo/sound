#include "comm.h"
#include<stdio.h>
#include <curl/curl.h>
#include <math.h>

//function definition, this function takes in 80-pieces of rms value, each
//is calculated by 200 samples.
void sendToServer(double rms[]){
	double fast[8], sum;
	int i, j;  //loop counters
	CURL *curl;
	CURLcode res;
	char post[1000];
	
	for(i=0; i<8; i++){     //8times
		for(j=0, sum=0; j<10; j++){    //10times
			sum +=  (rms[j+i*10]*rms[j+i*10])*200;
		}
		fast[i] = sqrt(sum/2000);
	}
	sprintf(post, "data=%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f",
		fast[0], fast[1], fast[2], fast[3], fast[4], fast[5], fast[6], fast[7]);
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl){
		curl_easy_setopt(curl, CURLOPT_URL, URL);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
		  curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
} 

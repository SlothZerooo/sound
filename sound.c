#include "comm.h"
#include "sound.h"
#include "screen.h"
#include <stdio.h>
#include <math.h>
// function definition of printfID
void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
	printf("%c", id[i]);

	printf("\n");
}

// function definition of dispWAVData()
void dispWAVData(char filename[]){
 	int i,j;    //loop counters
	FILE *fp;    // file header to open file test.wav
	double rms[80], sum;   //80 pieces of RMS value
	short samples[SAMPLERATE];   //totally 16000 samples in 1 sec
	WAVHeader mh;      //just use to skip over the header of wav file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error when open the file!\n");
		return;
	}
	fread(&mh, sizeof(mh), 1, fp);
	fread(samples, sizeof(short), SAMPLERATE,fp);
	fclose(fp);
	clearScreen();
	for(i=0; i<80; i++){
		for(j=0, sum=0.0; j<SAMPLERATE/80; ++j){
			sum += samples[j+i*200] * samples[j+i*200];
		}
		rms[i] = sqrt(sum/200);
#ifdef DEBUG
		printf("rms[%d]: %10.4f, dB = %10.4f\n", i, rms[i], 20*log10(rms[i]));
#else
		dispBar(i, 20*log10(rms[i]));     //display dB value a bar
#endif
	}
#ifdef COMM
	sendToServer(rms);
#endif
}
// function definition of dispWAVHeader()
void dispWAVHeader(char filename[]){
	FILE *fp;
	WAVHeader mh; // an instance of WAVEHeader struct

	//open the test.wav file for reading
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error when open the file!\n");
		return;
	}
	fread(&mh, sizeof(mh), 1, fp);
	fclose(fp);
	printf("Chunk ID: ");
	printID(mh.chunkID);
	printf("Chunk size: %d\n", mh.chunkSize);
	printf("Format: ");
	printID(mh.format);
	printf("  subchunk 1 ID: ");
	printID(mh.subchunk1ID);
	printf("  subchunk 1 size: %d\n", mh.subchunk1Size);
	printf("Audio format: %d\n", mh.audioFormat);
	printf("Num channels: %d\n", mh.numChannels);
	printf("  sample rate: %d\n", mh.sampleRate);
	printf("  byte rate: %d\n", mh.byteRate);
	printf("Block align: %d\n", mh.blockAlign);
	printf("Bits persample: %d\n", mh.bitsPerSample);
	printf("  subchunk 2 ID: ");
	printID(mh.subchunk2ID);
	printf("  subchunk 2 size: %d\n", mh.subchunk2Size);
}

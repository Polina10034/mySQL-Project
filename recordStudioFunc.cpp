#pragma once
#include "recordStudioFunc.h"

#include"structur.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

#include "connection.cpp"

/*#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/tokenizer.hpp>
#include <string>*/

using namespace std;

int getMusicianId(char *argv[]);
int getMusicianName(char *argv[]);


void showAllMusiciansOverTheYears(char *argv[]);//8

void showAlbumsRecordedBetweenDates(char *argv[]);//1

void showMusicianSongsBetweenDates(char *argv[], char musicianName);//2

void showDiffrentAlbumsBetweenDatesForMusician(char *argv[], char musicianName);//3

void showMostPopularInstrument(char *argv[]);//4

void showInstrumentsInAlbum(char *argv[], char albumName);//5

void mostProductiveProducer(char *argv[], char producerName);//6

void popularManufacturer(char *argv[]);//7

void totalMusicians(char *argv[]);//8
void showCollaborativeMusician(char *argv[]);//9

void showPopularJenre(char *argv[]);//10

void showProductiveThechBetweenDates(char *argv[]);//11

void firstAlbum(char *argv[]);//12

void showAllSongsIncludedIn2Albums(char *argv[]);//13

void allTechPersonInAllbum(char *argv[]);//14

void showMultiJenreMusician(char *argv[]);//15








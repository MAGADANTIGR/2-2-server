#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <locale.h>
#include <string.h>
#include <fstream> // работа с файлами
#include <iomanip> // манипуляторы ввода/вывода
#include <time.h>
#include "locale.h"
#include "stdlib.h"
#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include<ctime>

#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SEQURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

template < typename T>
void outfile(vector<T>& vector, char* fileName);
template < typename T>
void file(vector<T>& vector, char* fileName);
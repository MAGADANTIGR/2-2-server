#include "Header.h"
#include "Product.h"
#include "Abonement.h"
#include "Order.h"
#include"Trainer.h"

int numcl = 0;
int flag = 0;
int poisk = 0;

template < typename T>
void outfile(vector<T>& vector, char* fileName) {
	ifstream in(fileName);
	T obj;
	if (vector.size() > 0) { vector.clear(); }

	if (in.is_open())
	{
		while (!in.eof()) {
			in >> obj;
			vector.push_back(obj);
		}
		in.close();
	}
	else cout << "non" << endl;
	
};
template < typename T>
void file(vector<T>& vector, char* fileName)
{
	ofstream fin(fileName, ios_base::out);

	for (int i = 0; i < vector.size() - 1; i++) {
		if (i != 0) { 
			fin << "\n"; }
		fin << vector[i];
	}
	fin.close();
};
template < typename T>
void fileO(vector<T>& vector, char* fileName)
{
	ofstream fin(fileName, ios_base::out);

	for (int i = 0; i < vector.size(); i++) {
		if (i != 0) {
			fin << "\n";
		}
		fin << vector[i];
	}
	fin.close();
};


DWORD WINAPI ThreadFunc(LPVOID client_socket)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SOCKET newCon = ((SOCKET*)client_socket)[0];
	char b1[16384], b2[256], buf[256], logU[256], m[256], m1[256], m2[256], pr[16384], mm[256];
	string sBuf, bufe, buff;
	int i = 0, c = 0;
	int counter = 3;
	time_t now = time(0);

	vector<Product> prod;
	vector<Order>ord;
	vector<Abonement>ab;
	vector<Trainer>trn;
	Order o;

	while (recv(newCon, m1, sizeof(m1), NULL) != 0)//Стартовое меню
	{
		cout << "Главное меню" << endl;
		if (atoi(m1) == 1) {
			cout << "Вход в админа" << endl;
			ifstream adm("admin.txt");
			recv(newCon, b2, sizeof(b2), NULL);
			cout << b2 << endl;
			while (adm.getline(buf, sizeof(buf)))
			{
				sBuf = string(buf);
				if (sBuf == string(b2)) {
					flag = 1;
					strcpy(b1, "1");
					send(newCon, b1, sizeof(b1), NULL);
				}
				else {
					flag = 0;
					strcpy(b1, "0");
					send(newCon, b1, sizeof(b1), NULL);
				}
			}
			if (flag == 1)
				while (recv(newCon, mm, sizeof(mm), NULL) != 0)
				{
					if (atoi(mm) == 1) {
						cout << "1_1" << endl;
						
								recv(newCon, pr, sizeof(pr), NULL);
								ofstream ban("Product.txt", ios::app);
								ban << pr;
								ban.close();
						
					}
					if (atoi(mm) == 2)
					{
						cout << "1_2" << endl;
						int asd;
						char tx[5];
						outfile(prod, (char*)"Product.txt");
						asd = prod.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						if ((asd - 1) != 0) {
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = prod[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getprice();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getgrams();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getkkal();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getnum();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
						}
						
					}
					if (atoi(mm) == 3)
					{
						cout << "1_3" << endl;
						int asd;
						char tx[5];
						outfile(ord, (char*)"Orders.txt");
						asd = ord.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						for (int i = 0; i < asd - 1; i++)
						{
							sBuf = ord[i].getLog();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = ord[i].getNameP();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = ord[i].getprice();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
						}
						recv(newCon, b1, sizeof(b1), NULL);
						if (atoi(b1) == 1) {
							ofstream op("Отчет(покупки).txt");
							char* dat = ctime(&now);
							op << "     Отчет о покупках товаров     \n\n";
							for (int i = 0; i < asd - 1; i++) {
								op << "Название товара: " << ord[i].getNameP() << "\n";
								op << "Цена товара: " << ord[i].getprice() << "BYN\n";
								op << "Покупатель(пользователь): " << ord[i].getLog() << "\n\n";
							}
							op << "\nДата формирования отчета: " << dat;
							op.close();
						}
					}
					if (atoi(mm) == 4) {
						cout << "1_4" << endl;
						int asd;
						char tx[5];
						outfile(prod, (char*)"Product.txt");
						asd = prod.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						if ((asd - 1) != 0) {
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = prod[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getprice();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getgrams();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getkkal();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getnum();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);

							}
							recv(newCon, b1, sizeof(b1), NULL);
							char fl[256] = "1";
							int fla = 0;
							for (int i = 0; i < prod.size() - 1; i++) {
								if (prod[i].getnum() == (string)b1) {
									prod.erase(prod.begin() + (i));
									file(prod, (char*)"Product.txt");
									send(newCon, fl, sizeof(fl), NULL);
									fla = 1;
									break;
								}
							}
							if (fla != 1) {
								strcpy(fl, "0");
								send(newCon, fl, sizeof(fl), NULL);
							}
						}
					}
					if (atoi(mm) == 5) {
						cout << "1_5" << endl;
						recv(newCon, b1, sizeof(b1), NULL);
						outfile(prod, (char*)"Product.txt");
						char fl[256] = "1";
						int fla = 0;
						for (int i = 0; i < prod.size() - 1; i++) {
							if (prod[i].getnum() == (string)b1 || prod[i].getName() == (string)b1) {
								send(newCon, fl, sizeof(fl), NULL);
								fla = 1;
								sBuf = prod[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getprice();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getgrams();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getkkal();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getnum();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
						}
						if (fla != 1) {
							strcpy(fl, "0");
							send(newCon, fl, sizeof(fl), NULL);
						}
					}
					if (atoi(mm) == 6) {
						cout << "1_6" << endl;
						Product b;
						outfile(prod, (char*)"Product.txt");
						for (i = 0; i < prod.size() - 1; i++) {
							for (int j = 0; j < prod.size() - 2; j++) {
								if (prod[j].getName() > prod[j + 1].getName()) {
									b = prod[j];
									prod[j] = prod[j + 1];
									prod[j + 1] = b;
								}
							}
						}
						ofstream ban("Product.txt");
						for (int i = 0; i < prod.size() - 1; i++) {
							sBuf = prod[i].getName() + " " + prod[i].getprice() + " " + prod[i].getgrams() + " " + prod[i].getkkal() + " " + prod[i].getnum() + " ";
							if (i != prod.size() - 2) {
								sBuf = sBuf + "\n";
							}
							ban << sBuf;
						}
						ban.close();
					}
					if (atoi(mm) == 7) {
						cout << "1_7" << endl;
						int asd;
						char tx[5];
						outfile(ab, (char*)"Abonement.txt");
						asd = ab.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						if ((asd - 1) != 0) {
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = ab[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = ab[i].getDay();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = ab[i].getMon();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = ab[i].getDate();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = ab[i].getTime();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = ab[i].getYear();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
						}
						recv(newCon, b1, sizeof(b1), NULL);
						if (atoi(b1) == 1) {
							ofstream oa("Отчет(абонементы).txt");
							char* dat = ctime(&now);
							oa << "     Отчет о покупках абонементов     \n\n";
							for (int i = 0; i < asd - 1; i++) {
								oa << "Дата покупки абонемента: " << ab[i].getDay() << " " << ab[i].getMon() << " " << ab[i].getDate() << " " << ab[i].getTime() << " " << ab[i].getYear() << "\n";
								oa << "Стоимость абонемента: 230 BYN" << "\n";
								oa << "Покупатель(пользователь): " << ab[i].getName() << "\n\n";
							}
							oa << "\nДата формирования отчета: " << dat;
							oa.close();
						}
					}
					if (atoi(mm) == 8) {
						cout << "1_8" << endl;
						int asd;
						char tx[5];
						outfile(prod, (char*)"Product.txt");
						asd = prod.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						if ((asd - 1) != 0) {
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = prod[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getprice();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getgrams();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getkkal();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getnum();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
							recv(newCon, b1, sizeof(b1), NULL);
							asd = atoi(b1);
							sBuf = prod[asd - 1].getName();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getprice();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getgrams();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getkkal();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getnum();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							recv(newCon, b2, sizeof(b2), NULL);
							if (atoi(b2) == 1) {
								cout << "1_8_1" << endl;
								recv(newCon, b2, sizeof(b2), NULL);
								for (int i = 0; i < prod.size() - 1; i++) {
									if (i == asd - 1) {
										prod[i].setName((string)b2);
									}
								}
							}
							if (atoi(b2) == 2) {
								cout << "1_8_2" << endl;
								recv(newCon, b2, sizeof(b2), NULL);
								for (int i = 0; i < prod.size() - 1; i++) {
									if (i == asd - 1) {
										prod[i].setprice((string)b2);
									}
								}
							}
							if (atoi(b2) == 3) {
								cout << "1_8_3" << endl;
								recv(newCon, b2, sizeof(b2), NULL);
								for (int i = 0; i < prod.size() - 1; i++) {
									if (i == asd - 1) {
										prod[i].setgrams((string)b2);
									}
								}
							}
							if (atoi(b2) == 4) {
								cout << "1_8_4" << endl;
								recv(newCon, b2, sizeof(b2), NULL);
								for (int i = 0; i < prod.size() - 1; i++) {
									if (i == asd - 1) {
										prod[i].setkkal((string)b2);
									}
								}
							}
							if (atoi(b2) == 5) {
								cout << "1_8_5" << endl;
								recv(newCon, b2, sizeof(b2), NULL);
								for (int i = 0; i < prod.size() - 1; i++) {
									if (i == asd - 1) {
										prod[i].setnum((string)b2);
									}
								}
							}
							file(prod, (char*)"Product.txt");
						}
					}
					if (atoi(mm) == 9) {
						cout << "1_9" << endl;
						recv(newCon, m, sizeof(m), NULL);
						if (atoi(m) == 1) {
							cout << "1_9_1" << endl;
							recv(newCon, b1, sizeof(b1), NULL);
							ofstream tr("Trainers.txt", ios::app);
							tr << b1;
							tr.close();
						}
						if (atoi(m) == 2)
						{
							cout << "1_9_2" << endl;
							int asd;
							char tx[5];
							outfile(trn, (char*)"Trainers.txt");
							asd = trn.size();
							itoa(asd, tx, 10);
							send(newCon, tx, sizeof(tx), NULL);
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = trn[i].getSur();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = trn[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = trn[i].getAge();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
						}
						if (atoi(m) == 3) {
							cout << "1_9_3" << endl;
							int asd;
							char tx[5];
							outfile(trn, (char*)"Trainers.txt");
							asd = trn.size();
							itoa(asd, tx, 10);
							send(newCon, tx, sizeof(tx), NULL);
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = trn[i].getSur();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = trn[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = trn[i].getAge();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
							recv(newCon, b1, sizeof(b1), NULL);
							char fl[256] = "1";
							int fla = 0;
							for (int i = 0; i < trn.size() - 1; i++) {
								if (trn[i].getSur() == (string)b1) {
									trn.erase(trn.begin() + (i));
									file(trn, (char*)"Trainers.txt");
									send(newCon, fl, sizeof(fl), NULL);
									fla = 1;
									break;
								}
							}
							if (fla != 1) {
								strcpy(fl, "0");
								send(newCon, fl, sizeof(fl), NULL);
							}
						}
					}
					if (atoi(mm) == 11) {
						char* dat = ctime(&now);
						int asd;
						char tx[5];
						outfile(prod, (char*)"Lessons.txt");
						asd = prod.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						if((asd)!=0){
							ofstream oi("Отчет(инд. занятия).txt");
						oi << "     Отчет об оплатах индивидуальных занятий     \n\n";
							for (int i = 0; i < asd; i++)
							{
								oi << "Покупатель(пользователь): " << prod[i].getName() << "\n";
								oi << "Кол-во занятий: " << prod[i].getprice() << "\n";
								oi << "Тренер: " << prod[i].getgrams() << " " << prod[i].getkkal() << "\n";
								oi << "Стоимоть всех занятий: " << prod[i].getnum() << " BYN" << "\n\n";
							}
							oi << "\nДата формирования отчета: " << dat;
							oi.close();
						}
					}
					if (atoi(mm) == 12)break;
				}
		}

		if (atoi(m1) == 2)
		{
			cout << "Вход в пользователя" << endl;
			flag = 0;
			ifstream adm("user.txt");
			recv(newCon, b2, sizeof(b2), NULL);
			recv(newCon, logU, sizeof(logU), NULL);
			cout << b2 << endl;
			while (adm.getline(buf, sizeof(buf)))
			{
				sBuf = string(buf);
				if (sBuf == string(b2)) {
					flag = 1;
					strcpy(b1, "1");
					send(newCon, b1, sizeof(b1), NULL);
				}
			}
			if (flag == 0) {
				strcpy(b1, "0");
				send(newCon, b1, sizeof(b1), NULL);
			}

			if (flag == 1)
			{
			
				while (recv(newCon, m2, sizeof(m2), NULL) != 0)
				{
					if (atoi(m2) == 1) {
						cout << "2_1" << endl;
						int asd;
						char tx[5];
						outfile(prod, (char*)"Product.txt");
						asd = prod.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);

						for (int i = 0; i < asd - 1; i++)
						{
							sBuf = prod[i].getName();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[i].getprice();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[i].getgrams();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[i].getkkal();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[i].getnum();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
						}
					}
					if (atoi(m2) == 2) {
						cout << "2_2" << endl;
						int asd;
						char tx[5];
						outfile(prod, (char*)"Product.txt");
						asd = prod.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						if ((asd - 1) != 0) {
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = prod[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getprice();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getgrams();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getkkal();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getnum();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
							recv(newCon, b1, sizeof(b1), NULL);
							asd = atoi(b1);
							sBuf = prod[asd - 1].getName();
							o.setNameP(sBuf);
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getprice();
							o.setprice(sBuf);
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getgrams();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getkkal();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = prod[asd - 1].getnum();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = (string)logU;
							o.setLog(sBuf);
							ord.push_back(o);
							fileO(ord, (char*)"Orders.txt");
						}
					}
					if (atoi(m2) == 3) {
						cout << "2_3" << endl;
						if (recv(newCon, b1, sizeof(b1), NULL)) {
							ofstream ab("Abonement.txt", ios::app);
							ab << logU << " ";
							char* dt = ctime(&now);
							ab << dt;
							ab.close();
						}
					}
					if (atoi(m2) == 4) {
						cout << "2_4" << endl;
						Product b;
						outfile(prod, (char*)"Product.txt");
						for (i = 0; i < prod.size() - 1; i++){
							for (int j = 0; j < prod.size() - 2; j++){
								if (prod[j].getName() > prod[j + 1].getName()){
									b = prod[j];
									prod[j] = prod[j + 1];
									prod[j + 1] = b;
								}
							}
						}
						ofstream ban("Product.txt");
						for (int i = 0; i < prod.size() - 1; i++){
							sBuf = prod[i].getName() + " " + prod[i].getprice() + " " + prod[i].getgrams() + " " + prod[i].getkkal() + " " + prod[i].getnum() + " ";
							if (i != prod.size() - 2) {
								sBuf = sBuf + "\n";
							}
							ban << sBuf;
						}
						ban.close();
					}
					if (atoi(m2) == 5) {
						cout << "2_5" << endl;
						recv(newCon, b1, sizeof(b1), NULL);
						outfile(prod, (char*)"Product.txt");
						char fl[256] = "1";
						int fla = 0;
						for (int i = 0; i < prod.size() - 1; i++) {
							if (prod[i].getnum() == (string)b1 || prod[i].getName() == (string)b1) {
								send(newCon, fl, sizeof(fl), NULL);
								fla = 1;
								sBuf = prod[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getprice();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getgrams();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getkkal();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = prod[i].getnum();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
						}
						if (fla != 1) {
							strcpy(fl, "0");
							send(newCon, fl, sizeof(fl), NULL);
						}
					}
					if (atoi(m2) == 6) {
						cout << "2_6" << endl;
						int asd;
						char tx[5];
						outfile(trn, (char*)"Trainers.txt");
						asd = trn.size();
						itoa(asd, tx, 10);
						send(newCon, tx, sizeof(tx), NULL);
						recv(newCon, b1, sizeof(b1), NULL);
						if (atoi(b1) == 1) {
							for (int i = 0; i < asd - 1; i++)
							{
								sBuf = trn[i].getSur();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = trn[i].getName();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
								sBuf = trn[i].getAge();
								strcpy(b1, sBuf.c_str());
								send(newCon, b1, sizeof(b1), NULL);
							}
							recv(newCon, b1, sizeof(b1), NULL);
							asd = atoi(b1);
							sBuf = trn[asd - 1].getSur();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							sBuf = trn[asd - 1].getName();
							strcpy(b1, sBuf.c_str());
							send(newCon, b1, sizeof(b1), NULL);
							ofstream iz("Lessons.txt", ios::app);
							iz << logU << " ";
							recv(newCon, b1, sizeof(b1), NULL);
							iz << b1 << " ";
							iz << trn[asd - 1].getSur() << " ";
							iz << trn[asd - 1].getName() << " ";
							recv(newCon, b1, sizeof(b1), NULL);
							iz << b1 << " ";
							iz.close();
						}
					}
					if (atoi(m2) == 7) {
						break;
					}
				}
			}
		}

		if (atoi(m1) == 3) {
			cout << "   Регистрация   " << endl;
			ifstream use("user.txt");

			recv(newCon, b2, sizeof(b2), NULL);
			cout << b2 << endl;
			flag = 1;
			while (use.getline(buf, sizeof(buf)))
			{
				sBuf = string(buf);
				if (sBuf == string(b2)) {
					flag = 0;
					strcpy(b1, "0");
					send(newCon, b1, sizeof(b1), NULL);

					break;
				}

			}if (flag == 1) {
				strcpy(b1, "1");
				send(newCon, b1, sizeof(b1), NULL);
				ofstream use("user.txt", ios::app);
				use << b2;
				use << "\n";

			}
			use.close();
		}

		if (atoi(m1) == 4) {
			time_t rawtime;
			struct tm* timeinfo;
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			printf("Время и дата отключения: %s ", asctime(timeinfo));
			cout << "END OF WORK" << endl;
			break;
		}
	}

	closesocket(newCon);
	numcl--;
	return 0;
}

void print()
{
	if (numcl) printf("%d подключенный(ых) клиент(ов)\n", numcl);
	else printf("Нет подключенных клиентов\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData) != 0) {
		std::cout << "Ошибка подключения!" << std::endl;
		exit(1);
	}
	struct sockaddr_in local;
	int s_o_l = sizeof(local);
	local.sin_family = AF_INET;
	local.sin_port = htons(1280);
	local.sin_addr.s_addr = 0;
	SOCKET s = socket(AF_INET, SOCK_STREAM, NULL);
	bind(s, (sockaddr*)&local, sizeof(local));
	listen(s, SOMAXCONN);
	cout << "Сервер запущен" << endl;

	SOCKET client_socket;
	sockaddr_in client_addr;
	int client_addr_size = sizeof(client_addr);
	while ((client_socket = accept(s, (sockaddr*)&client_addr, &client_addr_size)))
	{
		numcl++;
		cout << "Пользователей " << numcl << endl;
		time_t rawtime;
		struct tm* timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		printf("Время и дата подключения: %s ", asctime(timeinfo));
		cout << "port:" << ntohs(client_addr.sin_port) << endl;
		char* ip = inet_ntoa(client_addr.sin_addr);
		cout << "Ip подключившегося компьютера:" << ip << endl;

		// вызов нового потока для обслуживания клиента
		DWORD thID;  //thID идентификатор типа DWORD
		CreateThread(NULL, NULL, ThreadFunc, &client_socket, NULL, &thID);
	}
	closesocket(s);
	closesocket(client_socket);
	WSACleanup();
}
#include "iostream"
using namespace std;
struct node
{
	int data;
	node *prev;
	node *next;
};

class dizi
{
	node *root = NULL;
public:

	dizi(int x) {
		root = new node;
		root->data = x;
		root->prev = NULL;
		root->next = NULL;
	}
	void ekle(int x) {

		node *yrd = root;
		while (yrd->next != NULL)
		{
			yrd = yrd->next;
		}//while sonunda listenin son eleman�na eri�mi� olucaz
		yrd->next = new node;
		yrd->next->data = x;
		yrd->next->prev = yrd;
		yrd->next->next = NULL;
	}
	void yazdir() {
		node *yrd = root;
		while (yrd->next != NULL)
		{
			cout << yrd->data << " ";
			yrd = yrd->next;
		}//while sonunda listenin son eleman�n� yazd�ramadan d�ng�den ��km�� olaca��ndan en sondaki eleman� d��arda yazd�r
		cout << yrd->data << " ";
	}
	void sil(int indis) {//verilen indisteki eleman� siler
		node *yrd = root;
		for (int i = 0; i < indis; i++)//silinecek eleman� verir (yrd)
		{
			yrd = yrd->next;
		}
		if (yrd->prev == NULL) {//root silme i�lemi
			root = yrd->next;
			root->prev = NULL;
		}
		else if (yrd->next == NULL) {//sondaki eleman� silme
			yrd->prev->next = NULL;
		}
		else {//aradan bir de�er silme i�lemi
			node *tmp = yrd;
			yrd->prev->next = tmp->next;
			yrd->next->prev = tmp->prev;
		}
	}
};


void main() {
	dizi d(10);
	for (int i = 0; i < 10; i++)
	{
		d.ekle(i + 11);
	}
	d.yazdir();
	cout << endl;
	d.sil(10);
	d.yazdir();
	d.ekle(111);
	cout << endl;
	d.yazdir();


	system("pause");

}
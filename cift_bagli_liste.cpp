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
		}//while sonunda listenin son elemanýna eriþmiþ olucaz
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
		}//while sonunda listenin son elemanýný yazdýramadan döngüden çýkmýþ olacaðýndan en sondaki elemaný dýþarda yazdýr
		cout << yrd->data << " ";
	}
	void sil(int indis) {//verilen indisteki elemaný siler
		node *yrd = root;
		for (int i = 0; i < indis; i++)//silinecek elemaný verir (yrd)
		{
			yrd = yrd->next;
		}
		if (yrd->prev == NULL) {//root silme iþlemi
			root = yrd->next;
			root->prev = NULL;
		}
		else if (yrd->next == NULL) {//sondaki elemaný silme
			yrd->prev->next = NULL;
		}
		else {//aradan bir deðer silme iþlemi
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
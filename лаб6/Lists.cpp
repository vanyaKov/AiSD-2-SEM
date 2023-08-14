#include "Lists.h"
#include <iostream>
using namespace std;

struct ELEM       //элемент таблицы
{
	unsigned int tel_number;
	char* fio;
};
namespace listx
{
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		if (head == NULL)
			//Ñîçäàåì ïåðâûé ýëåìåíò-çàãîëîâîê
			head = new Element(NULL, data, head);
		else
			head = (head->prev = new Element(NULL, data, head));
		return rc;
	}
	//-------------------------------
	Element* Object::search(void* data)
	{
		Element* rc = head;

		while ((rc != NULL) && ((((ELEM*)rc->data)->tel_number) != ((ELEM*)data)->tel_number))
			rc = rc->next;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
		}
		return rc;
	}
	//-------------------------------
	bool Object::deleteByData(void* data)
	{
		return deleteByElement(search(data));
	}
	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), * rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}
	Object create()
	{
		return *(new Object());
	};
	//-------------------------------
	void Object::scan()
	{
		listx::Element* e = this->getFirst();
		while (e != NULL)
		{
			cout << ((ELEM*)e->data)->tel_number << " - " << ((ELEM*)e->data)->fio << " / ";
			e = e->getNext();
		};
	}
}

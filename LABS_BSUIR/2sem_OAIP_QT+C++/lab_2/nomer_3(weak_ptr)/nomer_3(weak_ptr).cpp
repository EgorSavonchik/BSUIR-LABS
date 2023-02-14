#include <iostream>
#include "../../libs/smart_ptr/smart_ptrs.h"
#include <string>


class Human
{
	std::string m_name;
	weak_ptr<Human> m_partner; // обратите внимание, здесь std::weak_ptr

public:

	Human(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Human()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(shared_ptr<Human>& h1, shared_ptr<Human>& h2)
	{
		if (!h1 || !h2)
			return false;

		h1->m_partner = h2;
		h2->m_partner = h1;

		std::cout << h1->m_name << " is now partnered with " << h2->m_name << "\n";

		return true;
	}

	const shared_ptr<Human> getPartner() { return m_partner.lock(); } // используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
	const std::string& getName() const { return m_name; }
};

int main()
{
	auto anton = make_shared<Human>("Anton");
	auto ivan = make_shared<Human>("Ivan");
	
	partnerUp(anton, ivan);
	
	auto partner = ivan->getPartner(); // передаем partner-у содержимое умного указателя, которым владеет ivan
	std::cout << ivan->getName() << "'s partner is: " << partner->getName() << '\n';
	
	return 0;

	std::shared_ptr<int[]> t(new int[10]);

	std::cout << t[2000];

	std::weak_ptr<int> qw;
	std::weak_ptr<int> er;

	qw.owner_before(er);
	//shared_ptr<int> t(new int(5));

	/*shared_ptr<int> t(new int(5)), y(new int(120));
	weak_ptr<int> qw(t), er(y);
	std::cout << t << " " << y << "\n";
	qw.swap(er);
	std::cout << qw.getObj() << " " << er.getObj();
	qw.reset();
	std::cout << qw.expired() << qw.getBlock();*/

}

/*#include <iostream>
#include <memory> // для std::shared_ptr и std::weak_ptr
#include <string>

class Human
{
	std::string m_name;
	std::weak_ptr<Human> m_partner; // обратите внимание, здесь std::weak_ptr

public:

	Human(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Human()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Human>& h1, std::shared_ptr<Human>& h2)
	{
		if (!h1 || !h2)
			return false;

		h1->m_partner = h2;
		h2->m_partner = h1;

		std::cout << h1->m_name << " is now partnered with " << h2->m_name << "\n";

		return true;
	}

	const std::shared_ptr<Human> getPartner() const { return m_partner.lock(); } // используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
	const std::string& getName() const { return m_name; }
};

int main()
{
	auto anton = std::make_shared<Human>("Anton");
	auto ivan = std::make_shared<Human>("Ivan");

	partnerUp(anton, ivan);

	auto partner = ivan->getPartner(); // передаем partner-у содержимое умного указателя, которым владеет ivan
	std::cout << ivan->getName() << "'s partner is: " << partner->getName() << '\n';

	return 0;
}*/
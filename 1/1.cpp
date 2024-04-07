
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100

class Person {
public:
	
	Person(const string& name) {
		this->name = name;

	}

	Person(string _name, int _age)
	{
		name = _name;
		age = _age;
	}
	Person()
	{
		name = " ";
		age = 0;
	}
	string getName() const {return name;}
	string& getName()  { return name; }
	friend class Group;

private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	out << p.getName();
	return out;
}




class Group {
public:
/* 	Group()
	{
		size = 0;
		cap = 0;
		members = new Person[MAX_SIZE];
	} */
\
	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	Group(const Group& other) {
        this->cap = other.cap;
        this->size = other.size;
        this->members = new Person[other.cap];

        for (int i = 0; i < other.size; i++) {
            this->members[i] = other.members[i];
        }
    }
	Group& operator=(const Group& other) {
        if (this != &other) {
            delete[] members;
            this->cap = other.cap;
            this->size = other.size;
            this->members = new Person[other.cap];

            for (int i = 0; i < other.size; i++) {
                this->members[i] = other.members[i];
            }
        }
        return *this;
    }
	void add(Person p) {
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}

	void deletePerson(string name) {
		int i;
		for (i = 0; i < size; i++) {
			if (members[i].name == name)
				break;
		}
		if (i == size) {
			return;
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		members[size - 1].getName() = "";
		size--;
	}
	Group operator+(Group g)
	{
		Group res(this->size + g.size);
		for(int i = 0;i < (this->size);++i)
		{
			res.members[i] = this->members[i];
		}
		for(int i = this->size, j = 0;i < (this->size + g.size);++i, ++j)
		{
			res.members[i] = g.members[j];
		}
		res.size = this->size + g.size;
		res.cap = this->size + g.size;
		return res;
	}
	Group operator+= (Group g)///////////cap
	{
		for(int i = this->size, j = 0;i < (this->size + g.size);++i, ++j)
		{
			this->members[i] = g.members[j];
			this->size++;
		}
		return *this;
	}
	friend ostream& operator<< (ostream& out, const Group &g);

	~Group() {
		delete[] members;
	}
	friend bool isGroupFull(Group g);

private:
	int size;
	int cap;
	Person* members;

};

ostream& operator<< (ostream& out, const Group &g)
{
	for(int i = 0;i < g.size; ++i)
	{
		out << g.members[i] << '\t';	
	}
	return out;
}

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

int main()
{
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2;
	
	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout<<isGroupFull(g1)<<endl;
	
	
	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1<<endl;//should cout every person in it with a \t as the separator
	cout << g2 << endl;
	
	
	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;

	
	/*
	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){
		persons[i].getName()=to_string(rand()%100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for(int i=0;i<10;i++){
		cout<<persons[i].getName()<<' ';
	}*/
	/*
	cout<<*find(persons,persons+10,Erfan);
	*/
	








}


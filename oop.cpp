#include<iostream>
#include<string>

using namespace std;

class Animal{
	private:
		string name;
		string type;

	public:
		Animal(string n, string t){
			name = n;
			type = t;
		}

		void setName(string n){
			name = n;
		}

		void setType(string t){
				type = t;
		}

		void print(){
			cout << "Name: " << name << endl;
			cout << "Type: " << type << endl;
		}

		virtual void sound(string sound) const override{
			cout << sound;
		}
};

class Cat: public Animal{
	public:
		Cat(string n, string t){
			setName(n);
			setType(t);
		}

		void sound() const override{
			Animal::sound("Meow Meow");
		}
};

int main()
{
    Animal animal("Bosco", "Dog");
    animal.print();
    animal.sound("Woof woof");

    Cat cat("Whiskers", "Cat");
    cat.print();
    cat.sound();
}
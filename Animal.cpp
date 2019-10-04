#include <iostream>
#include <string>
#include <vector>

using namespace std;

// part 1 c - observer pattern
class Subject;

class Observer {
	public:
		virtual void Update(string o) = 0;
};

class Subject {
	private:
		vector<Observer*> observers;
	public:
		void Attach(Observer* o) {
			observers.push_back(o);
		}
		void Detach(Observer* o) {
			cout<<"ZooAnnouncer relieved from his duties"<<endl;
		    observers.erase(remove(observers.begin(), observers.end(), o));
		}
		void Notify(string s) {
			for (auto* o : observers) {
	            o->Update(s);
	        }
		}
};

class ZooAnnouncer : public Observer {
	public:
		void Update(string a) {
			cout<<"Hi this is ZooAnnouncer ... "<<a<<endl;
		}
};


// part 1b - strategy pattern
class StrategyPattern {
	public:
		StrategyPattern(){}
		// strategy pattern delegating roaming behaviour
		virtual void roam()=0;
};

class Animal : public StrategyPattern{

	protected:
		string name;
		string condition;

	public:
		Animal(){}
		Animal(string name1){
			name = name1;
		}
		void sleep(){
			condition = "asleep";
		}
		void makeNoise(){
			cout<<name<<" is making animal noise"<<endl;
		}
		virtual void eat() {
			cout<<"running animal class eat"<<endl;
		}
		void wakeUp(){
			condition = "awake";
			cout<<name<<" woke up!"<<endl;
		}
		string getName(){
			return name;
		}
		void setName(string name1){
			name = name1;
		}
		void roam(){
			cout<<"Animal class roam called"<<endl;
		}
		string getCondition(){
			return condition;
		}
};


class Feline: public Animal {

	public:
		Feline(){}
		Feline(string name1){
			name = name1;
		}

		virtual void eat() {
			cout<<"running Feline class eat"<<endl;
		}

		void roam(){
			cout<<name<<" of type Feline is roaming"<<endl;
		}
		virtual void makeNoise(int random){
			if (random == 2) {
				Animal a;
				a.makeNoise();
			} else {
				cout<<name<<" is making Feline noise!"<<endl;
			}
		}
};


class Pachyderm: public Animal {

	public:
		Pachyderm(){}
		Pachyderm(string name1){
			name = name1;
		}

		virtual void eat() {
			cout<<"running Pachyderm class eat"<<endl;
		}

		virtual void roam(){
			cout<<name<<" of type Pachyderm is roaming"<<endl;
		}
};


class Canine: public Animal {

	public:
		Canine(){}
		Canine(string name1){
			name = name1;
		}

		virtual void eat() {
			cout<<"running Canine class eat"<<endl;
		}

		void roam(){
			cout<<name<<" of type Canine is roaming"<<endl;
		}
};

class Cat: public Feline {

	private:
		string type = "Feline";

	public:
		Cat(){}
		Cat(string name1) {
			name = name1;
		}
		void makeNoise(){
			srand (time(NULL));
			int random = rand()%3;
			if (random == 1) {
				cout<<"Meow!"<<endl;
			} else {
				Feline f;
				f.makeNoise(random);
			}
		}
		void eat() {
			cout<<name<<" of type "<<type<<" is eating fish!"<<endl;
		}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}
		string getType(){
			return type;
		}
		void setType(string type1){
			type = type1;
		}

};

class Dog: public Canine {

	private:
		string type = "Canine";
	public:
		Dog(){}
		Dog(string name1){
			name = name1;
		}
		void makeNoise(){
			cout<<"Woof"<<endl;
		}
		void wakeUp(){}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}

		void eat(){
			cout<<name<<" of type "<<type<<" is eating meat!"<<endl;
		}
		string getType(){
			return type;
		}
		void setType(string type1){
			type = type1;
		}

};

class Elephant: public Pachyderm {

	private:
		string type = "Pachyderm";
	public:
		Elephant(){}
		Elephant(string name1){
			name = name1;
		}
		void makeNoise(){
			cout<<"Elephant sound!"<<endl;
		}
		void wakeUp(){}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}
		void eat(){
			cout<<name<<" of type "<<type<<" is eating leaves!"<<endl;
		}
		void setType(string type1){
			type = type1;
		}
		string getType(){
			return type;
		}
};


class Hippo: public Pachyderm {

	private:
		string type = "Pachyderm";
	public:
		Hippo(){}
		Hippo(string name1) {
			name = name1;
		}
		void makeNoise(){
			cout<<"Hippo sound!"<<endl;
		}
		void wakeUp(){}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}
		void eat(){
			cout<<name<<" of type "<<type<<" is eating fish!"<<endl; 
		}
		void setType(string type1){
			type = type1;
		}
		string getType(){
			return type;
		}

};

class Lion: public Feline {

	private:
		string type = "Feline";
	public:
		Lion(){}
		Lion(string name1){
			name = name1;
		}
		void makeNoise() {
			cout<<"Lion sound"<<endl;
		}
		void wakeUp(){}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}
		void eat(){
			cout<<name<< " of type "<<type  <<" is eating deer!"<<endl;
		}
		void setType(string type1){
			type = type1;
		}
		string getType(){
			return type;
		}
};


class Rhino: public Pachyderm {

	private:
		string type = "Pachyderm";
	public:
		Rhino(){}
		Rhino(string name1) {
			name = name1;
		}
		void makeNoise(){
			cout<<"Rhino sound!"<<endl;
		}
		void wakeUp(){}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}
		void eat(){
			cout<<name<<" of type "<<type<<" is eating food!"<<endl; 
		}
		void setType(string type1){
			type = type1;
		}
		string getType(){
			return type;
		}

};

class Tiger: public Feline {

	private:
		string type = "Feline";
	public:
		Tiger(){}
		Tiger(string name1){
			name = name1;
		}
		void makeNoise(){
			cout<<"Tiger Sound!"<<endl;
		}
		void wakeUp(){}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}
		void eat(){
			cout<<name<< " of type "<<type  <<" is eating deer!"<<endl;
		}
		void setType(string type1){
			type = type1;
		}
		string getType(){
			return type;
		}
};

class Wolf: public Canine {

	private:
		string type = "Canine";
	public:
		Wolf(){}
		Wolf(string name1){
			name = name1;
		}
		void makeNoise(){
			cout<<"Wolf sound"<<endl;
		}
		void wakeUp(){}
		void roam() {
			cout<<name<<" of type "<<type<<" is roaming arround"<<endl;
		}
		void eat(){
			cout<<name<<" of type "<<type<<" is eating rabbit!"<<endl;
		}
		string getType(){
			return type;
		}
		void setType(string type1){
			type = type1;
		}

};



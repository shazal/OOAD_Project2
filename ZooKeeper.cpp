#include <iostream>
#include <string>
#include <list>
#include "Animal.cpp"
using namespace std;

class ZooKeeper : public Subject{

	public:
		list <Animal*> zoo;
		void addAnimal(Animal *animal) {
			zoo.push_back(animal);
		}
		void wakeAnimals() {
			list <Animal*> :: iterator it;
			this->Notify("ZooKeeper about to wake animals up!"); 
			for(it = zoo.begin(); it != zoo.end(); ++it) 
				(*it)->wakeUp(); 
		}
		void rollCall() {
			list <Animal*> :: iterator it; 
			this->Notify("ZooKeeper about to rollcall animals!"); 
			cout<<"Taking animals rollcall!"<<endl;
			for(it = zoo.begin(); it != zoo.end(); ++it) 
				cout << (*it)->getName()<< " is now "<<(*it)->getCondition()<<endl;; 
		}
		void feedTheAnimals(){
			this->Notify("ZooKeeper about to feed animals!"); 
			cout<<"feeding animals!"<<endl;
			list <Animal*> :: iterator it; 
			for(it = zoo.begin(); it != zoo.end(); ++it) {
				(*it)->eat();
			}
		}
		void exerciseTheAnimals() {
			this->Notify("ZooKeeper about to make animals excercise!"); 
			cout<<"exercising the animals!"<<endl;
			list <Animal*> :: iterator it; 
			for(it = zoo.begin(); it != zoo.end(); ++it) {
				(*it)->roam();
			}
		}
		void shutDown() {
		this->Notify("ZooKeeper shutting down zoo!"); 
		cout<<"Shutting down the zoo!"<<endl;
		int size = zoo.size();
		for (int i =0; i< size; i++) {
			Animal* temp = zoo.front();
			cout<<(*temp).getName()<<" was set free!"<<endl;
			zoo.pop_front();
		}
	}


};

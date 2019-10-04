#include <iostream>
#include "ZooKeeper.cpp"

using namespace std;


int main() {

	// initialize
	ZooKeeper zooKeeper = ZooKeeper();
	ZooAnnouncer zooAnnouncer = ZooAnnouncer();

	// Attaching observer
	zooKeeper.Attach(&zooAnnouncer);

	// Add animals to the zoo
	Cat chloe = Cat("Chole");
	Feline fe = Feline("fe");
	zooKeeper.addAnimal(&chloe);
	zooKeeper.addAnimal(&fe);
	
	// zooKeeper.addAnimal(Feline("Fune"));
/*
	zooKeeper.addAnimal(Cat("Cole"));
	zooKeeper.addAnimal(Dog("Daz"));
	zooKeeper.addAnimal(Dog("Dug"));
	zooKeeper.addAnimal(Elephant("Elf"));
	zooKeeper.addAnimal(Elephant("Eu"));
	zooKeeper.addAnimal(Hippo("Hommie"));
	zooKeeper.addAnimal(Hippo("Hula"));
	zooKeeper.addAnimal(Lion("lame"));
	zooKeeper.addAnimal(Lion("Lasso"));
	zooKeeper.addAnimal(Rhino("Rami"));
	zooKeeper.addAnimal(Rhino("Rufi"));
	zooKeeper.addAnimal(Tiger("Tika"));
	zooKeeper.addAnimal(Tiger("Terry"));
	zooKeeper.addAnimal(Wolf("Willy"));
	zooKeeper.addAnimal(Wolf("Woz"));
*/

	// Starting zookeeper daily activities
	zooKeeper.wakeAnimals();
	zooKeeper.rollCall();
	zooKeeper.feedTheAnimals();
	zooKeeper.exerciseTheAnimals();

	// Day end
	zooKeeper.Detach(&zooAnnouncer);
	zooKeeper.shutDown();

	// Animal *a;
	// Feline *f;
	// Cat c = Cat("colo");
	// c.eat();
	// f = &c;
	// f->eat();
	// a = &c;
	// a->eat();

}

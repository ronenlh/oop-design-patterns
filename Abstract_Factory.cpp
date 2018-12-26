/*
 * Abstract Factory
 * Object Creational
 *
 * Intent:
 * Provide an interface for creating families of related or 
 * dependent objects without specifying their concrete class.
 *
 * WidgetFactory class declares an interface for creating each
 * basic kind of widget (like scroll bars, windows, and buttons)
 * 
 * There's also an abstract class for each kind of widget, and 
 * concrete subclasses implement widgets for specific look-and-feel
 * standards.
 *
 * WidgetFactory interface has operations that return a new widget
 * object for each abstract widget class. Clients call these, but
 * aren't aware of the concrete classes they're using, thus stay
 * independent.
 *
 * Use Abstract Factory when:
 *   - a system should be independednt of how its products are created.
 *   - a system should be configured with one of multiple families of products
 *   - a family of related product objects is designed to be used together
 *   - provide a class library of products, reveal only their interfaces
 *
 * Participants:
 *   - AbstractFactory: interface for operations to create abstract product objects
 *   - ConcreteFactory: implements the operations to create concrete product objects
 *   - AbstractProduct: interface for a type of product objects
 *   - ConcreteProduct: product object to be created by corresponding concrete fatory
 *   - Client: uses only interfaces declared by AstractFactory and AbstractProduct
 *
 * It isolates concrete classes, and makes exchanging product families easy. Promotes
 * consistency among products, however, it is difficult to support new kinds of products.
 *
 * Factories are singletons. AbstractFactory only declares an interface for creating
 * products, ConcreteProduct subclasses actually create them.
 *
 */

#include "MapSite.h" 

class MazeFactory
{
public:
    	MazeFactory();

	// virtual non-static methods support dynamic dispatch
	// behavior can be overriden in derived classes, and
	// behvaior is preserved even if there is no compile-time
	// information about the actual type of the class
	virtual Maze* MakeMaze() const { return new Maze; }
	virtual Wall* MakeWall() const { return new Wall; }
	virtual Room* MakeRoom(int n) const { return new Room(n); }
	virtual Door* MakeDoor(Room* r1, Room* r2) const
		{ return new Door(r1, r2); }	
};


class MazeGame
{
public:
	MazeGame();
	
	Maze* CreateMaze(MazeFactory &factory);
};

Maze* MazeGame::CreateMaze(MazeFactory &factory) {
	// CreateMaze takes a MazeFactory as a parameter,
	// thus not hard-coding the class name
	
	Maze* aMaze = factory.MakeMaze();
	Room* r1 = factory.MakeRoom(1);
	Room* r2 = factory.MakeRoom(2);
	Door* aDoor = factory.MakeDoor(r1, r2);

	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(North, factory.MakeWall());
	r1->SetSide(East, aDoor);
	r1->SetSide(South, factory.MakeWall());
	r1->SetSide(West, factory.MakeWall());

	r2->SetSide(North, factory.MakeWall());
	r2->SetSide(East, factory.MakeWall());
	r2->SetSide(South, factory.MakeWall());
	r2->SetSide(West, aDoor);

	return aMaze;
}
/* 

class EnchantedMazeFactory : public MazeFactory 
{
public:
	EnchantedMazeFactory();

	virtual Room* MakeRoom(int n) const
		{ return new EnchantedRoom(n, CastSpell()); }
	
	virtual Door* MakeDoor(Room* r1, Room* r2) const
		{ return new DoorNeedingSpell(r1, r2); }

protected:
	Spell* CastSpell() const;
};
*/

int main(int argn, char* argv[])
{
	
	return 0;
}
